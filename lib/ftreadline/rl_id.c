/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_id.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:31:03 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/22 11:53:29 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static int		rl_initdyn(t_dyn *dyn, size_t offset)
{
	if (!(dyn->str = ft_strnew(offset)))
		return (-1);
	dyn->strend = dyn->str + offset;
	dyn->slct = NULL;
	dyn->offset = offset;
	dyn->real = offset;
	dyn->used = 0;
	dyn->ante = 0;
	dyn->post = 0;
	dyn->slct_ante = 0;
	dyn->slct_post = 0;
	return (0);
}

int				rl_init(t_rl *rl, t_hist *hist, int settings, char *prompt)
{
	cur_initterm();
	cur_init();
	rl->settings = settings;
	rl->hist_cp.list = NULL;
	if (rl_initdyn(&rl->dyn, RL_XMALLOC_OFFSET) < 0)
		return (-1);
	if (ISIN(settings, RL_HISTORY))
	{
		if (hist_copy(hist, &rl->hist_cp) < 0)
		{
			rl_destroy(rl);
			return (-1);
		}
	}
	rl->bitset = 0;
	rl->prompt = prompt;
	rl->promptsize = ft_strlen(prompt);
	return (0);
}

int				rl_destroy(t_rl *rl)
{
	if (ISIN(rl->settings, RL_HISTORY))
		ft_dlstdel(&rl->hist_cp.list, NULL);
	if (rl->dyn.str)
		ft_memdel((void **)&rl->dyn.str);
	cur_resetterm();
	return (0);
}
