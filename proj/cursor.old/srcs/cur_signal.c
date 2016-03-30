/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 09:25:27 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 09:33:53 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

void				cur_resize(int sig)
{
	struct winsize	ws;

	ioctl(0, TIOCGWINSZ, &ws);
	cur_setscr(ws.ws_row - 1, ws.ws_col - 1);
	ft_printf("new li: %d\nnew co: %d\n", cur_scrli(), cur_scrco());
	(void)sig;
}
