/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 20:36:52 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/10 03:29:13 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "libft.h"

# include "s_err.h"

# include <sys/socket.h>
# include <netinet/in.h>
# include <signal.h>
# include <errno.h>

# define DEBUG 1
# define PORT 4444
# define BSS_SIZE 512
# define BRS_SIZE 2048

typedef struct sockaddr_in t_addr;

void		s_initaddr(t_addr *addr, uint32_t port, uint32_t inaddr, int family);
void		s_getsock(int *sock, t_addr *addr);
void		s_handle_co(int sock);
void		com_read(int fd, char *buf, size_t size, int sock);
void		com_write(int fd, char *buf, size_t size, int sock);
void		err_sock(void);

#endif
