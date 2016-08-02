/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mathtan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 12:21:49 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/06 19:57:17 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define UTESTTAN
#include "ft_math.h"

float		ft_math_tan(float angle)
{
	float	theta[6];
	float	precision;
	float	swp;
	float	x;
	float	y;
	int		i;

	theta[0] = 0.78539816339744830962;
	theta[1] = 0.099668652491162027378;
	theta[2] = 0.0099996666866652382063;
	theta[3] = 0.00099999966666686666652;
	theta[4] = 0.000099999999666666668667;
	theta[5] = 0.0000099999999996666666667;
	precision = ft_math_pow(10, -9);
	i = 0;
	x = 1;
	y = 0;
	while (angle > precision)
	{
		while (angle < theta[i])
			i++;
		angle -= theta[i];
		swp = x - ft_math_pow(10, -i) * y;
		y += ft_math_pow(10, -i) * x;
		x = swp;
	}
	return (y / x);
}

#ifdef UTESTTAN
# define UT_NBUTEST 8
# define UT(x) utf[x], ut(utf[x])
# include <stdio.h>

int main(void)
{
	float	(*ut)(float);
	float	utf[UT_NBUTEST];
	int		i;

	utf[0] = 0.0;
	utf[1] = 1.0;
	utf[2] = 2.0;
	utf[3] = 3.0;
	utf[4] = 4.0;
	utf[5] = 5.0;
	utf[6] = 6.0;
	utf[7] = 7.0;
	ut = ft_math_tan;
	i = -1;
	while (++i < UT_NBUTEST)
		printf("tan(%f) = [%f]\n", UT(i));
	return (0);
}
#endif /* UTESTTAN */
