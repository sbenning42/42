/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 22:47:58 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/10 04:57:10 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		com_read(int fd, char *buf, size_t size, int sock)
{
	int		ret;

	ret = read(fd, buf, size);
	if (ret < 0)
	{
		write(2, M_READ, ft_strlen(M_READ));
		shutdown(sock, SHUT_RDWR);
		close(sock);
		exit(0);
	}
	buf[ret] = '\0';
}

void		com_write(int fd, char *buf, size_t size, int sock)
{
	int		ret;

	ret = write(fd, buf, size);
	if (ret < 0)
	{
		write(2, M_WRITE, ft_strlen(M_WRITE));
		shutdown(sock, SHUT_RDWR);
		close(sock);
		exit(0);
	}
}
