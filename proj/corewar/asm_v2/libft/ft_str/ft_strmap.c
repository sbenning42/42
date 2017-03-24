/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:04:22 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/15 13:31:47 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	t_uint		i;
	size_t		len;
	char		*dst;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (!(dst = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = MAX_UINT;
	while (s[++i])
		dst[i] = f(s[i]);
	dst[len] = '\0';
	return (dst);
}
