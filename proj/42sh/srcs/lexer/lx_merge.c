/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_merge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 12:19:58 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 12:21:09 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int			static_lx_merge(t_lxem *list, t_lxtype type)
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
