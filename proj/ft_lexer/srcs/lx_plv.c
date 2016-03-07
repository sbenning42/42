/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_plv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 22:29:58 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/07 14:47:09 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

static void	static_lx_plvmaj(t_lxplv *plv, size_t i)
{
	if (ISBIT(plv->bitset, g_wsplvbit[i]))
		plv->bitset &= ~g_wsplvbit[i];
	else
		plv->bitset |= g_wsplvbit[i];
	plv->ws_cset = g_wsplv[plv->bitset].ws_cset;
	plv->protec_cset = g_wsplv[plv->bitset].protec_cset;
}

size_t		lx_plvmaj(char c, t_lxplv *plv)
{
	char	*f;

	if (ISBIT(plv->bitset, LX_PLVESCAPE))
		static_lx_plvmaj(plv, 0);
	if (!c || !(f = ft_strchr(plv->protec_cset, c)))
		return (0);
	static_lx_plvmaj(plv, f - plv->protec_cset);
	g_skip += 1;
	return (1);
}
