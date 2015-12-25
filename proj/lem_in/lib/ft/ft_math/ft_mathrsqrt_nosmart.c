/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mathrsqrt_nosmart.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 12:57:11 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/06 14:30:59 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define UTESTRSQRT_NOSMART
#include "ft_math.h"

float		ft_math_rsqrt_nosmart(float f)
{
	float	rsqrt;
	int		i;

	if (f < 0.0)
		return (-1.0);
	else if (f == 0.0)
		return (1.0);
	rsqrt = 0.0;
	i = 0;
	while ((!(ft_math_abs(rsqrt * rsqrt - f) <= MATH_RSQRT_PAD_NOSMART) \
			&& i++ < MATH_RSQRT_TURNOUT))
		rsqrt += MATH_RSQRT_PAD_NOSMART;
	return (rsqrt);
}

#ifdef UTESTRSQRT_NOSMART
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
	ut = ft_math_rsqrt_nosmart;
	i = -1;
	while (++i < UT_NBUTEST)
		printf("rsqrt_nosmart(%f) = [%f]\n", UT(i));
	return (0);
}
#endif /* UTESTRSQRT_NOSMART */
