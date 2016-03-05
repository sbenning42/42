/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_history_getrl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 13:03:54 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 15:43:49 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_newrl(t_rl *rl)
{
	char	*line;

	rl->real = rl->offset;
	rl->used = rl->prompt;
	rl->ante_cursor = rl->used;
	rl->post_cursor = rl->real;
	if (!(line = ft_strnew(rl->real)))
		return (-1);
	ft_strncpy(line, rl->buffer, rl->prompt);
	ft_memdel((void **)&rl->buffer);
	rl->buffer = line;
	rl->history_cursor = NULL;
	return (0);
}

int		rl_getrl(t_rl *rl)
{
	char	*line;

	if (!rl->history_cursor)
		return (rl_newrl(rl));
	rl->real = (rl->history_cursor->content_size - 1) + rl->offset;
	rl->used = (rl->history_cursor->content_size - 1) + rl->prompt;
	rl->ante_cursor = rl->used;
	rl->post_cursor = rl->real;
	if (!(line = ft_strnew(rl->real)))
		return (-1);
	ft_strncpy(line, rl->buffer, rl->prompt);
	ft_strncat(line, rl->history_cursor->content, rl->history_cursor->content_size);
	ft_memdel((void **)&rl->buffer);
	rl->buffer = line;
	return (0);
}
