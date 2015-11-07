/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 23:07:08 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/10 02:45:25 by sbenning         ###   ########.fr       */
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

void		c_initaddr(t_addr *addr, int port, t_host *host,  int family)
{
	ft_bzero(addr, sizeof(*addr));
	addr->sin_port = htons(port);
	addr->sin_family = family;
	ft_memcpy(&(addr->sin_addr), host->h_addr, host->h_length);
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
		if (DEBUG)
			write(2, "Client: c_handle_co: Top Loop\n", 30);
		ft_bzero(sbuf, BSS_SIZE);
		ft_bzero(rbuf, BRS_SIZE);
		com_read(sock, rbuf, BRS_SIZE, sock);
		if (DEBUG)
			write(2, "Client: c_handle_co: Read sock OK\n", 34);
		write(1, "\nReceive: ", 10);
		com_write(1, rbuf, ft_strlen(rbuf), sock);
		if (DEBUG)
			write(2, "Client: c_handle_co: Write 1 OK\n", 33);
		cmd_handle(sbuf, rbuf, ep);
		if (DEBUG)
			write(2, "Client: c_handle_co: Handle OK\n", 34);
		write(1, "\nSend: [- ", 10);
		com_write(2, sbuf, ft_strlen(sbuf), sock);
		write(1, " -]\n", 4);
		if (DEBUG)
			write(2, "Client: c_handle_co: Write 1 OK\n", 35);
		com_write(sock, sbuf, ft_strlen(sbuf), sock);
		if (!ft_strncmp("!shut\n", rbuf, 6))
			break ;
		if (DEBUG)
			write(2, "Client: c_handle_co: Write sock OK\n", 38);
	}
}
