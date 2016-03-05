/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:24:12 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 21:15:40 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"
#include "ft_lexer.h"

t_key	g_key[RL_GKEY_SIZE] = {\
	{0x1, rl_maj_home},\
	{0xa, rl_maj_nl},\
	{0x4, rl_maj_d},\
	{0xc, rl_maj_cl},\
	{0x7f, rl_maj_retarr},\
	{0x1b, rl_maj_insert},\
	{0x435b1b, rl_maj_right},\
	{0x445b1b, rl_maj_left},\
	{0x7e335b1b, rl_maj_suppr},\
	{0x415b1b, rl_maj_up},\
	{0x425b1b, rl_maj_down},\
	{0x485b1b, rl_maj_home},\
	{0x465b1b, rl_maj_end},\
	/*{, rl_maj_},\ */
};

t_lexstate		g_state[LX_STATE_SIZE] = {\
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
	ST_Tild,\
	ST_Comm,\
	ST_Autocmp,\
	ST_Neg,\
	ST_Sub,\
	//ST_,\/
	\
};

t_lexfstate		g_fstate[LX_STATE_SIZE] = {\
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
	lx_sttild,\
	lx_stcomm,\
	lx_stautocomp,\
	lx_stneg,\
	lx_stsub\
};
