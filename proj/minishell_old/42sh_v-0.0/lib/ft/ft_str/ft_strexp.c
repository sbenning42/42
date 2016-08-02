/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strexp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 04:33:17 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/25 11:20:31 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strexp(char *s, size_t size)
{
	char		*s_tmp;

	if (!s)
	{
		if (!(s_tmp = (char *)malloc(sizeof(char) * size + 1)))
			return (NULL);
		ft_bzero(s_tmp, size);
	}
	else
	{
		if (size < ft_strlen(s))
			return (NULL);
		if (!(s_tmp = (char *)malloc(sizeof(char) * size + 1)))
			return (NULL);
		s_tmp = ft_strcpy(s_tmp, s);
		free(s);
		s = NULL;
		return (s_tmp);
	}
	free(s);
	return (s_tmp);
}
