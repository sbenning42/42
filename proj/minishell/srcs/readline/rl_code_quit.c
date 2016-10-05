/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_code_p1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:39:14 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/27 22:24:02 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_code_nl(t_rl *rl)
{
	rl->bitset |= RL_BS_FLUSH;
	if (ISIN(rl->settings, RL_ECHO))
	{
		if (rl->dyn.post)
			cur_go_forward(rl->dyn.post);
	}
	return (0);
}

int		rl_code_c(t_rl *rl)
{
	rl->bitset |= RL_BS_QFLUSH;
	if (ISIN(rl->settings, RL_ECHO))
	{
		if (rl->dyn.post)
			cur_go_forward(rl->dyn.post);
	}
	write(1, "^C", 2);
	return (0);
}

int		rl_code_d(t_rl *rl)
{
	if (rl->dyn.used > 0)
		return (0);
	write(1, "exit\n", 5);
	cur_resetterm();
	exit(EXIT_SUCCESS);
	return (0);
	(void)rl;
}
