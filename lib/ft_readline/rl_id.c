/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_id.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:31:03 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/22 12:49:29 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static int		rl_initdyn(t_dyn *dyn, size_t offset)
{
	if (!(dyn->str = ft_strnew(offset)))
		return (-1);
	dyn->offset = offset;
	dyn->real = offset;
	dyn->used = 0;
	dyn->ante = 0;
	dyn->post = 0;
	return (0);
}

int				rl_init(t_rl *rl, int settings, char *prompt)
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
	rl->prompt = prompt;
	rl->promptsize = ft_strlen(prompt);
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
