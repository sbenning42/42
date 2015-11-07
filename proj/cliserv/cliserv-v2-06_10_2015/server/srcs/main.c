/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 20:34:31 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/10 04:57:08 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	initaddr(t_addr *addr, uint32_t port, uint32_t inaddr, int family)
{
	ft_bzero(addr, sizeof(*addr));
	addr->sin_port = htons(port);
	addr->sin_family = family;
	addr->sin_addr.s_addr = htonl(inaddr);
}

static void	getsock(int *sock, t_addr *addr)
{
	*sock = socket(addr->sin_family, SOCK_STREAM, 0);
	if (*sock < 0)
		err_sock();
}

static void	listening_sock(int *sock, t_addr *addr)
{
	initaddr(addr, PORT, INADDR_ANY, AF_INET);
	getsock(sock, addr);
	bind(*sock, (struct sockaddr *)addr, sizeof(*addr));
	listen(*sock, 5);
}

int			main(void)
{
	int		ssock;
	t_addr	saddr;
	int		csock;
	t_addr	caddr;
	t_uint	len;

	listening_sock(&ssock, &saddr);
	len = sizeof(caddr);
	while (42)
	{
		write(1, "Server: Waiting for connection\n", 31);
		csock = accept(ssock, (struct sockaddr *)&caddr, &len);
		write(1, "Server: Connected!\n", 19);
		if (fork() == 0)
		{
			close(ssock);
			s_handle_co(csock);
			shutdown(csock, SHUT_RDWR);
			close(csock);
			return (0);
		}
	}
	shutdown(ssock, SHUT_RDWR);
	close(ssock);
	return (0);
}
