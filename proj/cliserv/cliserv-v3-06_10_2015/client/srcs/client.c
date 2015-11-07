/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 23:07:08 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/10 06:37:51 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_host		*c_inithost(char *srv)
{
	t_host	*host;

	host = gethostbyname(srv);
	if (host == NULL)
		exit(0);
	return (host);
}

void		c_getsock(int *sock, t_addr *addr)
{
	*sock = socket(addr->sin_family, SOCK_STREAM, 0);
}

void		c_handle_co(int sock, char **ep)
{
	char	rbuf[BRS_SIZE + 1];
	char	sbuf[BSS_SIZE + 1];

	while (42)
	{
		ft_bzero(sbuf, BSS_SIZE);
		ft_bzero(rbuf, BRS_SIZE);
		com_read(sock, rbuf, BRS_SIZE, sock);
		cmd_handle(sbuf, rbuf, ep);
		com_write(sock, sbuf, ft_strlen(sbuf), sock);
		if (!ft_strncmp("!shut\n", rbuf, 6))
			break ;
	}
}
