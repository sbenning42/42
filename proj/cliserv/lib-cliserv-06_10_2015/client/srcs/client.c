/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 23:07:08 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/10 05:09:03 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_host		*c_inithost(char *srv)
{
	t_host	*host;

	host = gethostbyname(srv);
	if (host == NULL)
	{
		write(2, "Client: Gethost fail\n", 21);
		exit(0);
	}
	return (host);
}

void		c_getsock(int *sock, t_addr *addr)
{
	*sock = socket(addr->sin_family, SOCK_STREAM, 0);
	if (*sock < 0)
		err_sock();
}

void		c_handle_co(int sock, char **ep)
{
	char	rbuf[BRS_SIZE + 1];
	char	sbuf[BSS_SIZE + 1];

	while (42)
	{
		ft_bzero(sbuf, BSS_SIZE);
		ft_bzero(rbuf, BRS_SIZE);
		com_read(sock, rbuf, BRS_SIZE, sock);
		write(1, "\nReceive: ", 10);
		com_write(1, rbuf, ft_strlen(rbuf), sock);
		cmd_handle(sbuf, rbuf, ep);
		write(1, "\nSend: [- ", 10);
		com_write(2, sbuf, ft_strlen(sbuf), sock);
		write(1, " -]\n", 4);
		com_write(sock, sbuf, ft_strlen(sbuf), sock);
		if (!ft_strncmp("!shut\n", rbuf, 6))
			break ;
	}
}
