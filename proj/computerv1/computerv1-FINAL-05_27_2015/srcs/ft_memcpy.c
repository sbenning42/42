/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/25 19:21:25 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/15 12:15:06 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	t_uint		i;

	i = MAX_UINT;
	while (++i < n)
		((t_uchar *)dst)[i] = ((t_uchar*)src)[i];
	return (dst);
}
