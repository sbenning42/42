/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mathrsqrt_nosmart2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 12:28:06 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/06 17:22:15 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define UTESTRSQRT_NOSMART2
#include "ft_math.h"

float		ft_math_rsqrt_nosmart2(float f)
{
	float	rsqrt;
	int		i;

	if (f < 0.0)
		return (-1.0);
	else if (f == 0.0)
		return (1.0);
	rsqrt = f / 4.0;
	i = 0;
	while ((!(ft_math_abs(rsqrt * rsqrt - f) <= MATH_RSQRT_PAD) \
			&& i++ < MATH_RSQRT_TURNOUT))
	{
		if ((rsqrt * rsqrt - f) < 0.0)
			rsqrt += (rsqrt / 2.0);
		else if (( rsqrt* rsqrt - f) > 0.0)
			rsqrt -= (rsqrt / 2.0);
	}
	return (rsqrt);
}

#ifdef UTESTRSQRT_NOSMART2
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
	ut = ft_math_rsqrt_nosmart2;
	i = -1;
	while (++i < UT_NBUTEST)
		printf("rsqrt(%f) = [%f]\n", UT(i));
	return (0);
}
#endif /* UTESTRSQRT_NOSMART2 */
