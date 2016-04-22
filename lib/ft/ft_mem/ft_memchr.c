/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/28 00:42:53 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/22 19:28:53 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (!s)
		return (NULL);
	while (n--)
	{
		if (*(t_uchar *)s == (t_uchar)c)
			return ((void *)(s));
		s = (t_uchar *)s + 1;
	}
	return (NULL);
}
