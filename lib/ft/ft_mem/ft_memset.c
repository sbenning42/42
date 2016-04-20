/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/25 17:52:54 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/20 13:59:17 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void		*ft_memset(void *b, int c, size_t len)
{
	t_uchar	*b_cp;

	b_cp = (t_uchar *)b;
	b_cp += (len - 1);
	while (len--)
	{
		*(t_uchar *)b_cp = (t_uchar)c;
		if (len)
			b_cp--;
	}
	return ((void *)b);
}
