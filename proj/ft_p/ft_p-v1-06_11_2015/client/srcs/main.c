/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 23:15:27 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/11 15:44:02 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void		hdl_cmd(char *r, char *s, size_t *size)
{
	if (!ft_strcmp(r, "pwd"))
	{
		ft_strcpy(s, "***pwd");
		*size = 6;
	}
	else if (!ft_strncmp(r, "ls ", 3))
	{
		;
	}
	else if (!ft_strncmp(r, "cd ", 3))
	{
		;
	}
	else if (!ft_strncmp(r, "get ", 4))
	{
		;
	}
	else if (!ft_strncmp(r, "put ", 4))
	{
		;
	}
	else if (!ft_strcmp(r, "quit"))
	{
		ft_strcpy(s, "***shut");
		*size = 7;
	}
}

void		handle_co(int sock)
{
	t_uchar	rbuf[BRS_SIZE + 1];
	t_uchar	sbuf[BSS_SIZE + 1];
	t_uchar	buf[B_SIZE + 1];
	size_t	size;

	/*while (42)
	{
		ft_bzero(sbuf, BSS_SIZE + 1);
		ft_bzero(rbuf, BRS_SIZE + 1);
		fd_read(sock, rbuf, BRS_SIZE, &size);
		fd_write(1, rbuf, size);
		ft_putendl("ON READ 0");
		fd_read(0, buf, B_SIZE, &size);
		hdl_cmd((char *)buf, (char *)sbuf, &size);
		fd_write(sock, sbuf, size);
	}*/
	fd_read(sock, rbuf, BRS_SIZE, &size);
	fd_write(1, rbuf, size);
	fd_write(sock, (t_uchar *)"***pwd\n", 7);
}

int			main(int ac, char **av)
{
	int			sock;
	uint32_t	port;
	char		*srv;

	if (ac == 3)
	{
		srv = av[1];
		port = ft_atoi(av[2]);
	}
	else
	{
		srv = "127.0.0.1";
		port = 9696;
	}
	sock = cli_connect(srv, port);
	handle_co(sock);
	shutdown(sock, SHUT_RDWR);
	close(sock);
	return (0);
}
