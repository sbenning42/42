/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 00:06:39 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/26 09:43:33 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst || !src)
		return (dst);
	if (dst > src)
		while (len--)
			((t_uchar *)dst)[len] = ((t_uchar *)src)[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
