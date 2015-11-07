/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 23:07:08 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/11 15:32:08 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_host		*inithost(char *srv)
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

static int	getsock()
{
	int		sock;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0)
		err_sock();
	return (sock);
}

static void	initaddr(t_addr *addr, int port, t_host *host)
{
	ft_bzero(addr, sizeof(*addr));
	addr->sin_port = htons(port);
	addr->sin_family = AF_INET;
	ft_memcpy(&(addr->sin_addr), host->h_addr, host->h_length);
}

int			cli_connect(char *srv, uint32_t port)
{
	int		ret;
	int		sock;
	t_addr	addr;

	initaddr(&addr, port, inithost(srv));
	sock = getsock();
	/*ret = bind(sock, (struct sockaddr *)&addr, sizeof(addr));
	if (ret < 0)
		err_bind();*/
	ret = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
	if (ret < 0)
		err_co();
	return (sock);
}
