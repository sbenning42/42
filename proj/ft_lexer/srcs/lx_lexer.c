/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:26:31 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/06 14:34:58 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_lexcode		lx_lexer(char *line, t_lex **token, int *protect)
{
	char		*cp;
	t_lexcode	code;
	t_lexstate	state;

	cp = line;
	state = ST_Entry;
	code = CO_Repeat;
	while (code == CO_Repeat)
	{
		code = g_fstate[state](*line, *token, protect, &state);
		line++;
	}
	if ((code == CO_Success) && ((*token)->value = ft_strsub(cp, 0, (*token)->len)))
		return (code);
	else if (code == CO_Fail)
		ft_fprintf(2, "lexer: Error near token '%.*s'\n", (*token)->len, cp);
	lx_del(token);
	return (CO_Fail);
}
