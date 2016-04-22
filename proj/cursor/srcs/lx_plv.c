/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_plv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:55:13 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/15 14:29:25 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int			lx_majplv(char c, t_lxplv *plv)
{
	char	*f;

	if (c && (f = ft_strchr(plv->protec_cset, c)))
	{
		if (ISBIT(plv->bitset, g_lxplvbit[f - plv->protec_cset]))
			plv->bitset &= ~g_lxplvbit[f - plv->protec_cset];
		else
			plv->bitset |= g_lxplvbit[f - plv->protec_cset];
		*plv = g_lxplv[plv->bitset];
		g_plvskip += 1;
		return (1);
	}
	return (0);
}
