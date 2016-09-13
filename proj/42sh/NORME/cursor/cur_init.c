/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:13:00 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/09 11:14:41 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

int					cur_init_scr(void)
{
	struct winsize	ws;

	ioctl(0, TIOCGWINSZ, &ws);
	cur_set_scrli(ws.ws_row - 1);
	cur_set_scrco(ws.ws_col - 1);
	return (0);
}

int					cur_init_coo(void)
{
	int				li;
	int				co;

	if (cur_ask_lico(&li, &co) < 0)
		return (-1);
	cur_set_li(li);
	cur_set_co(co);
	return (0);
}

int					cur_init(void)
{
	char			*term;
	char			*tmp;
	char			msg[2048];
	int				success;

	if (!(term = ft_getenv("TERM")))
		cur_exit(EXIT_FAILURE, CAP_SPECIFYTERM);
	if ((success = tgetent(NULL, term)) < 0)
		cur_exit(EXIT_FAILURE, CAP_NOACCESSTERM);
	else if (success)
	{
		signal(SIGWINCH, cur_resize);
		tmp = tgetstr("pc", NULL);
		PC = (tmp ? *tmp : 0);
		UP = tgetstr("up", NULL);
		BC = tgetstr("le", NULL);
		cur_init_scr();
		if (cur_init_coo() < 0)
			return (-1);
		return (0);
	}
	ft_sprintf(msg, CAP_UNDEFTERM, term);
	cur_exit(EXIT_FAILURE, msg);
	return (-1);
}
