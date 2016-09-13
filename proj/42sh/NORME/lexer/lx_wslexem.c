/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_wslexem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:45:23 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/09 11:22:09 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_lxem			*lx_handlestate(t_lxem **token,\
								t_lxstate state,\
								char c,\
								int plv)
{
	if ((state == ST_Fail) || (state == ST_Synfail) || plv)
		lx_del(token);
	if (state == ST_Synfail)
		ft_fprintf(2, "lexer: Token error near '%c'\n", c);
	if (plv)
		ft_fprintf(2, "lexer: Token quoting error\n");
	return (*token);
}

t_lxem			*lx_wslexem(char *line)
{
	t_lxem		*token;
	t_lxstate	state;
	t_lxplv		plv;

	if (!(token = lx_newtoken(TY_Word)))
		return (NULL);
	state = ST_Word;
	plv.bitset = 0;
	plv.ws_cset = LX_WORDSPLIT_NOPROTEC_CSET;
	plv.protec_cset = LX_PROTEC_NOPROTEC_CSET;
	while (*line && (state < ST_Success))
	{
		while (*line && lx_majplv(*line, &plv))
			line++;
		state = g_lxwsfstate[state](token, *line, plv);
		line++;
		plv.bitset &= ~LX_PLVESCAPE;
		plv = g_lxplv[plv.bitset];
	}
	return (lx_handlestate(&token, state, *(line - 1), plv.bitset));
}
