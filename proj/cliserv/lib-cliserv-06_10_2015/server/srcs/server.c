/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 20:39:58 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/10 17:58:09 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int			g_shutsrv = 0;

static int	initaddr(t_addr *addr, uint32_t port)
{
	int		sock;

	ft_bzero(addr, sizeof(*addr));
	addr->sin_port = htons(port);
	addr->sin_family = AF_INET;
	addr->sin_addr.s_addr = htonl(INADDR_ANY);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0)
		err_sock();
	return (sock);
}

int			srv_init(uint32_t port)
{
	t_addr	addr;
	int		sock;
	int		ret;

	sock = initaddr(&addr, port);
	ret = bind(sock, (struct sockaddr *)&addr, sizeof(addr));
	if (ret < 0)
		err_bind();
	ret = listen(sock, 5);
	if (ret < 0)
		err_listen();
	return (sock);
}

void		srv_shut(int sock)
{
	shutdown(sock, SHUT_RDWR);
	close(sock);
}

void		srv_handle(int sock, void (*handle_co)(int, t_addr *, size_t))
{
	t_uint	len;
	t_addr	addr;
	int		c_sock;

	len = sizeof(addr);
	while (!g_shutsrv)
	{
		ft_putendl_fd("Server: Son: Waiting for connection", 2);
		c_sock = accept(sock, (struct sockaddr *)&addr, &len);
		if (c_sock < 0)
			err_accept();
		else if (fork() == 0)
		{
			close(sock);
			handle_co(c_sock, &addr, len);
			srv_shut(c_sock);
			return ;
		}
		else
			srv_shut(c_sock);
	}
	srv_shut(sock);
}
