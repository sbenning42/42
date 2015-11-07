/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 13:37:32 by sbenning          #+#    #+#             */
/*   Updated: 2014/12/09 13:44:24 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		To set MY_RLIMIT_NOFILE, type "limit" and get "descriptors" line.
**		Or, use the getrlimit function :
**		man 2 getrlimit
**		#include <sys/ressource.h>
**		int		getrlimit(int ressource, struct rlimit *rlp)
**		And get the "RLIMIT_NOFILE" (current, not max!) of your system.
*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>

# define BUFF_S 1024
# define MY_RLIMIT_NOFILE 256

int		get_next_line(int fd, char **line);

#endif
