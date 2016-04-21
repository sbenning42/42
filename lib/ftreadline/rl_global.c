/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:28:10 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/21 09:27:31 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

t_rlcode	g_rlcode[RL_CODESIZE] = {\
	{RL_CODE_CTRL_A, rl_code_home},\
	{RL_CODE_CTRL_C, rl_code_c},\
	{RL_CODE_CTRL_D, rl_code_d},\
	{RL_CODE_CTRL_L, rl_code_cl},\
	{RL_CODE_RETARR, rl_code_retarr},\
	{RL_CODE_SUPPR, rl_code_suppr},\
	{RL_CODE_INSERT, rl_code_insert},\
	{RL_CODE_ESC, rl_code_esc},\
	{RL_CODE_NL, rl_code_nl},\
	{RL_CODE_RIGHT, rl_code_right},\
	{RL_CODE_LEFT, rl_code_left},\
	{RL_CODE_UP, rl_code_up},\
	{RL_CODE_DOWN, rl_code_down},\
	{RL_CODE_PAGEUP, rl_code_pageup},\
	{RL_CODE_PAGEDOWN, rl_code_pagedown},\
	{RL_CODE_HOME, rl_code_home},\
	{RL_CODE_END, rl_code_end},\
	{RL_CODE_WRIGHT, rl_code_wright},\
	{RL_CODE_WLEFT, rl_code_wleft},\
	{RL_CODE_COPY, rl_code_cpy},\
	{RL_CODE_CUT, rl_code_cut},\
	{RL_CODE_PASTE, rl_code_cle},\
	{RL_CODE_DELETE, rl_code_del},\
	{RL_CODE_SELECT_RIGHT, rl_code_slct_right},\
	{RL_CODE_SELECT_LEFT, rl_code_slct_left},\
	{RL_CODE_SELECT_PAGEUP, rl_code_slct_pageup},\
	{RL_CODE_SELECT_PAGEDOWN, rl_code_slct_pagedown},\
	{RL_CODE_SELECT_HOME, rl_code_slct_home},\
	{RL_CODE_SELECT_END, rl_code_slct_end},\
	{RL_CODE_SELECT_WRIGHT, rl_code_slct_wright},\
	{RL_CODE_SELECT_WLEFT, rl_code_slct_wleft}
};
