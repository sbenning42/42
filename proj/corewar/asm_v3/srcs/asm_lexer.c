/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 12:01:43 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/26 12:12:08 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			asm_lexer_match(t_asm_token_ref *ref, char **scan, t_asm_token **token)
{

}

int					asm_lexer(char **scan, t_asm_token **lexem)
{
	t_asm_token		*token;
	int				i;

	if (!**scan)
		return (0);
	i = -1;
	while (g_asm_token_ref[++i].value)
	{
		if (asm_lexer_match(g_asm_token_ref[i], scan, &token))
		{
			asm_lexer_push_token(lexem, token);
			return (asm_lexer(scan, lexem));
		}
	}
	return (ASM_LEXICAL_ERROR);
}
