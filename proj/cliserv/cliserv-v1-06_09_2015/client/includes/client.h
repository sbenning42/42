/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 22:59:39 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/10 03:29:02 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "libft.h"

# include "c_err.h"

# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
//# include <sleep.h>
# include <errno.h>

# define DEBUG 1
# define SERVER "127.0.0.1"
# define PORT 4444
# define BSS_SIZE 2048
# define BRS_SIZE 512

typedef struct sockaddr_in t_addr;
typedef struct hostent t_host;

t_host		*c_inithost(char *srv);
void		c_initaddr(t_addr *addr, int port, t_host *host, int family);
void		c_getsock(int *sock, t_addr *addr);
void		c_handle_co(int sock, char **ep);
void		com_read(int fd, char *buf, size_t size, int sock);
void		com_write(int fd, char *buf, size_t size, int sock);
void		err_sock(void);
void		err_co(void);
void		cmd_handle(char *d, char *s, char **ep);


#endif
