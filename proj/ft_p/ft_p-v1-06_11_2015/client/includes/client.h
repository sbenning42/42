/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 22:59:39 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/11 15:23:27 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "libft.h"
# include "c_err.h"

# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <errno.h>

# define B_SIZE 512
# define BSS_SIZE 512
# define BRS_SIZE 512

typedef struct sockaddr_in	t_addr;
typedef struct hostent		t_host;

int			cli_connect(char *srv, uint32_t port);
void		fd_read(int fd, t_uchar buf[BRS_SIZE + 1], size_t size, size_t *nsize);
void		fd_write(int fd, t_uchar buf[BSS_SIZE + 1], size_t size);
void		err_sock(void);
void		err_bind(void);
void		err_co(void);

#endif
