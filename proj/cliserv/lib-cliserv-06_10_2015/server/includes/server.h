/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 20:36:52 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/10 17:39:08 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "libft.h"
# include "s_err.h"

# include <sys/socket.h>
# include <netinet/in.h>

typedef struct sockaddr_in	t_addr;

extern int	g_shutsrv;
int			srv_init(uint32_t port);
void		srv_handle(int sock, void (*handle_co)(int, t_addr *, size_t));
void		srv_shut(int sock);

#endif
