/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:25:01 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/31 15:25:27 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float		ft_atof(char *s)
{
	float	res;
	int		dec;
	int		flag;
	int		neg;

	res = 0.0;
	dec = 0;
	flag = 0;
	neg = (*s == '-') ? (s++, 1) : 0;
	while (*s != '\0' && (ft_isdigit(*s) || *s == '.'))
	{
		dec += flag ? 1 : 0;
		if (*s != '.')
			res = res * 10.0 + (*s - '0');
		else
			flag = 1;
		s++;
	}
	while (dec-- > 0)
		res *= 0.1;
	return (neg ? -res : res);
}
