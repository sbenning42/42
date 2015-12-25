/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mathrsqrt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 17:20:07 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/06 18:45:11 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define UTESTRSQRT
#include "ft_math.h"

float	ft_math_rsqrt(float f)
{
	float	root;
	int		i;

	i = 4096;
	if (f < 0.0)
		return (-1.0);
	else if (f == 0.0)
		return (0.0);
	else if (f == 1.0)
		return (1.0);
	root = (float)((int)((f > (int)f) ? f : f - 1.0));
	while (ft_math_abs(root * root - f) > 0.000001 && (i--))
		root = (root + (f / root)) / 2;
	return (root);
}

#ifdef UTESTRSQRT
# define UT_NBUTEST 8
# define UT(x) utf[x], ut(utf[x])
# include <stdio.h>

int main(void)
{
	float	(*ut)(float);
	float	utf[UT_NBUTEST];
	int		i;

	utf[0] = 0.0;
	utf[1] = 25.0;
	utf[2] = 2.0;
	utf[3] = MATH_PI;
	utf[4] = 1.0;
	utf[5] = -25.0;
	utf[6] = -1.0;
	utf[7] = 1000000.5;
	ut = ft_math_rsqrt;
	i = -1;
	while (++i < UT_NBUTEST)
		printf("rsqrt(%f) = [%f]\n", UT(i));
	return (0);
}
#endif /* UTESTRSQRT_NOSMART2 */
