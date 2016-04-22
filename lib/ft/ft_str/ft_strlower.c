/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:20:09 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/22 19:34:17 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char		*ft_strlower(char *const s)
{
	char	*cp;

	cp = (char *)s;
	while (*cp)
	{
		*cp = (char)ft_tolower(*cp);
		cp++;
	}
	return (s);
}
