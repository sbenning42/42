/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_code_p1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:39:14 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/18 19:24:32 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_code_nl(t_rl *rl)
{
	rl->bitset |= RL_BS_FLUSH;
	if (rl->dyn.post)
		cur_go_forward(rl->dyn.post);
	write(1, "\n", 1);
	return (0);
}

int		rl_code_d(t_rl *rl)
{
	if (rl->dyn.used > 0)
		return (0);
	cur_resetterm();
	exit(EXIT_SUCCESS);
	return (0);
	(void)rl;
}
