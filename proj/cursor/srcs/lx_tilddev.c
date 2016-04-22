/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_tilddev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 12:40:06 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/23 00:57:32 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int					lx_tilddevlexem(t_dynstr *value)
{
	char			*home;
	char			*cp;

	home = ft_getenv("HOME");
	if (!(cp = dyn_strsub(value, 1, value->used - 1)))
		return (-1);
	ft_bzero((void *)value->str, value->used);
	value->used = 0;
	if (dyn_strpushstr(value, home, ft_strlen(home)) < 0)
	{
		free(cp);
		return (-1);
	}
	if (dyn_strpushstr(value, cp, ft_strlen(cp)) < 0)
	{
		free(cp);
		return (-1);
	}
	free(cp);
	return (0);
}

int					lx_tilddev(t_lxem *list)
{
	while (list)
	{
		if (!list->plv && !ft_strncmp("~", list->value.str, 1))
		{
			if (lx_tilddevlexem(&list->value) < 0)
				return (-1);
		}
		list = list->next;
	}
	return (0);
}
