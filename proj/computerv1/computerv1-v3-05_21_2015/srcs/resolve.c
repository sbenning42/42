/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 17:16:57 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/26 18:27:18 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.h"

void				res_square(t_dis *delta)
{
	if (delta->dis > 0)
		res_positive_delta(delta);
	else if (delta->dis == 0.0)
		res_null_delta(delta);
	else
		res_negative_delta(delta);
}

void				res_simple(t_dis *delta)
{
	char			val[32];
	float			res;

	ft_putendl("The solution is:");
	res = (delta->coef[C_COEF] * -1) / delta->coef[B_COEF];
	ft_ftoa(ABS(res), val, 6);
	if (res < 0)
		ft_putchar('-');
	ft_putendl(val);
}

void				res_all(void)
{
	ft_putendl("All member of Real are solution of the equation.");
}

void				res_none(void)
{
	ft_putendl("There is no solution.");
}

void				res_resolve(t_dtab *dtab)
{
	t_dis			delta;

	dis_getdis(dtab, &delta);
	if (delta.coef[A_COEF])
		res_square(&delta);
	else if (delta.coef[B_COEF])
		res_simple(&delta);
	else if (delta.coef[C_COEF])
		res_none();
	else
		res_all();
}
