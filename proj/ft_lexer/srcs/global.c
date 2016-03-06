/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:24:12 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/06 17:33:27 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

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
