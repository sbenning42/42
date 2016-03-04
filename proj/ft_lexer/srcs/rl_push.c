/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:30:43 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/04 11:09:54 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_ante_push(t_rl *rl, int code)
{
	if (rl->used + 1 >= rl->real)
	{
		if (rl_expand(rl) < 0)
			return (-1);
	}
	rl->buffer[rl->ante_cursor] = (char)code;
	rl->ante_cursor += 1;
	rl->used += 1;
	return (0);
}

int		rl_post_push(t_rl *rl, int code)
{
	if (rl->used + 1 >= rl->real)
	{
		if (rl_expand(rl) < 0)
			return (-1);
	}
	rl->post_cursor -= 1;
	rl->buffer[rl->post_cursor] = (char)code;
	rl->used += 1;
	return (0);
}
