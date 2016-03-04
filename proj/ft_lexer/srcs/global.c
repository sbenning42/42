/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:24:12 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 00:18:34 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

t_key	g_key[RL_GKEY_SIZE] = {\
	{0xa, rl_maj_nl},\
	{0x7f, rl_maj_retarr},\
	{0x435b1b, rl_maj_right},\
	{0x445b1b, rl_maj_left},\
	{0x7e335b1b, rl_maj_suppr},\
	/*{, rl_maj_},\ */
};

t_lexcode	(*g_fstate)[LX_FSTATE_SIZE](char) = {\
	lx_stentry,\
	lx_stblank,\
	lx_stword,\
	lx_stchevxl,\
	lx_stchevxr,\
	lx_stquoted,\
	lx_stquotei,\
	lx_stquote,\
	lx_stparent,\
	lx_sthook,\
	lx_stor,\
	lx_stand,\
	lx_stescape,\
	lx_stexplicit\
	/*lx_st,\*/
};

t_lexstate	g_state[LX_STATE_SIZE] = {\
	ST_Chevxl,\
	ST_Chevxr,\
	ST_Chevxr,\
	ST_Chevxr,\
	ST_Quoted,\
	ST_Quotei,\
	ST_Quote,\
	ST_Parent,\
	ST_Hook,\
	ST_Or,\
	ST_And,\
	ST_Escape,\
	ST_Blank,\
	ST_Explicit,\
	ST_Explicit,\
	ST_Explicit,\
	ST_Explicit,\
	ST_Explicit,\
	ST_Word\
};
