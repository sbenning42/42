/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 00:06:39 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/20 19:23:13 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst || !src)
		return (dst);
	else if (dst > src)
	{
		dst += len;
		src += len;
		while (len--)
			*(t_uchar *)dst-- = *(t_uchar *)src--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
