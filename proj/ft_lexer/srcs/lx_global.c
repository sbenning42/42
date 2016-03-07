/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 09:40:15 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/07 13:11:22 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_lxstate		(*g_wsfstate[LX_WSFSTATE_SIZE])(char, t_lxplv plv, t_lxem **token) = {\
	lx_wsstword\
};

t_lxplv			g_wsplv[LX_WSPLV_SIZE] = {\
	{0, LX_WORDSPLIT_NOPROTEC_CSET, LX_PROTEC_NOPRPTEC_CSET},\
	{0, LX_WORDSPLIT_ESCAPE_CSET, LX_PROTEC_ESCAPE_CSET},\
	{0, LX_WORDSPLIT_DQUOTE_CSET, LX_PROTEC_DQUOTE_CSET},\
	{0, LX_WORDSPLIT_ESCAPE_CSET, LX_PROTEC_ESCAPE_CSET},\
	{0, LX_WORDSPLIT_QUOTE_CSET, LX_PROTEC_QUOTE_CSET}\
};

int				g_wsplvbit[LX_WSPLVBIT_SIZE] = {\
	LX_PLVESCAPE,\
	LX_PLVDQUOTE,\
	LX_PLVQUOTE\
};

int				g_skip = 0;
