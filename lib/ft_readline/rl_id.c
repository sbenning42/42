/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_id.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:31:03 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/19 19:04:24 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static int		rl_initdyn(t_dyn *dyn, size_t offset)
{
	if (!(dyn->str = ft_strnew(offset)))
		return (-1);
	dyn->real = offset;
	dyn->used = 0;
	dyn->ante = 0;
	dyn->post = offset;
	return (0);
}

int				rl_init(t_rl *rl, int settings, size_t promptsize)
{
	static int	call;

	if (rl_initterm() < 0)
		return (-1);
	rl->settings = settings;
	if (!call && ISIN(settings, RL_HISTORY))
	{
		call = 1;
		if (rl_loadhistory() < 0)
		{
			ft_putendl("1");
			return (-1);
		}
	}
	if (rl_initdyn(&rl->dyn, RL_XMALLOC_OFFSET) < 0)
	{
		if (ISIN(settings, RL_HISTORY))
			rl_destroyhistory();
		ft_putendl("2");
		return (-1);
	}
	rl->bitset = 0;
	rl->history = NULL;
	rl->promptsize = promptsize;
	return (0);
}

int				rl_destroy(t_rl *rl)
{
	if (!rl->dyn.str)
		return (-1);
	free(rl->dyn.str);
	if (rl_destroyterm() < 0)
		return (-1);
	return (0);
}
