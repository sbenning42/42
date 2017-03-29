/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:12:22 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/23 13:13:01 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			label_state(t_lexem *lexem, char c)
{
	lexem->token.type = ST_LABEL;
	token_save(lexem);
	return (0);
	(void)c;
}

int			word_state(t_lexem *lexem, char c)
{
	lexem->token.type = ST_WORD;
	if (c == COMMENT_CHAR)
	{
		token_save(lexem);
		return (comment_state(lexem, c));
	}
	if (c == NL_CHAR)
	{
		token_save(lexem);
		return (default_state(lexem, c));
	}
	if (c == LABEL_CHAR)
		return (label_state(lexem, c));
	if (ft_strchr(LABEL_CHARS, c))
	{
		token_push(lexem, c);
		return (0);
	}
	if (c == DIRECT_CHAR || ft_strchr(WHITE_CHARS, c))
	{
		token_save(lexem);
		return (args_state(lexem, c));
	}
	ft_fprintf(2, "word_state: ");
	ft_fprintf(2, LEXICAL_ERR_FMT, lexem->token.line, lexem->token.column, c);
	return (flush_state(lexem, c));
}

int			literal_state(t_lexem *lexem, char c)
{
	lexem->token.type = ST_LITERAL;
	if (lexem->token.size || c == LITERAL_CHAR)
		token_push(lexem, c);
	if (c == LITERAL_CHAR && lexem->token.size > 1)
	{
		token_save(lexem);
		return (flush_state(lexem, c));
	}
	return (0);
}

int			command_state(t_lexem *lexem, char c)
{
	lexem->token.type = ST_CMD;
	if (c == NL_CHAR)
	{
		token_save(lexem);
		return (default_state(lexem, c));
	}
	if (ft_strchr(LABEL_CHARS, c) || (!lexem->token.size && c == CMD_CHAR))
	{
		token_push(lexem, c);
		return (0);
	}
	if (c == LITERAL_CHAR || ft_strchr(WHITE_CHARS, c))
	{
		token_save(lexem);
		return (literal_state(lexem, c));
	}
	if (c == COMMENT_CHAR)
	{
		token_save(lexem);
		return (comment_state(lexem, c));
	}
	ft_fprintf(2, "command_state: ");
	ft_fprintf(2, LEXICAL_ERR_FMT, lexem->token.line, lexem->token.column, c);
	return (flush_state(lexem, c));
}

int			default_state(t_lexem *lexem, char c)
{
	lexem->token.type = ST_DEFAULT;
	if (c == NL_CHAR || ft_strchr(WHITE_CHARS, c))
		return (0);
	if (c == COMMENT_CHAR)
		return (comment_state(lexem, c));
	if (c == CMD_CHAR)
		return (command_state(lexem, c));
	if (ft_strchr(LABEL_CHARS, c))
		return (word_state(lexem, c));
	ft_fprintf(2, "default_state: ");
	ft_fprintf(2, LEXICAL_ERR_FMT, lexem->token.line, lexem->token.column, c);
	return (flush_state(lexem, c));
}
