/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:28:10 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 23:02:10 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

t_rlcode	g_rlcode[RL_CODESIZE] = {\
	{0x1, rl_code_home},\
	{0xa, rl_code_nl},\
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
	{0x465b1b, rl_code_end}
	/*{, rl_code_},\ */
};
