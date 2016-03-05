/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/28 01:42:10 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/15 12:23:13 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	return (ft_strcpy(str, s1));
}
