/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/28 00:42:53 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/19 13:39:59 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (!s)
		return (NULL);
	while (n--)
		if (*(t_uchar *)s++ == (t_uchar)c)
			return ((void *)(s - 1));
	return (NULL);
}
