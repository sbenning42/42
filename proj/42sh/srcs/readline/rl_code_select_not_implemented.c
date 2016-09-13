/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_code_select_not_implemented.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 13:27:26 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 13:27:53 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_code_slct_pageup(t_rl *rl)
{
	size_t	co;

	co = cur_get_scrco() + 1;
	if (rl->dyn.ante <= co)
		return (rl_code_slct_home(rl));
	rl->bitset |= RL_BS_SELECT;
	return (0);
	(void)rl;
}

int			rl_code_slct_pagedown(t_rl *rl)
{
	size_t	co;

	co = cur_get_scrco() + 1;
	if (rl->dyn.post <= co)
		return (rl_code_slct_end(rl));
	rl->bitset |= RL_BS_SELECT;
	return (0);
	(void)rl;
}

int			rl_code_slct_wright(t_rl *rl)
{
	if (!rl->dyn.post)
		return (0);
	rl->bitset |= RL_BS_SELECT;
	return (0);
	(void)rl;
}

int			rl_code_slct_wleft(t_rl *rl)
{
	if (!rl->dyn.ante)
		return (0);
	rl->bitset |= RL_BS_SELECT;
	return (0);
	(void)rl;
}
