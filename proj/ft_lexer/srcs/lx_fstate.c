/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_fstate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 13:10:06 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/06 16:20:46 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

char		*lx_selectcset(int protect)
{
	if (ISBIT(protect, LX_PDQUOTE))
		return (LX_CSET_DQUOTE);
	if (ISBIT(protect, LX_PIQUOTE))
		return (LX_CSET_IQUOTE);
	if (ISBIT(protect, LX_PQUOTE))
		return (LX_CSET_QUOTE);
	return (LX_CSET_ALL);
}

t_lexcode	lx_stentry(char c, t_lex *token, int *protect, t_lexstate *state)
{
	char	*s;
	char	*f;

	s = lx_selectcset(*protect);
	if ((f = ft_strchr(s, c)))
		*state = g_state[f - s];
	else if (ft_isprint(c))
		*state = ST_Word;
	else
		return (CO_Fail);
	token->len = 1;
	return (CO_Repeat);
}

t_lexcode	lx_stword(char c, t_lex *token, int *protect, t_lexstate *state)
{
	char	*s;
	char	*f;

	(void)state;
	s = lx_selectcset(*protect);
	if ((f = ft_strchr(s, c)))
	{
	 	if (!*protect)
			return (CO_Success);
		else
			*state = g_state[f - s];
	}
	else if (ft_isprint(c))
	{
		token->len += 1;
		token->type = TY_Word;
	}
	else
		return (CO_Fail);
	return (CO_Repeat);
}

t_lexcode	lx_stblank(char c, t_lex *token, int *protect, t_lexstate *state)
{
	(void)state;
	(void)protect;
	token->type = TY_Blank;
	if (c != ' ')
		return (CO_Success);
	token->len += 1;
	return (CO_Repeat);
}

t_lexcode	lx_stescape(char c, t_lex *token, int *protect, t_lexstate *state)
{
	(void)c;
	(void)protect;
	*state = ST_Word;
	token->len += 1;
	token->type = TY_Word;
	return (CO_Repeat);
}

t_lexcode	lx_stchevxl(char c, t_lex *token, int *protect, t_lexstate *state)
{
	(void)c;
	(void)protect;
	(void)state;
	(void)token;
	return (CO_Fail);
}

t_lexcode	lx_stchevxr(char c, t_lex *token, int *protect, t_lexstate *state)
{
	(void)c;
	(void)protect;
	(void)state;
	(void)token;
	return (CO_Fail);
}

t_lexcode	lx_stquoted(char c, t_lex *token, int *protect, t_lexstate *state)
{
	char	*s;
	char	*f;

	(void)state;
	*protect |= LX_PDQUOTE;
	s = lx_selectcset(*protect);
	if (!ft_isprint(c) || !c)
		return (CO_Fail);
	else if (c == '\\')
		*state = ST_Escape;
	else if ((f = ft_strchr(s, c)))
		return (CO_Success);
	token->len += 1;
	token->type = TY_Word;
	if (c == '"')
	{
		*protect &= ~LX_PDQUOTE;
		return (CO_Success);
	}
	return (CO_Repeat);
}

t_lexcode	lx_stquotei(char c, t_lex *token, int *protect, t_lexstate *state)
{
	(void)c;
	(void)protect;
	(void)state;
	(void)token;
	return (CO_Fail);
}

t_lexcode	lx_stquote(char c, t_lex *token, int *protect, t_lexstate *state)
{

	(void)state;
	*protect |= LX_PQUOTE;
	token->len += 1;
	token->type = TY_Word;
	if (c == '\'')
	{
		*protect &= ~LX_PQUOTE;
		return (CO_Success);
	}
	else if (!c)
		return (CO_Fail);
	return (CO_Repeat);
}

t_lexcode	lx_stparent(char c, t_lex *token, int *protect, t_lexstate *state)
{
	(void)c;
	(void)protect;
	(void)state;
	(void)token;
	return (CO_Fail);
}

t_lexcode	lx_sthook(char c, t_lex *token, int *protect, t_lexstate *state)
{
	(void)c;
	(void)protect;
	(void)state;
	(void)token;
	return (CO_Fail);
}

t_lexcode	lx_stor(char c, t_lex *token, int *protect, t_lexstate *state)
{
	(void)c;
	(void)protect;
	(void)state;
	(void)token;
	return (CO_Fail);
}

t_lexcode	lx_stand(char c, t_lex *token, int *protect, t_lexstate *state)
{
	(void)c;
	(void)protect;
	(void)state;
	(void)token;
	return (CO_Fail);
}

t_lexcode	lx_sttild(char c, t_lex *token, int *protect, t_lexstate *state)
{
	(void)c;
	(void)protect;
	(void)state;
	(void)token;
	return (CO_Fail);
}

t_lexcode	lx_stcomm(char c, t_lex *token, int *protect, t_lexstate *state)
{
	(void)c;
	(void)protect;
	(void)state;
	(void)token;
	return (CO_Fail);
}

t_lexcode	lx_stmatch(char c, t_lex *token, int *protect, t_lexstate *state)
{
	(void)c;
	(void)protect;
	(void)state;
	(void)token;
	return (CO_Fail);
}

t_lexcode	lx_stsub(char c, t_lex *token, int *protect, t_lexstate *state)
{
	(void)c;
	(void)protect;
	(void)state;
	(void)token;
	return (CO_Fail);
}

t_lexcode	lx_stneg(char c, t_lex *token, int *protect, t_lexstate *state)
{
	(void)c;
	(void)protect;
	(void)state;
	(void)token;
	return (CO_Fail);
}

t_lexcode	lx_stvar(char c, t_lex *token, int *protect, t_lexstate *state)
{
	(void)c;
	(void)protect;
	(void)state;
	(void)token;
	return (CO_Fail);
}

t_lexcode	lx_stsep(char c, t_lex *token, int *protect, t_lexstate *state)
{
	(void)c;
	(void)protect;
	(void)state;
	(void)token;
	return (CO_Fail);
}
