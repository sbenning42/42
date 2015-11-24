/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 11:10:26 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/24 14:52:16 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list				**buflist(void)
{
	static t_list	*bufs;

	return (&bufs);
}

void				save_buf(void *buf, size_t size)
{
	t_list			*cp;

	if (!size)
		return ;
	cp = ft_lstnew(buf, size);
	if (!cp)
		return ;
	ft_lstadd_back(LIST__(), cp);
}
