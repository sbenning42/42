/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discriminent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 18:52:28 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/26 18:54:45 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.h"

static void			dis_initflag(int flag[3])
{
	flag[A_COEF] = 0;
	flag[B_COEF] = 0;
	flag[C_COEF] = 0;
}

void				dis_initdis(t_dis *delta)
{
	delta->coef[A_COEF] = 0.0;
	delta->coef[B_COEF] = 0.0;
	delta->coef[C_COEF] = 0.0;
}

void				dis_getdis(t_dtab *dtab, t_dis *delta)
{
	unsigned int	i;
	int				flag[3];
	float			coef;
	t_tok			*tab;

	i = 0;
	dis_initdis(delta);
	dis_initflag(flag);
	tab = (t_tok *)dtab->data;
	while (i < dtab->size)
	{
		if (tab[i].type == TOK_COEF)
			coef = tab[i].val;
		else if (tab[i].type == TOK_EXP && tab[i].val < 3)
		{
			if (!flag[(int)tab[i].val])
			{
				flag[(int)tab[i].val] = 1;
				delta->coef[(int)tab[i].val] = coef;
			}
		}
		i++;
	}
	delta->dis = (delta->coef[B_COEF] * delta->coef[B_COEF] - 4 * \
			delta->coef[A_COEF] * delta->coef[C_COEF]);
}
