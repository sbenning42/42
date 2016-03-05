/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:26:31 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 21:49:35 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_lex			*lx_lexer(char *id, char *line)
{
	t_lex		*token;
	t_lexstate	state;
	t_lexcode	code;

	if (!(token = (t_lex *)ft_memalloc(sizeof(t_lex))))
		return (NULL);
	code = CO_Repeat;
	if ((state = lx_entry(*line)) == ST_Error)
		code = CO_Fail;
	while (code == CO_Repeat)
	{
		if ((code = g_fstate[state](*line, token, &state)) == CO_Repeat)
			line++;
	}
	if (code == CO_Success)
	{
		if (!(token->value = ft_strsub(line - token->len, 0, token->len)))
			ft_memdel((void **)&token);
		return (token);
	}
	ft_fprintf(2, "%s: Error near token '%c'\n", id, *line);
	lx_del(&token);
	return (NULL);
}
