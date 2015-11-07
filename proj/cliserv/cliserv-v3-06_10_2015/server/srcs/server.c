/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 20:39:58 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/10 04:57:09 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		s_handle_co(int sock)
{
	char	rbuf[BRS_SIZE + 1];
	char	sbuf[BSS_SIZE + 1];

	while (42)
	{
		ft_bzero(sbuf, BSS_SIZE);
		ft_bzero(rbuf, BRS_SIZE);
		write(1, "Sending: [- ", 12);
		com_read(0, sbuf, BSS_SIZE, sock);
		write(1, " -]\n", 4);
		com_write(sock, sbuf, ft_strlen(sbuf), sock);
		com_read(sock, rbuf, BRS_SIZE, sock);
		write(1, "Receive: [- ", 12);
		com_write(1, rbuf, ft_strlen(rbuf), sock);
		write(1, " -]\n", 4);
		if (!ft_strcmp(sbuf, "!shut\n"))
			break ;
	}
}
