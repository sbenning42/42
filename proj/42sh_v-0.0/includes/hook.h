/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 15:16:47 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/22 17:51:33 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "libft.h"

# include <termios.h>
# include <signal.h>

/*
***				***	HOOK_INPUT.C	***
*/

int				hook_input(char **buffer);

/*
***				***	HOOK_INIT.C	***
*/

int				hook_open(void);
int				hook_close(void);

/*
***				***	HOOK_LOG.C	***
*/

int				hook_input_log(char *buffer, int fd);

/*
***				***	HOOK_INPUT.C	***
*/

int				hook_input(char **buffer);

#endif
