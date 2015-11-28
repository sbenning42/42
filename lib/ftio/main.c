/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 21:22:18 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/19 18:01:51 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio.h"

int main(void)
{
	char			buf[FTIO_BS + 1];
	int				ret;

	ftio_init(0);

/*	ret = 1;
	ft_bzero((void *)buf, sizeof(char) * (FTIO_BS + 1));
	while (ret > 0)
	{
		ret = read(0, buf, FTIO_BS);
		if (ret == -1)
		{
			ftio_reset(0);
			return (1);
		}
		if (ft_isprint(*buf) || *buf == '\n')
			ft_printf("%c", *buf);
		else
			ftio_perform(*(long int *)buf);
		ft_bzero((void *)buf, sizeof(char) * (FTIO_BS + 1));
	}
*/
	ret = ftio_read(buf, FTIO_BS);
	write(1, buf, ret);
	ftio_reset(0);
	return (0);
}
