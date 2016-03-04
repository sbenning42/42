/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:55:00 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/04 13:39:35 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void				rl_goto(char *buff, size_t from, size_t to)
{
	int				co;
	int				eco;
	int				eli;
	char			c;

	co = tgetnum("co");
	if (ABS((eco = ((from % co) - (to % co)))))
	{
		if (eco > 0)
			c = 'D';
		else
			c = 'C';
		ft_sprintf(buff, "\033[%d%c", ABS(eco), c);
		write(1, buff, ft_strlen(buff));
	}
	if (ABS((eli = ((from / co) - (to / co)))))
	{
		if (eli > 0)
			c = 'A';
		else
			c = 'B';
		ft_sprintf(buff, "\033[%d%c", ABS(eli), c);
		write(1, buff, ft_strlen(buff));
	}
}
/*
void				rl_gofromhome(size_t to)
{
	char			buff[2048];
	int				co;
	size_t			eco;
	size_t			eli;

	co = tgetnum("co");
	eco = to % co;
	eli = to / co;
	ft_bzero((void *)buff, 2048);
	if (eco)
	{
		ft_sprintf(buff, "\033[%dC", eco);
		write(1, buff, ft_strlen(buff));
	}
	if (eli)
	{
		ft_sprintf(buff, "\033[%dB", eli);
		write(1, buff, ft_strlen(buff));
	}
}
*/
size_t				*echo_cursor(void)
{
	static size_t	cursor;

	return (&cursor);
}

void				rl_echo_init(t_rl *rl)
{
	*echo_cursor() = rl->prompt;
	write(1, rl->buffer, rl->prompt);
}

int					myput(int i)
{
	ft_putchar((char)i);
	return (1);
}

void				rl_last_co(size_t offset)
{
	int				co;

	co = tgetnum("co");
	if (!offset || (offset % co))
		return ;
	tm_cap("do");
}

void				rl_echo(t_rl *rl)
{
	char			buff[2048];

	if (rl->begin > 0)
	{
		rl_goto(buff, *echo_cursor(), rl->begin);
		write(1, rl->buffer + rl->begin, rl->diff);
		write(1, rl->buffer + rl->post_cursor, rl->real - rl->post_cursor);
		tm_cap("cd");
		if (ABS(rl->ante_cursor - rl->begin))
			rl_last_co(rl->used);
		rl_goto(buff, rl->used, rl->ante_cursor);
	}
	else
		rl_goto(buff, *echo_cursor(), rl->ante_cursor);
	*echo_cursor() = rl->ante_cursor;
}
