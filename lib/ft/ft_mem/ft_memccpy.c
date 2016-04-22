/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/25 21:21:17 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/22 19:25:50 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		*(t_uchar *)dst = *(t_uchar *)src;
		dst = (t_uchar *)dst + 1;
		if (*(t_uchar *)src == (t_uchar)c)
			return (dst);
		src = (t_uchar *)src + 1;
	}
	return (NULL);
}
