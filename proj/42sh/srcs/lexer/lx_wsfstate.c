/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_wsfstate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 11:11:41 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/15 14:31:17 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_lxstate		lx_wsfstate_word(t_lxem *token, char c, t_lxplv plv)
{
	char		*f;

	if (c && (f = ft_strchr(plv.ws_cset, c)))
	{
		if (token->len)
			return (ST_Success);
		token->len = 1;
		if (dyn_strpushstr(&token->value, &c, 1) < 0)
			return (ST_Fail);
		return (ST_Success);
	}
	else if (!c)
		return (ST_Success);
	if (dyn_strpushstr(&token->value, &c, 1) < 0)
		return (ST_Fail);
	token->len += 1;
	if (plv.bitset > LX_PLVESCAPE)
		token->plv = plv.bitset;
	return (ST_Word);
}
