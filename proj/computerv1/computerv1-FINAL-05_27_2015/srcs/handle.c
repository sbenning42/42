/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 11:00:30 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/27 14:41:07 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.h"
#include <stdio.h>

void				hdl_handle_degree(t_tok *tab, unsigned int size, \
					float *degree)
{
	int				i;
	float			coef;
	int				flag;

	i = -1;
	flag = 0;
	coef = 1.0;
	while ((unsigned int)++i < size)
	{
		if (tab[i].type == TOK_COEF)
			coef = tab[i].val;
		else if (tab[i].type == TOK_EXP && *degree < tab[i].val)
		{
			if (coef != 0.0)
				*degree = tab[i].val;
			coef = 1.0;
		}
		else if (flag && tab[i].type != TOK_EXP && *degree < 1)
		{
			if (coef != 0.0)
				*degree = 1;
			coef = 1.0;
		}
		flag = tab[i].type == TOK_X ? 1 : 0;
	}
	//DEBUG
	printf("DEGREE = %f\n", *degree);
	//
}

void				hdl_handle_sig(t_tok *tab, unsigned int size)
{
	unsigned int	i;
	char			flag;

	i = 0;
	flag = 0;
	while (i < size)
	{
		if (tab[i].type == TOK_SIG && tab[i].val == 1.0)
			flag = 1;
		else if (tab[i].type == TOK_COEF && flag)
		{
			flag = 0;
			tab[i].val *= -1;
		}
		i++;
	}
}

void				hdl_handle_put(t_tok *tab, unsigned int size, \
					int eq, float degree)
{
	unsigned int	i;
	float			coef;
	float			tmp;

	i = 0;
	tmp = degree;
	ft_putstr("\nReduced form: ");
	while (degree >= 0)
	{
		while (i < size)
		{
			if (tab[i].type == TOK_COEF)
				coef = tab[i].val;
			else if (tab[i].type == TOK_EXP && tab[i].val == degree)
			{
				red_put_polynom(coef, degree, eq - i, tmp == degree ? 0 : 1);
				break ;
			}
			i++;
		}
		degree--;
		i = 0;
	}
	ft_putendl("= 0");
}

static float		hdl_handle_exp(t_tok *tab, unsigned int size, \
					float degree, int eq)
{
	int				i;
	float			coef;
	float			tcoef;

	i = 0;
	tcoef = 0.0;
	while (i < (int)size)
	{
		if (tab[i].type == TOK_COEF)
			coef = tab[i].val;
		else if (tab[i].type == TOK_EXP && tab[i].val == degree)
			tcoef += (i < eq) ? coef : (coef * -1);
		i++;
	}
	return (tcoef);
}

void				hdl_handle_coef(t_tok *tab, unsigned int size, \
					float *degree, int eq)
{
	unsigned int	i;
	float			*coef;
	float			tmp;

	tmp = *degree;
	while (i = 0, *degree >= 0.0)
	{
		while (i < size)
		{
			if (tab[i].type == TOK_COEF)
				coef = &(tab[i].val);
			else if (tab[i].type == TOK_EXP && tab[i].val == *degree)
			{
				++i;
				*coef += hdl_handle_exp(tab + i, size - i, *degree, eq - i);
				if (tmp && *coef == 0.0 && *degree == tmp)
					tmp--;
				break ;
			}
			i++;
		}
		(*degree)--;
	}
	*degree = tmp;
}
