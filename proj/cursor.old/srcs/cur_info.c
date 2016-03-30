/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:20:39 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 09:37:40 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

static int	stcur_li(void)
{
	char	buf;
	int		li;

	li = 0;
	buf = 0;
	while (buf != ';')
	{
		buf = 0;
		if (read(0, &buf, 1) < 0)
			cur_exit(EXIT_FAILURE, "cur_li: Can't receive li");
		if (ft_isdigit(buf))
		{
			li *= 10;
			li += (buf - '0');
		}
	}
	return (li);
}

static int	stcur_co(void)
{
	char	buf;
	int		co;

	co = 0;
	buf = 0;
	while (buf != 'R')
	{
		buf = 0;
		if (read(0, &buf, 1) < 0)
			cur_exit(EXIT_FAILURE, "cur_co: Can't receive co");
		if (ft_isdigit(buf))
		{
			co *= 10;
			co += (buf - '0');
		}
	}
	return (co);
}

void		cur_lico(int *li, int *co)
{
	int		lco;
	int		lli;

	cur_initterm();
	ft_putstr("\033[6n");
	lli = stcur_li() - 1;
	lco = stcur_co() - 1;
	cur_resetterm();
	if (li)
		*li = lli;
	if (co)
		*co = lco;
}

int			cur_li(void)
{
	return (*li());
}

int			cur_co(void)
{
	return (*co());
}
