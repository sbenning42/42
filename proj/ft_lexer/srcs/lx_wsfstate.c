/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_wsfstate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:01:49 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/07 15:00:14 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_lxstate		lx_wsstword(char c, t_lxplv plv, t_lxem **token)
{
	if (ft_strchr(plv.protec_cset, c))
		return (ST_Skip);
	if (!*token)
	{
		if (!(*token = lx_newtoken(TY_Word, plv.bitset)))
			return (ST_Mfail);
		if (dyn_strpushstr(&(*token)->value, &c, 1) < 0)
		{
			lx_del(token);
			return (ST_Mfail);
		}
		(*token)->len = 1;
		return (ST_Word);
	}
	if (ft_strchr(plv.ws_cset, c))
		return (ST_Success);
	(*token)->len += 1;
	if (dyn_strpushstr(&(*token)->value, &c, 1) < 0)
	{
		lx_del(token);
		return (ST_Mfail);
	}
	return (ST_Word);
}
