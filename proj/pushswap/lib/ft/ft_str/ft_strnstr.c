/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 01:09:56 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/16 21:32:02 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		len;
	t_uint		i;

	i = MAX_UINT;
	if (!(len = ft_strlen(s2)))
		return ((char *)s1);
	while (len <= (n - ++i) && s1[i])
		if (!ft_strncmp(&s1[i], s2, len))
			return ((char *)&s1[i]);
	return (NULL);
}
