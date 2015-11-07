/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 20:36:52 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/10 04:57:11 by sbenning         ###   ########.fr       */
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

# define PORT 4242
# define BSS_SIZE 512
# define BRS_SIZE 2048

typedef struct sockaddr_in	t_addr;

void		s_handle_co(int sock);
void		com_read(int fd, char *buf, size_t size, int sock);
void		com_write(int fd, char *buf, size_t size, int sock);
void		err_sock(void);

#endif
