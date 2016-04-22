/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 11:02:00 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/15 13:54:05 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int			g_plvskip = 0;

int			g_lxplvbit[] = {\
	LX_PLVESCAPE,\
	LX_PLVDQUOTE,\
	LX_PLVQUOTE\
};

t_lxplv		g_lxplv[] = {\
	{LX_PLVNOPROTEC, LX_WORDSPLIT_NOPROTEC_CSET, LX_PROTEC_NOPROTEC_CSET},\
	{LX_PLVESCAPE, LX_WORDSPLIT_ESCAPE_CSET, LX_PROTEC_ESCAPE_CSET},\
	{LX_PLVDQUOTE, LX_WORDSPLIT_DQUOTE_CSET, LX_PROTEC_DQUOTE_CSET},\
	{(LX_PLVESCAPE | LX_PLVDQUOTE), LX_WORDSPLIT_ESCAPE_CSET, LX_PROTEC_ESCAPE_CSET},\
	{LX_PLVQUOTE, LX_WORDSPLIT_QUOTE_CSET, LX_PROTEC_QUOTE_CSET}\
};

t_lxfstate	g_lxwsfstate[] = {\
	lx_wsfstate_word\
};

t_lxem_low	g_lxreserved[] = {\
	{TY_Neg, "!"},\
	{TY_Case, "case"},\
	{TY_Coproc, "coproc"},\
	{TY_Do, "do"},\
	{TY_Done, "done"},\
	{TY_Elif, "elif"},\
	{TY_Else, "else"},\
	{TY_Esac, "esac"},\
	{TY_Fi, "fi"},\
	{TY_For, "for"},\
	{TY_Function, "function"},\
	{TY_If, "if"},\
	{TY_In, "in"},\
	{TY_Select, "select"},\
	{TY_Then, "then"},\
	{TY_Until, "until"},\
	{TY_While, "while"},\
	{TY_Bracket_open, "{"},\
	{TY_Bracket_close, "}"},\
	{TY_Time, "time"},\
	{TY_Hook_open, "[["},\
	{TY_Hook_close, "]]"}\
};
