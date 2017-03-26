/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/28 02:23:48 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/19 14:07:09 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strcpy(char *dst, const char *src)
{
	t_uint		i;

	if (!dst || !src)
		return (NULL);
	i = MAX_UINT;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
