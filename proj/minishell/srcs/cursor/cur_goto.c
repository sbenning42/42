/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_goto.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:27:36 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/09 11:16:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

int			cur_goto(int li, int co)
{
	char	*s;

	if (!(s = tgetstr("cm", NULL)))
		cur_exit(EXIT_FAILURE, "No \"cm\" capability");
	if (!(s = tgoto(s, co, li)))
		cur_exit(EXIT_FAILURE, "tgoto failure");
	if (tputs(s, 1, cur_put))
		cur_exit(EXIT_FAILURE, "tputs failure");
	cur_set_li(li);
	cur_set_co(co);
	return (0);
}

int			cur_home(void)
{
	cur_tputs("ho");
	cur_set_li(0);
	cur_set_co(0);
	return (0);
}

int			cur_go_forward(int x)
{
	int		len;
	int		scrco;
	int		rest;
	int		res;

	len = cur_get_co() + x;
	scrco = cur_get_scrco() + 1;
	res = len / scrco;
	rest = len % scrco;
	if (!rest)
	{
		if (cur_get_li() + res > cur_get_scrli())
		{
			res = (cur_get_li() + res) - cur_get_scrli();
			cur_goto(cur_get_scrli(), 0);
			while (res--)
				cur_up_scroll();
		}
		else
			cur_goto(cur_get_li() + res, 0);
		return (0);
	}
	cur_goto(cur_get_li() + res, rest);
	return (0);
}

int			cur_go_backward(int x)
{
	int	co;
	int	scrco;
	int	res;
	int	rest;

	scrco = cur_get_scrco() + 1;
	co = cur_get_co();
	if (x <= co)
	{
		cur_xle(x);
		return (0);
	}
	x -= co;
	cur_fle();
	rest = x % scrco;
	res = x / scrco;
	if (!rest)
	{
		cur_xup(res);
		return (0);
	}
	cur_xup(res + 1);
	cur_xri(scrco - rest);
	return (0);
}
