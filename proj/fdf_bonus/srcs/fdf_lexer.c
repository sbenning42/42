/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lexer_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:06:56 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/08 20:03:57 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_lex_tk		lex_eol_tk(char *s)
{
	t_lex_tk		t;

	t.type = Eol;
	t.value = s;
	t.size = 1;
	return (t);
}

static t_lex_tk		lex_constnu_tk(char **s)
{
	t_lex_tk		t;

	t.type = Const_nu;
	t.value = *s;
	(*s)++;
	t.size++;
	while (ft_isdigit(**s))
	{
		(*s)++;
		t.size++;
	}
	return (t);
}

static t_lex_tk		lex_unknow_tk(char *s)
{
	t_lex_tk		t;

	t.type = Unknow;
	t.value = s;
	t.size = 1;
	return (t);
}

static int			lex_add_tk(char *av, char *id, t_list **alst, t_lex_tk *t)
{
	t_list			*el;

	if ((el = ft_lstnew((void *)t, sizeof(t_lex_tk))) == NULL)
	{
		ft_err(av, id, "Memory allocation failed");
		ft_lstdel(alst, NULL);
		return (0);
	}
	ft_lstadd_back(alst, el);
	return (1);
}

t_list				*fdf_lexer(char *av, char *id, char *s)
{
	t_list			*lst;
	t_lex_tk		t;
	char			*cp;

	t.type = None;
	lst = NULL;
	cp = s;
	while (t.type != Eol)
	{
		ft_bzero((void *)&t, sizeof(t_lex_tk));
		if (*s == ' ')
			s++;
		else if (*s == '\0')
			t = lex_eol_tk(s);
		else if (ft_isdigit(*s) || *s == '-')
			t = lex_constnu_tk(&s);
		else
			t = lex_unknow_tk(s - 1);
		if (t.type != None)
		{
			if (!lex_add_tk(av, id, &lst, &t))
				return (NULL);
		}
	}
	return (lst);
}

