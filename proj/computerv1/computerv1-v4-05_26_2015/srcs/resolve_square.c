/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 18:26:11 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/27 11:26:43 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.h"

void				res_positive_delta(t_dis *delta)
{
	float			x1;
	float			x2;
	float			root;
	char			val[32];

	root = mt_fsqrt(delta->dis);
	x1 = (-1 * delta->coef[B_COEF] - root) / (2 * delta->coef[A_COEF]);
	x2 = (-1 * delta->coef[B_COEF] + root) / (2 * delta->coef[A_COEF]);
	ft_putendl(POS_DELTA);
	ft_putstr("X1 = ");
	if (x1 < 0)
		ft_putchar('-');
	ft_ftoa(ABS(x1), val, 6);
	ft_putendl(val);
	ft_putstr("X2 = ");
	if (x2 < 0)
		ft_putchar('-');
	ft_ftoa(ABS(x2), val, 6);
	ft_putendl(val);
}

void				res_null_delta(t_dis *delta)
{
	float			x1;
	float			root;
	char			val[32];

	root = mt_fsqrt(delta->dis);
	x1 = (-1 * delta->coef[B_COEF]) / 2 * delta->coef[A_COEF];
	ft_putendl(NUL_DELTA);
	if (x1 < 0)
		ft_putchar('-');
	ft_ftoa(ABS(x1), val, 6);
	ft_putstr("X = ");
	ft_putendl(val);
}

void				res_negative_delta(t_dis *delta)
{
	float			x1;
	float			x2;
	float			root;
	char			val[32];

	root = mt_fsqrt(delta->dis);
	ft_putendl(NEG_DELTA);
	x1 = (-1 * delta->coef[B_COEF]) / (2 * delta->coef[A_COEF]);
	x2 = (mt_fsqrt(ABS(delta->dis))) / (2 * delta->coef[A_COEF]);
	ft_putstr("X1 = ");
	if (x1 < 0)
		ft_putchar('-');
	ft_ftoa(ABS(x1), val, 6);
	ft_putstr(val);
	ft_putstr(" +i * ");
	ft_ftoa(ABS(x2), val, 6);
	ft_putendl(val);
	if (x1 < 0)
		ft_putchar('-');
	ft_ftoa(ABS(x1), val, 6);
	ft_putstr("X2 = ");
	ft_putstr(val);
	ft_putstr(" -i * ");
	ft_ftoa(ABS(x2), val, 6);
	ft_putendl(val);
}
