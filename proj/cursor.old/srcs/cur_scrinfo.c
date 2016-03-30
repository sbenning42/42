/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_scrinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 17:34:37 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 09:28:36 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

int					*scrco(void)
{
	static int		co;

	return (&co);
}

int					*scrli(void)
{
	static int		li;

	return (&li);
}

int					cur_getscrli(void)
{
	return (*scrli());
}

int					cur_getscrco(void)
{
	return (*scrco());
}

void				cur_setscr(int li, int co)
{
	*scrli() = li;
	*scrco() = co;
}

int					cur_scrli(void)
{
	struct winsize	ws;
	int				li;

	if ((li = cur_getscrli()))
		return (li);
	ioctl(0, TIOCGWINSZ, &ws);
	cur_setscr(ws.ws_row - 1, ws.ws_col - 1);
	return (ws.ws_row - 1);
}

int					cur_scrco(void)
{
	struct winsize	ws;
	int				co;

	if ((co = cur_getscrco()))
		return (co);
	ioctl(0, TIOCGWINSZ, &ws);
	cur_setscr(ws.ws_row - 1, ws.ws_col - 1);
	return (ws.ws_col - 1);
}
