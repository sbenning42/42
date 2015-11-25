/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:21:47 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/25 11:21:50 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char		*ft_strupper(char *const s)
{
	char	*cp;

	cp = (char *)s;
	while (*cp)
	{
		*cp = ft_toupper(*cp);
		cp++;
	}
	return (s);
}
