/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/28 03:29:59 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/15 12:25:01 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t		len;
	t_uint		i;

	i = MAX_UINT;
	len = ft_strlen(dst);
	while (n-- && src[++i])
		dst[len++] = src[i];
	dst[len] = '\0';
	return (dst);
}
