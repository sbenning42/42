/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/28 02:48:24 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/15 12:24:44 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t		len;

	len = ft_strlen(dst);
	return (ft_strcpy(&dst[len], src) - len);
}
