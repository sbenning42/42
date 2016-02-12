/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 12:59:50 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/12 16:48:34 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		ps_resolve(t_dlist **ah_dla, t_dlist **ah_dlb, size_t size)
{
	t_dlist	*tmp;
	
	if (IS(O_DEBUG, *opt()))
		debug_dl(*ah_dla, size, "A");
	tmp = *ah_dla;
	while (42)
	{
		if (!*ah_dla)
			break ;
		op_px(ah_dla, ah_dlb); //pb
		if (IS(O_DEBUG, *opt()))
		{
			debug_dl(*ah_dla, size, "A");
			debug_dl(*ah_dlb, size, "B");
		}
		//handle_dlb(ah_dlb);
	}
}
