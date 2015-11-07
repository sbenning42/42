/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 23:15:27 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/10 04:12:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int		connecting_sock(int *sock, t_addr *addr, char *srv)
{
	int			ret;

	c_initaddr(addr, PORT, c_inithost(srv), AF_INET);
	if (DEBUG)
		write(2, "Client: Connecting: Addr initialized\n", 37);
	c_getsock(sock, addr);
	bind(*sock, (struct sockaddr *)addr, sizeof(*addr));
	if (DEBUG)
		write(2, "Client: Connecting: Sock & bind OK\n", 35);
	ret = connect(*sock, (struct sockaddr *)addr, sizeof(*addr));
	if (ret < 0)
		err_co();
	if (DEBUG)
		write(2, "Client: Connecting: Client connected\n", 36);
	return (ret);
}

int			main(int ac, char **av, char **ep)
{
	if (!ac || !av){return (-1);}

	int		ssock;
	t_addr	saddr;
	int		ret;

	while (42)
	{
		ret = connecting_sock(&ssock, &saddr, SERVER);
		if (ret < 0)
		{
			shutdown(ssock, SHUT_RDWR);
			close(ssock);		
			write(2, "IN_SLEEP\n", 9);
			sleep(15);
			write(2, "OUT_SLEEP\n", 10);
			continue ;
		}
		if (DEBUG)
			write(2, "Client: main: Client connected\n", 30);
		c_handle_co(ssock, ep);
		if (DEBUG)
			write(2, "Client: main: s_handle_co OK\n", 29);
		shutdown(ssock, SHUT_RDWR);
		write(1, "IN_SLEEP\n", 9);
		sleep(15);
		write(1, "OUT_SLEEP\n", 10);
	}
	return (0);
}
