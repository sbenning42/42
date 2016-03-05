/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_flush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:43:43 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 14:45:16 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

char		*rl_flush(t_rl *rl)
{
	char	*line;

	write(1, "\n", 1);
	if (!(line = ft_strnew(rl->used - rl->prompt)))
		return (NULL);
	ft_strcpy(line, rl->buffer + rl->prompt);
	ft_strcat(line, rl->buffer + rl->post_cursor);
	*rl_historytrace() = rl->history;
	return (line);
}
