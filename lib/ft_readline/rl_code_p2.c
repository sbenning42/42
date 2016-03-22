/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_code_p2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:39:14 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/22 13:31:50 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int					rl_code_right(t_rl *rl)
{
	char			c;

	if (!rl->dyn.post)
		return (0);
	rl->dyn.post -= 1;
	c = rl->dyn.str[rl->dyn.real - rl->dyn.post];
	rl->dyn.str[rl->dyn.ante] = c;
	rl->dyn.ante += 1;
	if (ISIN(rl->settings, RL_ECHO))
		ft_cap("nd", CAP_NOARG);
	return (0);
}

int					rl_code_left(t_rl *rl)
{
	char			c;

	if (!rl->dyn.ante)
		return (0);
	rl->dyn.ante -= 1;
	c = rl->dyn.str[rl->dyn.ante];
	rl->dyn.str[rl->dyn.ante] = 0;
	rl->dyn.str[rl->dyn.real - rl->dyn.post] = c;
	rl->dyn.post += 1;
	if (ISIN(rl->settings, RL_ECHO))
		ft_cap("le", CAP_NOARG);
	return (0);
}
