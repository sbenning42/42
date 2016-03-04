/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_mat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 03:18:57 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/06 11:55:15 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

float				math_abs(float f)
{
	return ((f < 0 ? -f : f));
}

float				math_pow(float f, int i)
{
	while (--i > 0)
		f *= f;
	return ((i < 0 ? 1 : f));
}

float				math_rsqrt(float f)
{
	float			rsqrt;
	float			max;

	rsqrt = 0.0;
	max = f / 2.0;
	if (!f)
		return (0.0);
	while ((!(math_abs(rsqrt * rsqrt - f) < 0.1) && (rsqrt < max)))
		rsqrt += 0.1;
	return (rsqrt);
}

float				math_arctan_pos(float f, float *c)
{
	float			arctan;
	int				i;

	i = -1;
	arctan = 0.0;
	while (++i < 5)
	{
		if (f)
			arctan += (MATH_PI_DEMI - c[i] * math_pow(1 / f, 2 * (i + 1) - 1));
	}
	return (arctan);
}

float				math_arctan_neg(float f, float *c)
{
	float			arctan;
	int				i;

	i = -1;
	arctan = 0.0;
	while (++i < 5)
	{
		if (f)
			arctan += (-MATH_PI_DEMI - c[i] * math_pow(1 / f, 2 * (i + 1) - 1));
	}
	return (arctan);
}

float				math_arctan(float f)
{
	float			arctan;
	float			c[5];
	int				i;

	c[0] = 0.999866;
	c[1] = -0.3302995;
	c[2] = 0.180141;
	c[3] = -0.085133;
	c[4] = 0.0208351;
	if (f > 1.0)
		return(math_arctan_pos(f, c));
	else if (f < -1.0)
		return (math_arctan_neg(f, c));
	i = -1;
	arctan = 0.0;
	while (++i < 5)
		arctan += (c[i] * math_pow(f, 2 * (i + 1) - 1));
	return (arctan);
}

float				*math_carthtosph(float *sphere, int y, int x, int z)
{
	sphere[Coo_r] = math_rsqrt(x * x + y * y + z * z);
	sphere[Coo_phi] = math_arctan((float)y / (float)x);
	sphere[Coo_teta] = math_arctan(math_rsqrt(x * x + y * y) / z);
	return (sphere);
}

void				math_carttosph(float **sphere, int **cart, int y, int x)
{
	int				i;
	int				j;
	int				index;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			index = i * x + j;
			sphere[index][Coo_r] = math_rsqrt(i * i + j * j + cart[i][j] * cart[i][j]);
			if (j != 0)
				sphere[index][Coo_phi] = math_arctan((float)i / (float)j);
			if (cart[i][j] != 0)
				sphere[index][Coo_teta] = math_arctan(math_rsqrt(i * i + j * j) / (float)cart[i][j]);
			j++;
		}
		i++;
	}
}

float				**math_matdestroy(float ***amat, int i, float **returnval)
{
	int				j;

	j = 0;
	while (j < i && (*amat)[j])
		free((*amat)[j++]);
	free(*amat);
	*amat = NULL;
	return (returnval);
}

float				**math_matnew_sphcoo(int x, int y, int z_ensemble)
{
	float			**mat;
	int				i;

	mat = (float **)ft_memalloc(sizeof(float *) * ((x * y) + 1));
	if (mat == NULL)
		return (NULL);
	mat[x * y] = NULL;
	i = 0;
	while (i < (x * y))
	{
		mat[i] = ft_memalloc(sizeof(float) * 3);
		if (mat[i] == NULL)
			return (math_matdestroy(&mat, i, NULL));
		math_carthtosph(mat[i], i / x, i % x, 1);
		i++;
	}
	return (mat);
}
