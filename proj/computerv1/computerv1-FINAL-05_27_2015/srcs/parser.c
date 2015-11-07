/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 10:53:19 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/27 14:41:08 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.h"

static int			red_put_degree(float degree)
{
	ft_putstr("Polynomial degree: ");
	ft_putnbr(degree);
	ft_putchar('\n');
	if (degree > 2.0)
	{
		ft_putstr(MSG2);
		return (END);
	}
	return (CONTINUE);
}

void				red_put_polynom(float coef, float degree, int ieq, int flag)
{
	char			val[32];

	ft_bzero(val, sizeof(char) * 32);
	coef *= ieq > 0 ? 1 : -1;
	if (flag)
		coef >= 0 ? ft_putstr("+ ") : ft_putstr ("- ");
	else if (coef < 0)
		ft_putstr ("-");
	ft_ftoa(ABS(coef), val, 2);
	ft_putstr(val);
	ft_putstr(" * X^");
	ft_putnbr(degree);
	ft_putchar(' ');
}

static int			red_tokchr(t_tok *tab, unsigned int size, t_ttyp type)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i].type == type)
			return ((int)i);
		i++;
	}
	return (ERR_PAR);
}

int					par_parser(t_dtab *dtab)
{
	t_tok			*tab;
	float			degree;
	int				ret;

	degree = 0.0;
	tab = (t_tok *)dtab->data;
	ret = red_tokchr(tab, dtab->size, TOK_EQ);
	if (ret == ERR_PAR)
		return (ERR_PAR);
	hdl_handle_sig(tab, dtab->size);
	hdl_handle_degree(tab, dtab->size, &degree);
	hdl_handle_coef(tab, dtab->size, &degree, ret);
	hdl_handle_put(tab, dtab->size, ret, degree);
	ret = red_put_degree(degree);
	if (ret == END)
		return (END);
	return (CONTINUE);
}
