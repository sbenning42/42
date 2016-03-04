/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mathabs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 12:29:17 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/06 13:53:49 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define UTESTABS
#include "ft_math.h"

float		ft_math_abs(float f)
{
	return ((f < 0.0 ? -f : f));
}

#ifdef UTESTABS
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
	ut = ft_math_abs;
	i = -1;
	while (++i < UT_NBUTEST)
		printf("abs(%f) = [%f]\n", UT(i));
	return (0);
}
#endif /* UTESTABS */
