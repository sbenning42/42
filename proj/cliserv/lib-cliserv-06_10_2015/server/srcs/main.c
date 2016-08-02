/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 20:34:31 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/30 15:39:59 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

#define RSIZE 512
#define SSIZE 512

static void	test_co(int sock, t_addr *addr, size_t addrlen)
{
	char	rbuf[RSIZE + 1];
	char	sbuf[SSIZE + 1];
	int		ret;

	ft_strcpy(sbuf, "Test d'envoi de srv");
	if (sizeof(*addr) != addrlen || !addr || sock < 0)
		return ;
	while (!ft_strncmp(rbuf, "!QUIT\n", 6))
	{
		ret = read(sock, rbuf, RSIZE);
		if (ret < 0)
		{
			write(sock, "Srv cannot read anymore\n", 24);
			break ;
		}
		rbuf[ret] = '\0';
		write(1, "recept: ", 8);
		write(1, rbuf, ft_strlen(rbuf));
		write(sock, sbuf, SSIZE);
	}
}

int			main(void)
{
	int		sock;
	int		status;

	sock = srv_init(4242);
	status = fork();
	if (status == 0)
		srv_handle(sock, test_co);
	else
	{
		wait(&status);
		g_shutsrv = 1;
		srv_shut(sock);
	}
	return (0);
}
