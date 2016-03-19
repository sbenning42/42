/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_code.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 19:08:18 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/19 19:16:09 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_searchcode(t_rl *rl, int code)
{
	return (0);
	(void)rl;
	(void)code;
}

int		rl_defcode(t_rl *rl, int code)
{
	if (code == 0xa || code == 0x4)
		rl->bitset |= RL_BS_FLUSH;
	else if (code == 0x3)
	{
		rl_destroyterm();
		ft_exit(EXIT_SUCCESS, "Fatal QUIT");
	}
	return (0);
	(void)rl;
	(void)code;
}
