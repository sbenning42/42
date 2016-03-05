/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:55:00 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 13:53:57 by sbenning         ###   ########.fr       */
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

int					rl_checkperf(size_t size, size_t *len)
{
	static int		flag;
	int				co;

	co = tgetnum("co");
	*len = (size_t)co;
	if ((((int)size / co) < (tgetnum("li") - 1)) && !flag)
		return (1);
	if (flag)
		*len = 0;
	flag = 1;
	return (0);
}

void				rl_echo(t_rl *rl)
{
	char			buff[2048];
	size_t			len;

	if (!rl_checkperf(rl->used, &len))
	{
		if (len)
			ft_fprintf(1, "%*.*s", len, len, "...[Echo stop here... but line still saving input ;)]");
		return ;
	}
	if (rl->diff.type == RL_TCURSORONLY)
		rl_goto(buff, *echo_cursor(), rl->ante_cursor);
	else
	{
		rl_goto(buff, *echo_cursor(), rl->diff.begin);
		tm_cap("cd");
		if (rl->diff.type == RL_TAPPEND)
			write(1, rl->buffer + rl->diff.begin, rl->diff.offset);
		if (rl->real != rl->post_cursor)
		{
			write(1, rl->buffer + rl->post_cursor, rl->real - rl->post_cursor);
			rl_last_co(rl->used);
		}
		rl_goto(buff, rl->used, rl->ante_cursor);
	}
	*echo_cursor() = rl->ante_cursor;
}
