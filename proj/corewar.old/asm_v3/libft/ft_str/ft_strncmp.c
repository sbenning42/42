/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 01:19:26 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/22 13:56:50 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		len_s1;
	size_t		len_s2;

	if (n > (len_s1 = ft_strlen(s1)))
		n = len_s1 + 1;
	if (n > (len_s2 = ft_strlen(s2)))
		n = len_s2 + 1;
	return (ft_memcmp((void *)s1, (void *)s2, n));
}
