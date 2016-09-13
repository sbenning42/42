/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_code_p2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:39:14 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 12:37:31 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int					rl_code_right(t_rl *rl)
{
	char			c;

	if (!rl->dyn.post)
		return (0);
	dyn_strpoppost(&rl->dyn, &c, 1);
	dyn_strpushante(&rl->dyn, &c, 1);
	if (ISIN(rl->settings, RL_ECHO))
		cur_go_forward(1);
	return (0);
}

int					rl_code_left(t_rl *rl)
{
	char			c;

	if (!rl->dyn.ante)
		return (0);
	dyn_strpopante(&rl->dyn, &c, 1);
	dyn_strpushpost(&rl->dyn, &c, 1);
	if (ISIN(rl->settings, RL_ECHO))
		cur_go_backward(1);
	return (0);
}
