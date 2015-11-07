/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/25 21:21:17 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/15 12:15:38 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	t_uint		i;

	i = MAX_UINT;
	while (++i < n)
	{
		((t_uchar *)dst)[i] = ((t_uchar *)src)[i];
		if (((t_uchar *)src)[i] == (t_uchar)c)
			return ((void *)((t_uchar *)(dst + ++i)));
	}
	return (NULL);
}
