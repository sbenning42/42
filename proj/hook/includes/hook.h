/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 15:16:47 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/24 00:03:26 by sbenning         ###   ########.fr       */
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

typedef struct		s_hook_buffer
{
	int				flag;
	char			**acontent;
	char			*curs;
	char			*stack;
	size_t			max;
	size_t			*asize;
	size_t			offset;
}					t_hook_buffer;

typedef struct		s_keymap
{
	int				k_code;
	int				(*k_handle)();
}					t_keymap;

typedef struct		s_termattr
{
	struct termios	std;
	struct termios	hook;
	size_t			lin;
	size_t			col;
}					t_termattr;

typedef struct		s_hook_input
{
	t_termattr		term;
	t_dlist			*inputs;
	t_dlist			*input_curs;
	t_hook_buffer	buffer;
	t_keymap		*keymap;
}					t_hook_input;

typedef int			(*t_handler)(t_hook_input *);

/*
***					***	HOOK_INIT.C	***
*/

void				hk_open(t_hook_input *hook);
void				hk_close(t_hook_input *hook);

/*
***					***	HOOK_INPUT.C	***
*/
/*
char				*hook_input(t_hook_input *hk);
*/
/*
***					***	HOOK_HANDLER_CONF.C	***
*/
/*
int					inser_handler(t_hook_input *hk);
int					suppr_handler(t_hook_input *hk);
int					retarr_handler(t_hook_input *hk);
*/
/*
***					***	HOOK_HANDLER_ARROW.C	***
*/
/*
int					right_handler(t_hook_input *hk);
int					left_handler(t_hook_input *hk);
int					down_handler(t_hook_input *hk);
int					up_handler(t_hook_input *hk);
*/
#endif
