/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 20:36:52 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/11 15:23:35 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "libft.h"
# include "s_err.h"

# include <sys/socket.h>
# include <netinet/in.h>

# define RSIZE 512
# define SSIZE 512

typedef struct sockaddr_in	t_addr;

extern int	g_shutsrv;
int			srv_init(uint32_t port);
void		srv_handle(int sock, void (*handle_co)(int, char **), char **ep);
void		srv_shut(int sock);
void		fd_read(int fd, t_uchar buf[RSIZE + 1], size_t size, size_t *nsize);
void		fd_write(int fd, t_uchar buf[SSIZE + 1], size_t size);

#endif
