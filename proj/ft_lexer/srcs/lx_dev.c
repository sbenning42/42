/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_dev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 19:34:49 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/07 15:06:46 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

static int			*static_lx_isplv(void)
{
	static int		plv;

	return (&plv);
}

t_lxem				*lx_dev_wordextract(char *line, t_lxplv *plv)
{
	char			*cp;
	t_lxstate		state;
	t_lxem			*token;

	cp = line;
	token = NULL;
	state = ST_Word;
	while (state == ST_Word)
	{
		cp += lx_plvmaj(*cp, plv);
		if (plv->bitset)
			*static_lx_isplv() |= (plv->bitset);
		if (!*cp)
			break ;
		if ((state = g_wsfstate[state](*cp, *plv, &token)) == ST_Skip)
			state = ST_Word;
		else
			cp++;
	}
	if (state == ST_Fail)
		ft_fprintf(2, "Inknow lexem: '%s'\n", cp - line);
	else if (token)
		token->plv = *static_lx_isplv();
	return (token);
}

t_lxem				*lx_wordsplit_dev(char *line)
{
	t_lxplv			plv;
	t_lxem			*lst;
	t_lxem			*token;

	lst = NULL;
	plv = g_wsplv[LX_PLVNOPROTEC];
	while (*line)
	{
		if (!(token = lx_dev_wordextract(line, &plv)))
		{
			g_skip = 0;
			*static_lx_isplv() = 0;
			break ;
		}
		line += token->len;
		line += g_skip;
		g_skip = 0;
		lx_addtoken(&lst, token);
		*static_lx_isplv() = 0;
	}
	if (plv.bitset > LX_PLVESCAPE)
	{
		ft_fprintf(2, "Lexem quoting error\n");
		lx_del(&lst);
		return (NULL);
	}
	return (lst);
}
