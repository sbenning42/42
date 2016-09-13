/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_code_moves_part_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 13:37:19 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 13:38:18 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_code_cl(t_rl *rl)
{
	cur_all_clr();
	cur_cwrite(rl->prompt, rl->promptsize, ft_strlen(rl->prompt));
	if (ISIN(rl->settings, RL_ECHO))
	{
		if (rl->dyn.ante)
			cur_write(rl->dyn.str, rl->dyn.ante);
		rl_post_display(rl);
	}
	return (0);
}

int		rl_code_retarr(t_rl *rl)
{
	if (!rl->dyn.ante)
		return (0);
	dyn_strpopante(&rl->dyn, NULL, 1);
	if (ISIN(rl->settings, RL_ECHO))
	{
		cur_go_backward(1);
		rl_reset_post_display(rl);
	}
	return (0);
}

int		rl_code_suppr(t_rl *rl)
{
	if (!rl->dyn.post)
		return (0);
	dyn_strpoppost(&rl->dyn, NULL, 1);
	if (ISIN(rl->settings, RL_ECHO))
		rl_reset_post_display(rl);
	return (0);
}

int		rl_code_insert(t_rl *rl)
{
	if (ISIN(rl->bitset, RL_BS_INSERT))
		rl->bitset &= ~RL_BS_INSERT;
	else
		rl->bitset |= RL_BS_INSERT;
	return (0);
}
