/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_match.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 10:24:04 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/24 15:46:14 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			match_c(char **scan, t_lexem *lexer, char c)
{
	char	*tmp;

	tmp = *scan;
	if (**scan == c)
	{
		*scan += 1;
		/*TODO: push lexer*/
		return (1);
	}
	return (0);
	(void)lexer;
}

int			match_c_minus(char **scan, t_lexem *lexer)
{
	return (match_c(scan, lexer, MINUS_CHAR));
}

int			match_c_comment(char **scan, t_lexem *lexer)
{
	return (match_c(scan, lexer, COMMENT_CHAR));
}

int			match_c_command(char **scan, t_lexem *lexer)
{
	return (match_c(scan, lexer, COMMAND_CHAR));
}

int			match_c_label(char **scan, t_lexem *lexer)
{
	return (match_c(scan, lexer, LABEL_CHAR));
}

int			match_c_separator(char **scan, t_lexem *lexer)
{
	return (match_c(scan, lexer, SEPARATOR_CHAR));
}

int			match_c_direct(char **scan, t_lexem *lexer)
{
	return (match_c(scan, lexer, DIRECT_CHAR));
}

int			match_c_registre(char **scan, t_lexem *lexer)
{
	return (match_c(scan, lexer, REGISTRE_CHAR));
}

int			match_c_literal(char **scan, t_lexem *lexer)
{
	return (match_c(scan, lexer, LITERAL_CHAR));
}

int			match_c_end_line(char **scan, t_lexem *lexer)
{
	char	*tmp;
	int		ret;

	tmp = *scan;
	ret = 1;
	while (**scan && **scan != END_LINE_CHAR)
	{
		if (**scan != ' ' && **scan != '\t')
			ret = 0;
		*scan += 1;
	}
	if (**scan != END_LINE_CHAR)
	{
		*scan = tmp;
		return (0);
	}
	/*TODO: push lexer*/
	return (ret);
	(void)lexer;
}

int			match_charset(char **scan, t_lexem *lexer, char *charset)
{
	char	*tmp;

	tmp = *scan;
	while (**scan && ft_strchr(charset, **scan))
		*scan += 1;
	if (*scan == tmp)
		return (0);
	/*TODO: push lexer*/
	return (1);
	(void)lexer;
}

int			match_identifier(char **scan, t_lexem *lexer)
{
	if ((**scan < 'a' || **scan > 'z') && **scan != '_')
		return (0);
	return (match_charset(scan, lexer, LABEL_CHARS));
}

int			match_uinteger(char **scan, t_lexem *lexer)
{
	return (match_charset(scan, lexer, "0123456789"));
}

int			match_end_literal(char **scan, t_lexem *lexer)
{
	char	*tmp;

	tmp = *scan;
	while (**scan && **scan != LITERAL_CHAR)
		*scan += 1;
	if (!**scan || *scan == tmp)
	{
		*scan = tmp;
		return (0);
	}
	*scan += 1;
	/*TODO: push lexer*/
	return (1);
	(void)lexer;
}
