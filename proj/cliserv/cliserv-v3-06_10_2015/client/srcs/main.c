/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 23:15:27 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/10 06:32:24 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	initaddr(t_addr *addr, int port, t_host *host, int family)
{
	ft_bzero(addr, sizeof(*addr));
	addr->sin_port = htons(port);
	addr->sin_family = family;
	ft_memcpy(&(addr->sin_addr), host->h_addr, host->h_length);
}

static int	connecting_sock(int *sock, t_addr *addr, char *srv)
{
	int		ret;

	initaddr(addr, PORT, c_inithost(srv), AF_INET);
	c_getsock(sock, addr);
	bind(*sock, (struct sockaddr *)addr, sizeof(*addr));
	ret = connect(*sock, (struct sockaddr *)addr, sizeof(*addr));
	return (ret);
}

int			main(int ac, char **av, char **ep)
{
	int		ssock;
	t_addr	saddr;
	int		ret;

	if (!ac || !av)
		return (-1);
	while (42)
	{
		ret = connecting_sock(&ssock, &saddr, SERVER);
		if (ret < 0)
		{
			shutdown(ssock, SHUT_RDWR);
			close(ssock);
			sleep(15);
			continue ;
		}
		c_handle_co(ssock, ep);
		shutdown(ssock, SHUT_RDWR);
		close(ssock);
		sleep(15);
	}
	return (0);
}
