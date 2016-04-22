/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/28 00:57:07 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/22 19:29:47 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	while (n-- && *(t_uchar *)s1 == *(t_uchar *)s2)
	{
		if (n)
		{
			s1 = (t_uchar *)s1 + 1;
			s2 = (t_uchar *)s2 + 1;
		}
	}
	return (*(t_uchar *)s1 - *(t_uchar *)s2);
}
