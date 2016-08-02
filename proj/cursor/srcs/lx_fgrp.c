/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_fgrp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 09:04:03 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/25 11:37:06 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

static int	static_lx_merge(t_lxem *list, t_lxtype type)
{
	t_lxem	*tmp;
	char	*str;
	size_t	len;

	str = list->next->value.str;
	len = ft_strlen(str);
	if (dyn_strpushstr(&list->value, str, len) < 0)
		return (-1);
	list->len += len;
	list->type = type;
	tmp = list->next;
	list->next = tmp->next;
	if (tmp->next)
		tmp->next->previous = list;
	dyn_strdel(&tmp->value);
	ft_memdel((void **)&tmp);
	return (0);
}

int		lx_grp_bg(t_lxem *list)
{
	if (list->next && !ft_strcmp(list->next->value.str, LX_GROUP_BG))
	{
		if (static_lx_merge(list, TY_And_sep) < 0)
			return (-1);
	}
	else
		list->type = TY_Word;
	return (0);
}

int		lx_grp_pipe(t_lxem *list)
{
	if (list->next && !ft_strcmp(list->next->value.str, LX_GROUP_PIPE))
	{
		if (static_lx_merge(list, TY_Or_sep) < 0)
			return (-1);
	}
	else
		list->type = TY_Pipe;
	return (0);
}

int		lx_grp_to(t_lxem *list)
{
	if (list->next && !ft_strcmp(list->next->value.str, LX_GROUP_TO))
	{
		if (static_lx_merge(list, TY_Stdout_append_redir) < 0)
			return (-1);
	}
	else
		list->type = TY_Stdout_redir;
	return (0);
}

int		lx_grp_from(t_lxem *list)
{
	list->type = TY_Stdin_redir;
	return (0);
}

int		lx_grp_sep(t_lxem *list)
{
	list->type = TY_Strict_sep;
	return (0);
}
