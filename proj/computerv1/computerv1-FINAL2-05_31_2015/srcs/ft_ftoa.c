/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:25:39 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/31 15:26:04 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_ftoa(float f, char *s, int dec)
{
	long	pow;
	int		i;

	pow = 1;
	i = 0;
	while (pow * 10 <= f)
		pow *= 10;
	while (pow > 0)
	{
		*s++ = (char)(f / pow + '0');
		f -= ((int)(f / pow)) * pow;
		pow /= 10;
	}
	*s++ = '.';
	while (i < dec)
	{
		f *= 10;
		*s++ = (char)(f + '0');
		f -= (int)f;
		i++;
	}
	*s = '\0';
}
