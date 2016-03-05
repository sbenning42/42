/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_history_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 11:47:11 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 15:43:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int				rl_maj_up(t_rl *rl)
{
	if (!ISATTR(rl->gflag, RL_GHISTORY))
		return (0);
	rl->lflag |= RL_LHISTORY;
	if (rl->history_cursor)
	{
		if (!rl->history_cursor->n)
			return (0);
		rl->history_cursor = rl->history_cursor->n;
	}
	else
		rl->history_cursor = rl->history;
	if (rl_getrl(rl) < 0)
		return (-1);
	rl->diff.type = RL_TAPPEND;
	rl->diff.begin = 0;
	rl->diff.offset = rl->ante_cursor;
	return (0);
}

int			rl_maj_down(t_rl *rl)
{
	if (!ISATTR(rl->gflag, RL_GHISTORY) || !rl->history_cursor)
		return (0);
	rl->lflag |= RL_LHISTORY;
	rl->history_cursor = rl->history_cursor->p;
	if (rl_getrl(rl) < 0)
		return (-1);
	rl->diff.type = RL_TAPPEND;
	rl->diff.begin = 0;
	rl->diff.offset = rl->ante_cursor;
	return (0);
}
