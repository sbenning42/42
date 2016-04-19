/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:28:10 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/19 11:48:27 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

t_rlcode	g_rlcode[RL_CODESIZE] = {\
	{0x1, rl_code_home},\
	{0xa, rl_code_nl},\
	{0x3, rl_code_c},\
	{0x4, rl_code_d},\
	{0xc, rl_code_cl},\
	{0x7f, rl_code_retarr},\
	{0x7e325b1b, rl_code_insert},\
	{0x435b1b, rl_code_right},\
	{0x445b1b, rl_code_left},\
	{0x7e335b1b, rl_code_suppr},\
	{0x415b1b, rl_code_up},\
	{0x425b1b, rl_code_down},\
	{0x7e355b1b, rl_code_pageup},\
	{0x7e365b1b, rl_code_pagedown},\
	{0x485b1b, rl_code_home},\
	{0x465b1b, rl_code_end},\
	{0x43353b315b1b, rl_code_wright},\
	{0x44353b315b1b, rl_code_wleft},\
	{0x631b, rl_code_cpy},\
	{0x781b, rl_code_cpe},\
	{0x761b, rl_code_cle},\
	{0x641b, rl_code_del},\
	{0x43333b315b1b, rl_code_slct_right},\
	{0x44333b315b1b, rl_code_slct_left},\
	{0x7e333b355b1b, rl_code_slct_pageup},\
	{0x7e333b365b1b, rl_code_slct_pagedown},\
	{0x48333b315b1b, rl_code_slct_home},\
	{0x46333b315b1b, rl_code_slct_end},\
	{0x43343b315b1b, rl_code_slct_wright},\
	{0x44343b315b1b, rl_code_slct_wleft}
	/*{, rl_code_},\ */
};
