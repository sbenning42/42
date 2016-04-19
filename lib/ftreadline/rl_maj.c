/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_maj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:55:51 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/19 13:18:17 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int				rl_maj(t_rl *rl, long int code)
{
	static int	slct;
	int			ret;

	if (!(ret = rl_searchcode(rl, code)))
		rl_defcode(rl, code);
	else if (ret < 0)
		return (-1);
	if (ISIN(rl->bitset, RL_BS_SELECT))
		slct = 1;
	else if (slct)
	{
		slct = 0;
		rl->dyn.slct_ante = 0;
		rl->dyn.slct_post = 0;
		if (rl->dyn.ante)
		{
			cur_go_backward(rl->dyn.ante);
			cur_write(rl->dyn.str, rl->dyn.ante);
		}
		if (rl->dyn.post)
			cur_static_write(rl->dyn.strend - rl->dyn.post, rl->dyn.post);
	}
	rl->bitset &= ~RL_BS_SELECT;
	return (0);
}
