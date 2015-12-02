/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/28 02:30:30 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/12 03:47:32 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	t_uint		i;

	i = MAX_UINT;
	while (++i < n && src[i])
		dst[i] = src[i];
	ft_bzero((void *)&dst[i], n - i);
	return (dst);
}
