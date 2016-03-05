/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 23:32:38 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 22:42:30 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_lexcode				lx_stword(char c, t_lex *token, t_lexstate *state)
{
	char				*s;

	(void)state;
	s = LX_CSET_SEARCH;
	if (ft_strchr(s, c) || !ft_isprint(c))
		return (CO_Success);
	if (token->type == TY_None)
		token->type = TY_Word;
	token->len += 1;
	return (CO_Repeat);
}

t_lexcode				lx_stblank(char c, t_lex *token, t_lexstate *state)
{
	(void)state;
	if (c != ' ')
		return (CO_Success);
	if (token->type == TY_None)
		token->type = TY_Blank;
	token->len += 1;
	return (CO_Repeat);
}

t_lexcode				lx_stchevxl(char c, t_lex *token, t_lexstate *state)
{
	(void)c;
	(void)token;
	(void)state;
	return (CO_Fail);
}

t_lexcode				lx_stchevxr(char c, t_lex *token, t_lexstate *state)
{
	(void)c;
	(void)token;
	(void)state;
	return (CO_Fail);
}

t_lexcode				lx_stquoted(char c, t_lex *token, t_lexstate *state)
{
	(void)c;
	(void)token;
	(void)state;
	return (CO_Fail);
}

t_lexcode				lx_stquotei(char c, t_lex *token, t_lexstate *state)
{
	(void)c;
	(void)token;
	(void)state;
	return (CO_Fail);
}

t_lexcode				lx_stquote(char c, t_lex *token, t_lexstate *state)
{
	static int			quoting;
	static int			success;

	(void)state;
	if (!quoting)
	{
		token->type = TY_Quote;
		token->len += 1;
		quoting = 1;
	}
	else if ((!success) && (c) && (c != '\''))
		token->len += 1;
	else if (success)
	{
		quoting = 0;
		success = 0;
		return (CO_Success);
	}
	else if (c == '\'')
	{
		token->len += 1;
		success = 1;
	}
	else if (c == 0)
	{
		quoting = 0;
		success = 0;
		return (CO_Fail);
	}
	return (CO_Repeat);
}

t_lexcode				lx_stparent(char c, t_lex *token, t_lexstate *state)
{
	(void)c;
	(void)token;
	(void)state;
	return (CO_Fail);
}

t_lexcode				lx_sthook(char c, t_lex *token, t_lexstate *state)
{
	(void)c;
	(void)token;
	(void)state;
	return (CO_Fail);
}

t_lexcode				lx_stor(char c, t_lex *token, t_lexstate *state)
{
	(void)state;
	if ((token->len == 1 && c != '|') || (token->len == 2))
		return (CO_Success);
	if  (token->len == 1 && c == '|')
	{
		token->type = TY_Or;
		token->len = 2;
	}
	else if (!token->len)
	{
		token->type = TY_Pipe;
		token->len = 1;
	}
	return (CO_Repeat);
}

t_lexcode				lx_stand(char c, t_lex *token, t_lexstate *state)
{
	(void)state;
	if ((token->len == 1 && c != '&') || (token->len == 2))
		return (CO_Success);
	if  (token->len == 1 && c == '&')
	{
		token->type = TY_And;
		token->len = 2;
	}
	else if (!token->len)
	{
		token->type = TY_Bground;
		token->len = 1;
	}
	return (CO_Repeat);
}

t_lexcode				lx_stescape(char c, t_lex *token, t_lexstate *state)
{
	(void)state;
	(void)c;
	if (token->len == 2)
		return (CO_Success);
	if (token->len)
		token->len = 2;
	else
	{
		token->type = TY_Escape;
		token->len = 1;
	}
	return (CO_Repeat);
}

t_lexcode				lx_sttild(char c, t_lex *token, t_lexstate *state)
{
	(void)c;
	(void)state;
	if (token->len)
		return (CO_Success);
	token->type = TY_Tild;
	token->len = 1;
	return (CO_Repeat);
}

t_lexcode				lx_stcomm(char c, t_lex *token, t_lexstate *state)
{
	(void)c;
	(void)state;
	if (token->len)
		return (CO_Success);
	token->type = TY_Comm;
	token->len = 1;
	return (CO_Repeat);
}

t_lexcode				lx_stautocomp(char c, t_lex *token, t_lexstate *state)
{
	(void)c;
	(void)state;
	if (token->len)
		return (CO_Success);
	token->type = TY_Match;
	token->len = 1;
	return (CO_Repeat);
}

t_lexcode				lx_stneg(char c, t_lex *token, t_lexstate *state)
{
	(void)c;
	(void)state;
	if (token->len)
		return (CO_Success);
	token->type = TY_Neg;
	token->len = 1;
	return (CO_Repeat);
}

t_lexcode				lx_stsub(char c, t_lex *token, t_lexstate *state)
{
	(void)c;
	(void)state;
	if (token->len)
		return (CO_Success);
	token->type = TY_Sub;
	token->len = 1;
	return (CO_Repeat);
}
