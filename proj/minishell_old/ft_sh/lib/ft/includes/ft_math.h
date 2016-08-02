/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 03:19:33 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/06 20:46:58 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include "libft.h"
# include <limits.h>

# define MATH_PI_DEMI 1.57079632679
# define MATH_PI_QUART 0.78539816339
# define MATH_PI 3.14159265359

# define MATH_RSQRT_PAD_NOSMART 0.1
# define MATH_RSQRT_PAD 0.01
# define MATH_RSQRT_TURNOUT INT_MAX

//float			g_theta[] = {};

typedef enum	s_math_coo_id
{
	Cart_x = 0,
	Cart_y = 1,
	Cart_z = 2,
	Sph_r = 0,
	Sph_phi = 1,
	Sph_teta = 2
}				t_math_coo_id;

typedef struct	s_sph_pt
{
	float		p[3];
}				t_sph_pt;

typedef struct	s_cart_pt
{
	int			p[3];
}				t_cart_pt;

typedef struct	s_mat_sph
{
	t_sph_pt	*mat;
	size_t		size;
}				t_mat_sph;

typedef struct	s_mat_cart
{
	t_cart_pt	*mat;
	size_t		size;
}				t_mat_cart;

typedef struct	s_mat_sph_2d
{
	t_sph_pt	**mat;
	size_t		y;
	size_t		x;
}				t_mat_sph_2d;

typedef struct	s_mat_cart_2d
{
	t_cart_pt	**mat;
	size_t		y;
	size_t		x;
}				t_mat_cart_2d;

/*
void	math_carttosph(float **sphere, int **cart, int y, int x);
float	**math_matdestroy(float ***amat, int i, float **returnval);
float	**math_matnew_sphcoo(int x, int y, int z_ensemble);
*/
float			ft_math_abs(float f);
float			ft_math_rsqrt_nosmart(float f);
float			ft_math_rsqrt_nosmart2(float f);
float			ft_math_rsqrt(float f);
float			ft_math_pow(float f, int pow);
float			ft_math_cos(float angle);
float			ft_math_sin(float angle);
float			ft_math_tan(float angle);
float			ft_math_arccos(float angle);
float			ft_math_arcsin(float angle);
float			ft_math_arctan(float angle, int n);
t_mat_sph		ft_math_newmatsph(int x, int y);
t_mat_cart		ft_math_newmatcart(int x, int y);
t_mat_sph_2d	ft_math_newmatsph_2d(int x, int y);
t_mat_cart_2d	ft_math_newmatcart_2d(int x, int y);

#endif
