/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 10:33:42 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/27 10:33:57 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.h"

float		mt_fsqrt(float a)
{
	float	root;
	int		i;

	i = 2048;
	if (a < 0.0)
		return (-1.0);
	else if (a == 0.0)
		return (0.0);
	root = (float)((int)((a > (int)a) ? a : a - 1.0));
	while (--i > 0 && (((root * root) - a) > 0.000001))
		root = (root + (a / root)) / 2;
	return (root);
}
