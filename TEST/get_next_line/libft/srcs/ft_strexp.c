/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strexp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 04:33:17 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/26 10:22:14 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strexp(char *s, size_t size)
{
	char		*new;

	if (!s)
	{
		if (!(s = ft_strnew(size)))
			return (NULL);
		return (s);
	}
	if (!(new = ft_strnew(size)))
		return (NULL);
	ft_strncpy(new, s, size);
	free(s);
	s = NULL;
	return (new);
}
