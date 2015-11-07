/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 22:47:58 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/11 15:25:40 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void		fd_read(int fd, t_uchar buf[BRS_SIZE + 1], size_t size, size_t *nsize)
{
	int		ret;

	ft_putendl("ON REAL READ");
	ret = read(fd, buf, size);
	ft_putendl("OUT REAL READ");
	if (ret < 0)
	{
		write(2, M_READ, ft_strlen(M_READ));
		shutdown(fd, SHUT_RDWR);
		close(fd);
		exit(0);
	}
	buf[*nsize] = '\0';
	*nsize = ret;
	ft_putendl("OUT REAL READ");
}

void		fd_write(int fd, t_uchar buf[BSS_SIZE + 1], size_t size)
{
	int		ret;

	ft_putendl("ON REAL WRT");
	ret = write(fd, buf, size);
	if (ret < 0)
	{
		write(2, M_WRITE, ft_strlen(M_WRITE));
		shutdown(fd, SHUT_RDWR);
		close(fd);
		exit(0);
	}
	ft_putendl("OUT REAL WRT");
}
