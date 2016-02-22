/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_log.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 11:37:54 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/22 12:27:24 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sb42sh.h"

int		hook_input_log(char *buffer, int fd)
{
	int	ret;

	ret = hook_input_read(buffer);
	if (ret != 1)
		return (ret);
	ft_fprintf(fd, "[%d][%d][%d][%d][%d]\n",\
			buffer[0],\
			buffer[1],\
			buffer[2],\
			buffer[3],\
			buffer[4]);
	return (ret);
}
