/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_save.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:35:36 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/26 14:35:52 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
