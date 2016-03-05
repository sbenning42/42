/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 12:05:22 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 17:34:55 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

t_dlist		**rl_historytrace(void)
{
	static t_dlist	*history;

	return (&history);
}

int			rl_history_init(t_rl *rl, int gflag)
{
	rl->history_cursor = NULL;
	rl->history = (*rl_historytrace() ? *rl_historytrace() : NULL);
	if (ISATTR(gflag, RL_GLOAD) && (rl_history_load(rl) < 0))
		return (-1);
	return (0);
}

int			rl_init(t_rl *rl, int gflag, const char *prompt)
{
	size_t	offset;

	offset = RL_XMALLOC_SIZE;
	rl->prompt = ft_strlen(prompt);
	while (rl->prompt >= offset)
		offset *= 2;
	if (!(rl->buffer = ft_strnew(offset)))
		return (-1);
	if (ISATTR(gflag, RL_GHISTORY) && (rl_history_init(rl, gflag) < 0))
	{
		rl_quit(rl);
		return (-1);
	}
	rl->offset = offset;
	rl->real = offset;
	ft_strcpy(rl->buffer, prompt);
	rl->used = rl->prompt;
	rl->ante_cursor = rl->prompt;
	rl->post_cursor = rl->real;
	rl->gflag = gflag;
	rl->lflag = 0;
	return (0);
}

int			rl_quit(t_rl *rl)
{
	if (rl->buffer)
		ft_memdel((void **)&rl->buffer);
	if (ISATTR(rl->gflag, RL_GHISTORY) && rl->history && !*rl_historytrace())
		ft_dlstdel(&rl->history, NULL);
	return (0);
}
