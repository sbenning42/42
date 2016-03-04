/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:41:43 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/04 13:39:35 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_maj_nl(t_rl *rl)
{
	rl->lflag |= RL_LFLUSH;
	return (0);
}

int		rl_maj_retarr(t_rl *rl)
{
	if (rl->ante_cursor == rl->prompt)
		return (0);
	rl_ante_pop(rl);
	rl->begin = rl->ante_cursor;
	rl->diff = 1;
	return (0);
}

int		rl_maj_suppr(t_rl *rl)
{
	if (rl->post_cursor == rl->real)
		return (0);
	rl_post_pop(rl);
	rl->begin = rl->ante_cursor;
	rl->diff = 1;
	return (0);
}

int		rl_maj_right(t_rl *rl)
{
	if (rl->post_cursor == rl->real)
		return (0);
	rl_ante_push(rl, rl_post_pop(rl));
	rl->begin = -1;
	return (0);
}

int		rl_maj_left(t_rl *rl)
{
	if (rl->ante_cursor == rl->prompt)
		return (0);
	rl_post_push(rl, rl_ante_pop(rl));
	rl->begin = -1;
	return (0);
}
