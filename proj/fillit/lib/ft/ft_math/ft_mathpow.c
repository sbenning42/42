/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mathpow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 12:27:14 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/06 19:11:05 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define UTESTPOW
#include "ft_math.h"

float		ft_math_pow(float f, int pow)
{
	float	npow;
	int		i;

	if (pow < 0)
		return (1.0 / ft_math_pow(f, -pow));
	else if (f == 0.0)
		return (0.0);
	else if (pow == 0)
		return (1.0);
	npow = f;
	i = 1;
	while (i++ < pow)
		npow *= f;
	return (npow);
}

#ifdef UTESTPOW
# define UT_NBUTEST 8
# define UT(x, y) utf[x], uti[y], ut(utf[x], uti[y])
# include <stdio.h>

int main(void)
{
	float	(*ut)(float, int);
	float	utf[UT_NBUTEST];
	int		uti[UT_NBUTEST];
	int		i;
	int		j;

	utf[0] = 0.0;
	utf[1] = 1.0;
	utf[2] = 2.0;
	utf[3] = 10.0;
	utf[4] = -10.0;
	utf[5] = -2.0;
	utf[6] = -1.0;
	utf[7] = MATH_PI;
	uti[0] = 0;
	uti[1] = 1;
	uti[2] = 2;
	uti[3] = 10;
	uti[4] = -10;
	uti[5] = -2;
	uti[6] = -1;
	uti[7] = -9;
	ut = ft_math_pow;
	i = -1;
	while (++i < UT_NBUTEST)
	{
		j = -1;
		while (++j < UT_NBUTEST)
			printf("pow(%f, %i) = [%f]\n", UT(i, j));
	}
	return (0);
}
#endif /* UTESTTAN */
