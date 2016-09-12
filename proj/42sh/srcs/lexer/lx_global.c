/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 11:02:00 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/09 11:20:55 by sbenning         ###   ########.fr       */
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
	{\
		(LX_PLVESCAPE | LX_PLVDQUOTE),\
		LX_WORDSPLIT_ESCAPE_CSET,\
		LX_PROTEC_ESCAPE_CSET},\
	{LX_PLVQUOTE, LX_WORDSPLIT_QUOTE_CSET, LX_PROTEC_QUOTE_CSET}\
};

t_lxfstate	g_lxwsfstate[] = {\
	lx_wsfstate_word\
};

t_lxgrp		g_lxgrp[] = {\
	{{TY_Bg, LX_GROUP_BG}, lx_grp_bg},\
	{{TY_Pipe, LX_GROUP_PIPE}, lx_grp_pipe},\
	{{TY_Stdout_redir, LX_GROUP_TO}, lx_grp_to},\
	{{TY_Stdin_redir, LX_GROUP_FROM}, lx_grp_from},\
	{{TY_Strict_sep, LX_GROUP_SEP}, lx_grp_sep}\
};
