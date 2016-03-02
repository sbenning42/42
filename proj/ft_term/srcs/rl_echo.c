/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:55:00 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/02 15:07:32 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

t_rl				*echo_rl(void)
{
	static t_rl		rl;

	return (&rl);
}

void				rl_clear(size_t len)
{
	char			cl[RL_CLEAR_SIZE] = RL_CL_INIT;

	if (len < RL_CLEAR_SIZE)
		write(1, cl, len);
	else
	{
		while (len > 0)
		{
			len -= RL_CLEAR_SIZE;
			write(1, cl, RL_CLEAR_SIZE);
		}
	}
}

void				rl_echo_init(t_rl *rl)
{
	*echo_rl() = *rl;
	write(1, rl->buffer, rl->prompt);
}

void				rl_echo(t_rl *rl)
{
	t_rl			lastrl;
	size_t			cl_zone;
	char			move[1024];

	lastrl = *echo_rl();
	cl_zone = 0;
	if (lastrl.used > rl->used)
		cl_zone = lastrl.used - rl->used;
	if (rl->ante_cursor >= lastrl.ante_cursor)
		write(1, rl->buffer + lastrl.ante_cursor, rl->ante_cursor - lastrl.ante_cursor);
	else
	{
		ft_sprintf(move, "\033[%dD", lastrl.ante_cursor - rl->ante_cursor);
		write(1, move, ft_strlen(move));
		write(1, rl->buffer + lastrl.ante_cursor, ft_strlen(rl->buffer + lastrl.ante_cursor));
	}
	tm_cap("sc");
	write(1, rl->buffer + rl->post_cursor, rl->real - rl->post_cursor);
	if (cl_zone)
		rl_clear(cl_zone);
	tm_cap("rc");
	*echo_rl() = *rl;
}
