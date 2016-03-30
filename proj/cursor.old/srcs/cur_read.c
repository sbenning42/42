/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 00:35:42 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 09:46:40 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

long int		cur_read(void)
{
	long int	buffer;

	buffer = 0;
	if (read(0, (char *)&buffer, sizeof(buffer)) < 0)
		return (0);
	return (buffer);
}

void			cur_write(char *str, int size)
{
	int			len;
	int			flag;

	flag = 0;
	len = *co() + size;
	if (len % (cur_scrco() + 1) == 0)
		flag = 1;
	write(1, str, size);
	if (flag)
	{
		cur_bli();
		if (*li() == cur_scrli())
			cur_uroll();
		else
			cur_nli();
	}
}
