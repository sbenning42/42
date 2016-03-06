/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_dev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 19:34:49 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/06 22:30:11 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_lxem				*lx_dev_wordextract(char *s, char *cset, int *plv)
{
	char			*cp;
	t_lxcode		code;
	t_lxstate		state;
	t_lxem			*token;

	cp = s;
	token = NULL;
	state = ST_Entry;
	code = CO_Repeat;
	while (code == CO_Repeat)
		code = g_ws_fstate[state](*s++, lx_plvhandle(plv), &state, &token);
	if (code == CO_Fail)
		ft_fprintf(2, "Inknow lexem: '%s'\n", s - cp);
	return (token);
}

t_lxem				*lx_dev_wordsplit(char *s, char *cset)
{
	int				plv;
	t_lxem			*lst;
	t_lxem			*token;

	lst = NULL;
	plv = LX_PLVNOPROTEC;
	while (s)
	{
		if (!(token = lx_dev_wordextract(s, cset, &plv)))
		{
			lx_del(&lst);
			return (NULL);
		}
		s += token->len;
		lx_addtoken(&lst, token);
	}
	return (lst);
}
