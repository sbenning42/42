/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/28 00:57:07 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/19 12:34:04 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	t_uint		i;

	if (!s1 || !s2)
		return (0);
	i = MAX_UINT;
	while (n--)
	{
		++i;
		if (((t_uchar *)s1)[i] != ((t_uchar *)s2)[i])
			return (((t_uchar *)s1)[i] - ((t_uchar *)s2)[i]);
	}
	return (0);
}
