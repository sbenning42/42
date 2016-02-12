/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_multiple.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 15:57:59 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/12 16:48:34 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	op_ss(t_dlist **ah_dla, t_dlist **ah_dlb)
{
	op_sx(ah_dla);
	op_sx(ah_dlb);
}

void	op_rs(t_dlist **ah_dla, t_dlist **ah_dlb)
{
	op_rx(ah_dla);
	op_rx(ah_dlb);
}

void	op_rrs(t_dlist **ah_dla, t_dlist **ah_dlb)
{
	op_rrx(ah_dla);
	op_rrx(ah_dlb);
}

void		op_px(t_dlist **ah_dl_pop, t_dlist **ah_dl_push)
{
	t_dlist	*tmp;

	if (!(*ah_dl_pop))
		return ;
	tmp = *ah_dl_pop;
	*ah_dl_pop = (*ah_dl_pop)->n;
	if (*ah_dl_pop)
		(*ah_dl_pop)->p = NULL;
	tmp->n = NULL;
	tmp->p = NULL;
	ft_dlstaddp(ah_dl_push, tmp);
}
