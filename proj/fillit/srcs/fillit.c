/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/25 10:07:06 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/25 13:18:32 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			put_tetrimino(t_tetrimino t, char c)
{
	int			tmp;
	int			i;

	tmp = 0x1;
	i = 1;
	while (tmp < TETRIMINOEND)
	{
		if (t & tmp)
			write(1, &c, 1);
		else
			write(1, ".", 1);
		if (!(i++ % 4))
			write(1, "\n", 1);
		tmp <<= 0x1;
	}
}
