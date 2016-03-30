/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 19:09:25 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/22 12:10:37 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void		rl_echo(t_rl *rl)
{
	if (!ISIN(rl->bitset, RL_BS_FLUSH))
		ft_printf("%s", rl->dyn.str + rl->dyn.ante - 1);
	else
		write(1, "\n", 1);
	(void)rl;
}
