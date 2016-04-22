/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/25 19:21:25 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/22 19:24:29 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*cp;

	cp = dst;
	while (n--)
	{
		*(t_uchar *)dst = *(t_uchar*)src;
		dst = (t_uchar *)dst + 1;
		src = (t_uchar *)src + 1;
	}
	return (cp);
}
