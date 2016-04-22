/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 00:06:39 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/22 19:28:06 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst || !src)
		return (dst);
	else if (dst > src)
	{
		dst = (t_uchar *)dst + len;
		src = (t_uchar *)src + len;
		while (len--)
		{
			*(t_uchar *)dst = *(t_uchar *)src;
			dst = (t_uchar *)dst - 1;
			src = (t_uchar *)src - 1;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
