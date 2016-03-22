/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_code_p1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:39:14 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/22 13:16:14 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_code_nl(t_rl *rl)
{
	rl->bitset |= RL_BS_FLUSH;
	write(1, "\n", 1);
	return (0);
}

int		rl_code_d(t_rl *rl)
{
	exit(EXIT_SUCCESS);
	return (0);
	(void)rl;
}
