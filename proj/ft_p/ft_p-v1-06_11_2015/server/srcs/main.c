/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 20:34:31 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/11 15:41:52 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		hdl_cmd(char r[RSIZE + 1], char s[SSIZE + 1], size_t *size, char **ep)
{
	if (!ft_strncmp(r, "***givprompt", 12))
	{
		ft_strcpy(s, "ft_p $>");
		*size = 7;
	}
	else if (!ft_strncmp(r, "***ls", 5))
	{
		;
	}
	else if (!ft_strncmp(r, "***cd", 5))
	{
		;
	}
	else if (!ft_strncmp(r, "***pwd", 7))
	{
		while (ft_strncmp(*ep, "PWD", 3))
			ep++;
		while (**ep != '=')
			(*ep)++;
		ft_strcpy(s, *ep + 1);
		*size = ft_strlen(s);
	}
	else if (!ft_strncmp(r, "***dl", 5))
	{
		;
	}
	else if (!ft_strncmp(r, "***up", 5))
	{
		;
	}
}

void		ft_p_handle_cli(int sock, char **ep)
{
	t_uchar	rbuf[RSIZE + 1];
	t_uchar	sbuf[SSIZE + 1];
	size_t	size;

/*	while (!g_shutsrv)
	{*/
		ft_bzero(rbuf, RSIZE + 1);
		ft_bzero(sbuf, SSIZE + 1);
		ft_strcpy((char *)sbuf, "ft_p $>\n");

		fd_write(sock, sbuf, 8);
		ft_putendl_fd("Server: Handle: On read", 2);
		fd_read(sock, rbuf, RSIZE, &size);
		ft_putendl_fd("Server: Handle: Out read", 2);
		hdl_cmd((char *)rbuf, (char *)sbuf, &size, ep);
		ft_putendl_fd("Server: Handle: Out hdl_cmd", 2);
		fd_write(sock, sbuf, size);

/*		if (!ft_strcmp((char *)sbuf, "***shut"))
			break ;
	}*/
}

int				main(int ac, char **av, char **ep)
{
	uint32_t	port;

	if (ac > 1)
		port = ft_atoi(av[1]);
	else
		port = 9696;
	srv_handle(srv_init(port), ft_p_handle_cli, ep);
	return (0);
}
