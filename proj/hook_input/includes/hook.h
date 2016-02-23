/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 15:16:47 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/23 18:01:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "libft.h"
# include <termios.h>
# include <signal.h>

# define TAB_KEY_SIZE 3
# define POSIX_INPUT_SIZE 6
# define POSIX_INPUT_MAX 4096
# define POSIX_INPUT_STACK 1024

typedef struct			s_hook_buffer
{
	int					flush;
	char				*buffer;
	char				*curs;
	char				stack[POSIX_INPUT_STACK + 1];
	char				*stack_curs;
}						t_hook_buffer;

typedef struct			s_hook_input
{
	struct termios		standard_attr;
	struct termios		hook_attr;
	t_dlist				*inputs;
	t_hook_buffer		buffer;
}						t_hook_input;

typedef int				(*t_handler)(t_hook_input *);

typedef struct			s_keymap
{
	char				key[POSIX_INPUT_SIZE];
	t_handler			handle;
}						t_keymap;
/*
***				***	HOOK_INPUT.C	***
*/

char			*hook_input(t_hook_input *hk);

/*
***				***	HOOK_INIT.C	***
*/

int				hook_init(t_hook_input *hk);
int				hook_open(t_hook_input *hk);
int				hook_close(t_hook_input *hk);

/*
***				***	HOOK_LOG.C	***
*/

int				hook_input_log(int fd, char *buffer);

int				down_arrow_handler(t_hook_input *hk);
int				up_arrow_handler(t_hook_input *hk);
#endif
