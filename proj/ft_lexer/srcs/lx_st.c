/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 23:32:38 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 00:21:01 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_lexcode		lx_entry_state(int i, t_lexstate *curr_state)
{
	if ((*curr_state = g_state[i]) != ST_Explicit)
		return (CO_Success);
	*crr_state == ST_Entry;
	if (!())
}

char			*lx_chr(char *s, char c)
{
	char		*f;

	if ((f = ft_strchr(s, c)))
		return (f);
	return (NULL);
}

t_lexcode		lx_stentry(char c, t_lex **token, t_lexstate *curr_state)
{
	char		*s;
	char		*f;
	
	(void)alst;
	s = LX_CSET_SEARCH;
	if (!(f = lx_chr(s, c)))
	{
		if (!(*token = (t_lex *)ft_memalloc(sizeof(t_lex))))
			return (CO_Fail);
		if (!((*token)->value = ft_strnew(1)))
		{
			ft_memdel((void **)token);
			return (CO_FAIL);
		}
		*(*token)->value = c;
		return (CO_Fail);
	}lx_entrystate(f - s, curr_state)
	return ();
}
