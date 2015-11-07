/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 20:39:58 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/10 01:38:02 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		s_initaddr(t_addr *addr, uint32_t port, uint32_t inaddr, int family)
{
	ft_bzero(addr, sizeof(*addr));
	addr->sin_port = htons(port);
	addr->sin_family = family;
	addr->sin_addr.s_addr = htonl(inaddr);
}

void		s_getsock(int *sock, t_addr *addr)
{
	*sock = socket(addr->sin_family, SOCK_STREAM, 0);
	if (*sock < 0)
		err_sock();
}

void		s_handle_co(int sock)
{
	char	rbuf[BRS_SIZE + 1];
	char	sbuf[BSS_SIZE + 1];

	while (42)
	{
		if (DEBUG)
			write(1, "Server: s_handle_co: Top Loop\n", 30);
		ft_bzero(sbuf, BSS_SIZE);
		ft_bzero(rbuf, BRS_SIZE);
		com_read(0, sbuf, BSS_SIZE, sock);
		if (DEBUG)
			write(1, "Server: s_handle_co: Read 0 OK\n", 31);
		com_write(sock, sbuf, ft_strlen(sbuf), sock);
		if (DEBUG)
			write(1, "Server: s_handle_co: Write sock OK\n", 35);
		if (!ft_strcmp(sbuf, "!shut\n"))
			return ;
		com_read(sock, rbuf, BRS_SIZE, sock);
		if (DEBUG)
			write(1, "Server: s_handle_co: Read sock OK\n", 34);
		write(1, "Receive: ", 9);
		com_write(1, rbuf, ft_strlen(rbuf), sock);
		if (DEBUG)
			write(1, "Server: s_handle_co: Write 1 OK\n", 32);
	}
}
