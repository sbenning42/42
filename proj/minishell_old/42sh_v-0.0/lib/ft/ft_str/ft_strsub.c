/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:50:04 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/19 16:28:27 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	char		*dst;
	t_uint		i;

	i = MAX_UINT;
	if (!s1)
		return (NULL);
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++i < len)
		dst[i] = s1[start + i];
	dst[len] = '\0';
	return (dst);
}
