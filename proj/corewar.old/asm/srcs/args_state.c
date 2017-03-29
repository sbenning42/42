/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:08:22 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/23 13:17:34 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			args_state(t_lexem *lexem, char c)
{
	lexem->token.type = ST_ARGS;
	if (c == COMMENT_CHAR)
		return (comment_state(lexem, c));
	if (c == SEPARATOR_CHAR)
	{
		token_push(lexem, c);
		lexem->token.type = ST_SEPARATOR;
		token_save(lexem);
		lexem->token.type = ST_ARGS;
		return (0);
	}
	if (c == NL_CHAR)
		return (default_state(lexem, c));
	if (ft_strchr(WHITE_CHARS, c))
		return (0);
	if (c == 'r')
		return (reg_arg_state(lexem, c));
	if (c == DIRECT_CHAR)
		return (dir_arg_state(lexem, c));
	if (c == '-' || ft_strchr(LABEL_CHARS, c))
		return (ind_arg_state(lexem, c));
	ft_fprintf(2, "args_state: ");
	ft_fprintf(2, LEXICAL_ERR_FMT, lexem->token.line, lexem->token.column, c);
	return (flush_state(lexem, c));
}

int			lab_arg_state(t_lexem *lexem, char c)
{
	lexem->token.type = ST_LABEL_ARG;
	if (c == COMMENT_CHAR)
	{
		token_save(lexem);
		return (comment_state(lexem, c));
	}
	if (c == LABEL_CHAR && !lexem->token.size)
		return (0);
	if (ft_strchr(LABEL_CHARS, c))
	{
		token_push(lexem, c);
		return (0);
	}
	if (c == SEPARATOR_CHAR || ft_strchr(WHITE_CHARS, c))
	{
		token_save(lexem);
		return (args_state(lexem, c));
	}
	if (c == NL_CHAR)
	{
		token_save(lexem);
		return (default_state(lexem, c));
	}
	ft_fprintf(2, "lab_arg_state: ");
	ft_fprintf(2, LEXICAL_ERR_FMT, lexem->token.line, lexem->token.column, c);
	return (flush_state(lexem, c));
}

int			ind_arg_state(t_lexem *lexem, char c)
{
	lexem->token.type = ST_IND_ARG;
	if (c == COMMENT_CHAR)
	{
		token_save(lexem);
		return (comment_state(lexem, c));
	}
	if ((c == '-' && !lexem->token.size) || ft_strchr(LABEL_CHARS, c))
	{
		token_push(lexem, c);
		return (0);
	}
	if (c == SEPARATOR_CHAR || ft_strchr(WHITE_CHARS, c))
	{
		token_save(lexem);
		return (args_state(lexem, c));
	}
	if (c == NL_CHAR)
	{
		token_save(lexem);
		return (default_state(lexem, c));
	}
	ft_fprintf(2, "ind_arg_state: ");
	ft_fprintf(2, LEXICAL_ERR_FMT, lexem->token.line, lexem->token.column, c);
	return (flush_state(lexem, c));
}

int			dir_arg_state(t_lexem *lexem, char c)
{
	lexem->token.type = ST_DIR_ARG;
	if (c == DIRECT_CHAR && !lexem->token.size)
		return (0);
	if (c == LABEL_CHAR && !lexem->token.size)
		return (lab_arg_state(lexem, c));
	if (c == COMMENT_CHAR || c == SEPARATOR_CHAR || ft_strchr(WHITE_CHARS, c))
	{
		token_save(lexem);
		return ((c == COMMENT_CHAR ?\
					comment_state(lexem, c) : args_state(lexem, c)));
	}
	if ((c == '-' && !lexem->token.size) || ft_strchr(LABEL_CHARS, c))
	{
		token_push(lexem, c);
		return (0);
	}
	if (c == NL_CHAR)
	{
		token_save(lexem);
		return (default_state(lexem, c));
	}
	ft_fprintf(2, "dir_arg_state: ");
	ft_fprintf(2, LEXICAL_ERR_FMT, lexem->token.line, lexem->token.column, c);
	return (flush_state(lexem, c));
}

int			reg_arg_state(t_lexem *lexem, char c)
{
	lexem->token.type = ST_REG_ARG;
	if (c == 'r' && !lexem->token.size)
		return (0);
	if (c == COMMENT_CHAR)
	{
		token_save(lexem);
		return (comment_state(lexem, c));
	}
	if (c == SEPARATOR_CHAR || ft_strchr(WHITE_CHARS, c))
	{
		token_save(lexem);
		return (args_state(lexem, c));
	}
	if (c == NL_CHAR)
	{
		token_save(lexem);
		return (default_state(lexem, c));
	}
	if (ft_strchr(NUMERIC_CHARS, c))
	{
		token_push(lexem, c);
		return (0);
	}
	ft_fprintf(2, "reg_arg_state: ");
	ft_fprintf(2, LEXICAL_ERR_FMT, lexem->token.line, lexem->token.column, c);
	return (flush_state(lexem, c));
}
