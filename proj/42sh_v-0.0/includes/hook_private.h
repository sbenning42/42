/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_private.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 17:06:48 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/22 17:58:56 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_PRIVATE_H
# define HOOK_PRIVATE_H

# include "hook.h"

# define HOOK_PRIVATE_BUFFER_OFFSET_SIZE 64
# define HOOK_PRIVATE_INPUT_SIZE 4
# define HOOK_PRIVATE_CC 1

typedef void	(*t_input_h)(void);

typedef struct	s_hook_buffer
{
	int			flush;
	size_t		size_max;
	size_t		size;
	size_t		offset;
	char		*buffer;
}				t_hook_buffer;

/*
***				***	HOOK_CONTROL.C	***
*/

t_hook_buffer	*hook_buffer(void);

/*
***				***	HOOK_HANDLE.C	***
*/

int				hook_input_handle(char *input);

/*
***				***	HOOK_CONTROL.C	***
*/

int				hook_control(char *input);

/*
***				***	HOOK_READ.C	***
*/

int				hook_input_read(char *buffer);

#endif
