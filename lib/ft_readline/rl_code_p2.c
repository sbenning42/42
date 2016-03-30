/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_code_p2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:39:14 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/29 13:19:03 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void				rl_code_right_echo(t_rl *rl)
{
	int				col;

	col = tgetnum("co");
	if (!((rl->dyn.ante + rl->promptsize) % col))
		ft_cap("do", CAP_NOARG);
	else
		ft_cap("nd", CAP_NOARG);
}

void				rl_code_left_echo(t_rl *rl)
{
	int				col;

	col = tgetnum("co");
	if (!((rl->dyn.ante + rl->promptsize) % col))
	{
		ft_cap("up", CAP_NOARG);
		ft_cap("RI", CAP_PARAM(col - 1));
	}
	else
		ft_cap("le", CAP_NOARG);
}

int					rl_code_right(t_rl *rl)
{
	char			c;

	if (!rl->dyn.post)
		return (0);
	dyn_strpoppost(&rl->dyn, &c, 1);
	dyn_strpushante(&rl->dyn, &c, 1);
	if (ISIN(rl->settings, RL_ECHO))
		rl_code_right_echo(rl);
	return (0);
}

int					rl_code_left(t_rl *rl)
{
	char			c;

	if (!rl->dyn.ante)
		return (0);
	if (ISIN(rl->settings, RL_ECHO))
		rl_code_left_echo(rl);
	dyn_strpopante(&rl->dyn, &c, 1);
	dyn_strpushpost(&rl->dyn, &c, 1);
	return (0);
}
