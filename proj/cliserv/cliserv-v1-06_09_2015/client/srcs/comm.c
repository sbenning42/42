/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 23:05:51 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/10 01:36:45 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void		com_read(int fd, char *buf, size_t size, int sock)
{
	int		ret;

/*	if (DEBUG)
		write(1, "Client: com_read: On read\n", 26);*/
	ret = read(fd, buf, size);
/*	if (DEBUG)
		write(1, "Client: com_read: read end\n", 27);*/
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

	if (DEBUG)
		write(1, "Client: com_write: On write\n", 28);
	ret = write(fd, buf, size);
	if (DEBUG)
		write(1, "Client: com_write: write end\n", 29);
	if (ret < 0)
	{
		write(2, M_WRITE, ft_strlen(M_WRITE));
		shutdown(sock, SHUT_RDWR);
		close(sock);
		exit(0);
	}
}
