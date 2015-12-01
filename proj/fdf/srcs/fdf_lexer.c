/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:16:57 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/02 00:08:13 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		fdf_synerror(t_list *lst)
{
	while (lst)
	{
		if (((t_lex_tk *)lst->content)->type != Const_nu)
		{
			ft_printf("fdf: {red}Syntax error: %.*s{eoc} :: ", \
					((t_lex_tk *)lst->content)->size, \
					((t_lex_tk *)lst->content)->value);
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

static int		fdf_handle_lexed(t_list **lst, t_list *lex_lst, \
				t_fdf_point point)
{
	t_list		*elem;
	char		*s;

	s = ((t_lex_tk *)lex_lst->content)->value;
	point.z = ft_atoi(s);
	if (!(elem = ft_lstnew(&point, sizeof(t_fdf_point))))
	{
		ft_lstdel(lst, NULL);
		ft_printf("fdf: {red}Memorry allocation error{eoc}\n");
		return (0);
	}
	ft_lstadd_back(lst, elem);
	return (1);
}

int				fdf_lexing(t_list **lst, char *s, int y, t_lex_rule rule)
{
	t_fdf_point	point;
	t_list		*lex_lst;
	t_list		*tmp;
	int			x;

	lex_lst = ft_lexer(rule, NULL, 0, s);
	if (fdf_synerror(lex_lst))
		return (0);
	point.y = y;
	x = 0;
	tmp = lex_lst;
	while (lex_lst)
	{
		point.x = x++;
		if (!fdf_handle_lexed(lst, lex_lst, point))
		{
			ft_lstdel(&tmp, NULL);
			free(s);
			return (0);
		}
		lex_lst = lex_lst->next;
	}
	ft_lstdel(&tmp, NULL);
	free(s);
	return (1);
}
