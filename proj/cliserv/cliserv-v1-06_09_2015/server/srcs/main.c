/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 20:34:31 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/10 01:04:52 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void		listening_sock(int *sock, t_addr *addr)
{
	s_initaddr(addr, PORT, INADDR_ANY, AF_INET);
	s_getsock(sock, addr);
	bind(*sock, (struct sockaddr *)addr, sizeof(*addr));
	listen(*sock, 5);

}

int			main(int ac, char **av)
{
	if (!ac || !av){return (-1);}

	int		ssock;
	t_addr	saddr;
	int		csock;
	t_addr	caddr;
	t_uint	len;
	int		status;

	listening_sock(&ssock, &saddr);
	len = sizeof(caddr);
	while (42)
	{
		if (DEBUG)
			write(1, "Server: main: Top Loop\n", 23);
		csock = accept(ssock, (struct sockaddr *)&caddr, &len);
		if (DEBUG)
			write(1, "Server: main: accept OK\n", 24);
		status = fork();
		if (status == 0)
		{
			if (DEBUG)
				write(1, "Server: main: Top son\n", 22);
			close(ssock);
			s_handle_co(csock);
			if (DEBUG)
				write(1, "Server: main: s_handle_co OK\n", 29);
			shutdown(csock, SHUT_RDWR);
			close(csock);
			if (DEBUG)
				write(1, "Server: main: Kill son\n", 23);
			return (0);
		}
	}
	shutdown(ssock, SHUT_RDWR);
	close(ssock);
	return (0);
}
