/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 12:05:22 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/04 12:42:17 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_init(t_rl *rl, int gflag, const char *prompt, char *term)
{
	size_t	offset;

	offset = RL_XMALLOC_SIZE;
	if (tgetent(term, NULL) < 0)
		return(-1);
	rl->prompt = ft_strlen(prompt);
	while (rl->prompt >= offset)
		offset *= 2;
	if (!(rl->buffer = ft_strnew(offset)))
		return (-1);
	rl->offset = offset;
	rl->real = offset;
	ft_strcpy(rl->buffer, prompt);
	rl->used = rl->prompt;
	rl->ante_cursor = rl->prompt;
	rl->begin = rl->prompt;
	rl->post_cursor = rl->real;
	rl->gflag = gflag;
	rl->lflag = 0;
	return (0);
}

int			rl_quit(t_rl *rl)
{
	ft_memdel((void **)&rl->buffer);
	return (0);
}
