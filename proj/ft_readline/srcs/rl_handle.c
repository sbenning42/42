/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:41:43 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 14:58:35 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_maj_nl(t_rl *rl)
{
	t_dlist	*entry;
	char	*line;

	if (ISATTR(rl->gflag, RL_GHISTORY) && (rl->used > rl->prompt))
	{
		if (!(line = ft_strjoin(rl->buffer + rl->prompt, rl->buffer + rl->post_cursor)))
			return (-1);
		if (!(entry = ft_dlstnew((void *)line, ft_strlen(line) + 1)))
		{
			free(line);
			return (-1);
		}
		ft_dlstaddp(&rl->history, entry);
		if (ISATTR(rl->gflag, RL_GSAVE))
			rl_history_save((char *)entry->content);
		free(line);
	}
	rl->lflag |= RL_LFLUSH;
	return (0);
}

int		rl_maj_retarr(t_rl *rl)
{
	if (rl->ante_cursor == rl->prompt)
		return (0);
	rl_ante_pop(rl);
	rl->diff.type = RL_TERASE;
	rl->diff.begin = rl->ante_cursor;
	rl->diff.offset = 0;
	return (0);
}

int		rl_maj_suppr(t_rl *rl)
{
	if (rl->post_cursor == rl->real)
		return (0);
	rl_post_pop(rl);
	rl->diff.type = RL_TERASE;
	rl->diff.begin = rl->ante_cursor;
	rl->diff.offset = 0;
	return (0);
}

int		rl_maj_right(t_rl *rl)
{
	if (rl->post_cursor == rl->real)
		return (0);
	rl->diff.type = RL_TCURSORONLY;
	rl->diff.begin = -1;
	rl->diff.offset = 0;
	rl_ante_push(rl, rl_post_pop(rl));
	return (0);
}

int		rl_maj_left(t_rl *rl)
{
	if (rl->ante_cursor == rl->prompt)
		return (0);
	rl->diff.type = RL_TCURSORONLY;
	rl->diff.begin = -1;
	rl->diff.offset = 0;
	rl_post_push(rl, rl_ante_pop(rl));
	return (0);
}
