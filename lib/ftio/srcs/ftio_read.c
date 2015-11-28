/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftio_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 17:49:57 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/19 18:10:28 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio.h"

int		ftio_read(char *buf, size_t size)
{
	char	key[FTIO_BS + 1];
	int	ret;
	int	offset;

	offset = 0;
	while (offset < size)
	{
		ret = read(ftio_env()->fd, key, FTIO_BS);
		if (ret < 0)
			return (-1);
		else if (!ret)
			break ;
		offset += ftio_env()->perform(buf, key, ret);
	}
	return (offset);
}
