/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 20:20:52 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/09 11:11:36 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

int		cur_all_clr(void)
{
	cur_tputs("cl");
	cur_set_li(0);
	cur_set_co(0);
	return (0);
}

int		cur_line_clr(void)
{
	cur_fle();
	cur_tputs("cd");
	return (0);
}

int		cur_restline_clr(void)
{
	cur_tputs("ce");
	return (0);
}

int		cur_x_clr(int x)
{
	cur_tparm("ec", x);
	return (0);
}

int		cur_from_clr(void)
{
	int	co;
	int	li;

	co = cur_get_co();
	li = cur_get_li();
	cur_restline_clr();
	if (li < cur_get_scrli())
	{
		cur_goto(li + 1, 0);
		cur_line_clr();
		cur_goto(li, co);
	}
	return (0);
}
