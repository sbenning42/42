/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_maj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:55:51 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/28 12:03:08 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int				rl_maj(t_rl *rl, long int code)
{
	static int	slct;
	int			ret;

	if ((ret = rl_searchcode(rl, code)) < 0)
		return (-1);
	if (ret == 0)
		rl_defcode(rl, code);
	if (ISIN(rl->bitset, RL_BS_SELECT))
		slct = 1;
	else if (slct)
	{
		slct = 0;
		rl->dyn.slct_ante = 0;
		rl->dyn.slct_post = 0;
		rl_reset_display(rl);
	}
	rl->bitset &= ~RL_BS_SELECT;
	return (0);
}
