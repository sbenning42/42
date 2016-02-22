/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb42sh.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 11:23:54 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/22 12:24:02 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SB42SH_H
# define SB42SH_H

# include "libft.h"

# include <termios.h>
# include <signal.h>

# define HOOK_INPUT_SIZE 4

extern char		**environ;

/*
***				***	HOOK_INIT.C	***
*/

int				hook_open(void);
int				hook_close(void);

/*
***				***	HOOK_READ.C	***
*/

int				hook_input_read(char *buffer);

/*
***				***	HOOK_LOG.C	***
*/

int				hook_input_log(char *buffer, int fd);

#endif
