/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_ask.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:20:39 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/28 09:33:46 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

static int	cur_ask_li(void)
{
	char	buf;
	int		li;

	li = 0;
	buf = 0;
	while (buf != ';')
	{
		buf = 0;
		if (read(0, &buf, 1) < 0)
			cur_exit(EXIT_FAILURE, "cur_ask_li: Can't receive li");
		if (ft_isdigit(buf))
			li = li * 10 + (buf - '0');
	}
	return (li - 1);
}

static int	cur_ask_co(void)
{
	char	buf;
	int		co;

	co = 0;
	buf = 0;
	while (buf != 'R')
	{
		buf = 0;
		if (read(0, &buf, 1) < 0)
			cur_exit(EXIT_FAILURE, "cur_ask_co: Can't receive co");
		if (ft_isdigit(buf))
			co = co * 10 + (buf - '0');
	}
	return (co - 1);
}

int			cur_ask_lico(int *li, int *co)
{
	if (!isatty(1))
		return (-1);
	ft_putstr("\033[6n");
	*li = cur_ask_li();
	*co = cur_ask_co();
	return (0);
}
