/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matharctan.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 12:26:20 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/06 19:36:03 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define UTESTARCTAN
#include "ft_math.h"

float		ft_math_arctan(float angle, int n)
{
	float	arctan;
	int		k;

	k = 0;
	arctan = 0.0;
	while (k <= (n + 1))
	{
		if (k % 2)
			arctan -= ((1.0 / (2.0 * k + 1.0)) * ft_math_pow(angle, 2 * k + 1));
		else
			arctan += ((1.0 / (2.0 * k + 1.0)) * ft_math_pow(angle, 2 * k + 1));
		k++;
	}
	return (arctan);
}

#ifdef UTESTARCTAN
# define UT_NBUTEST 8
# define UT(x) uti[x], ut(0.9, uti[x])
# include <stdio.h>

int main(void)
{
	float	(*ut)(float, int);
	int		uti[UT_NBUTEST];
	int		i;

	uti[0] = 0;
	uti[1] = 1;
	uti[2] = 2;
	uti[3] = 3;
	uti[4] = 4;
	uti[5] = 5;
	uti[6] = 6;
	uti[7] = 7;
	ut = ft_math_arctan;
	i = -1;
	while (++i < UT_NBUTEST)
		printf("arctan(0.9, %d) = [%f]\n", UT(i));
	return (0);
}
#endif /* UTESTARCTAN */
