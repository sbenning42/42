/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 03:21:09 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/08 04:25:01 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		fdf_synerror(char *av, char *id, t_list **alst)
{
	t_list		*cp;
	t_lex_tk	*t;
	char		*synmsg[64];

	cp = *alst;
	while (cp)
	{
		t = (t_lex_tk *)cp->content;
		if (t->type != Const_nu && t->type != Eol)
		{
			ft_sprintf(synmsg, "near token '{red}%*s{eoc}'", t->size, t->value);
			ft_fprintf(2, ERRFMT, av, "Syntax error", synmsg);
			ft_lstdel(alst, NULL);
			return (1);
		}
	}
	return (0);
}

t_list				*fdf_lexer(char *av, char *id, char *s)
{
	t_list			*lst;
	t_list			*el;
	t_lex_tk		t;

	t.type = None;
	while (t_type != Eol)
	{
		ft_bzero((void *)&t, sizeof(t_lex_tk));
		if (*s == ' ')
			s++;
		else if (*s == '\0')
		{
			t.type = Eol;
			t.value = s;
			t.size = 1;
		}
		else if (ft_isdigit(*s))
		{
			t.type = Const_nu;
			t.value = s;
			while (ft_isdigit(*s++))
				t.size++;
		}
		else
		{
			t.type = Unknow;
			t.value = s++;
			t.size = 1;
		}
		if (t.type != None)
		{
			if ((el = ft_lstnew((void *)&t, sizeof(t_lex_tk))) == NULL)
			{
				ft_err(av, id, "Memory allocation failed");
				ft_lstdel(&lst, NULL);
				return (NULL);
			}
			ft_lstadd_back(&lst, el);
		}
	}
}

int				fdf_parse(t_env *env, int fd)
{
	t_list		*lst;
	t_list		*el;
	char		*line;
	int			ret;

	lst = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if ((el = fdf_lexer(env->av, env->id, line)) == NULL)
		{
			ret = -1;
			break ;
		}
		ft_lstadd_back(&lst, el);
	}
	if (ret < 0 || errno)
	{
		ft_err(env->av, env->id, "Can't read (gnl)");
		ft_lstdel(&lst, NULL);
	}
	if (fdf_synerror(env->av, env->id, &lst))
		return ;
	fdf_map_constructor(env, &lst); //todo + set x/y/z_(min-max) etc etc
}

