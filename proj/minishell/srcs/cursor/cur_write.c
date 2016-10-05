/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 00:35:42 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/29 20:22:43 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

void	cur_cwrite(char *str, int size, int rsize)
{
	int	len;
	int	rest;
	int	res;
	int	scrco;

	len = cur_get_co() + size;
	scrco = cur_get_scrco() + 1;
	write(1, str, rsize);
	res = len / scrco;
	rest = len % scrco;
	if (!rest)
	{
		if (cur_get_li() + res > cur_get_scrli())
		{
			cur_goto(cur_get_scrli(), 0);
			cur_up_scroll();
		}
		else
			cur_goto(cur_get_li() + res, 0);
		return ;
	}
	cur_maj_li(res);
	cur_set_co(rest);
}

void	cur_write(char *str, int size)
{
	int	len;
	int	rest;
	int	res;
	int	scrco;

	len = cur_get_co() + size;
	scrco = cur_get_scrco() + 1;
	write(1, str, size);
	res = len / scrco;
	rest = len % scrco;
	if (!rest)
	{
		if (cur_get_li() + res > cur_get_scrli())
		{
			cur_goto(cur_get_scrli(), 0);
			cur_up_scroll();
		}
		else
			cur_goto(cur_get_li() + res, 0);
		return ;
	}
	cur_maj_li(res);
	cur_set_co(rest);
}

void	cur_static_write(char *str, int size)
{
	cur_write(str, size);
	cur_go_backward(size);
}
