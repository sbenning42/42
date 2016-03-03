/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:55:00 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/03 12:02:37 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void				rl_gotohome(size_t from)
{
	char			buff[2048];
	int				co;
	size_t			eco;
	size_t			eli;

	co = tgetnum("co");
	eco = from % co;
	eli = from / co;
	if (eli)
	{
		ft_sprintf(buff, "\033[%dA", eli);
		eco -= eli;
	}
	if (eco)
	{
		if (eli)
			ft_sprintf(buff + ft_strlen(buff), "%s\033[%dD", buff, eco);
		else
			ft_sprintf(buff, "\033[%dD", eco);
	}
	if (eco || eli)
		write(1, buff, ft_strlen(buff));
}

void				rl_gofromhome(size_t to)
{
	char			buff[2048];
	int				co;
	size_t			eco;
	size_t			eli;

	co = tgetnum("co");
	eco = to % co;
	eli = to / co;
	if (eco)
		ft_sprintf(buff, "\033[%dC", eco);
	if (eli)
	{
		if (eco)
			ft_sprintf(buff + ft_strlen(buff), "%s\033[%dB", buff, eli);
		else
			ft_sprintf(buff, "\033[%dB", eli);
	}
	if (eco || eli)
		write(1, buff, ft_strlen(buff));
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

void				rl_echo(t_rl *rl)
{

	size_t			lastcursor;

	lastcursor = *echo_cursor();
	rl_gotohome(lastcursor);
	write(1, rl->buffer, rl->ante_cursor);
	write(1, rl->buffer + rl->post_cursor, rl->real - rl->post_cursor);
	tm_cap("cd");
	rl_gotohome(rl->used);
//	rl_gofromhome(rl->ante_cursor);
/*	if (!(rl->ante_cursor % tgetnum("co")))
		tm_cap("do");
*/	*echo_cursor() = rl->ante_cursor;
}
