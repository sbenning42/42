/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 15:16:47 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/25 14:43:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "libft.h"
# include <term.h>
# include <termios.h>
# include <signal.h>
# include <fcntl.h>

# define POSIX_INPUT_OFFSET 4096
# define POSIX_INPUT_SIZE 6
# define HOOK_INPUTS_FILE "inputs.list"

# define IS_PRINT(X) (X > 0x1f && X < 0x7f)
# define ISBIT(X, Y) (((X & Y) == Y) ? 1 : 0)
# define HOOK_F_FLUSH 0x1
# define HOOK_FLUSH ISBIT(hook->buffer.flag, HOOK_F_FLUSH)

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
	size_t			size;
}					t_hook_input;

typedef int			(*t_handler)(t_hook_input *);

extern t_keymap		g_kmap[];
extern size_t		g_size;

/*
***					***	HOOK_INIT.C	***
*/

void				hk_open(t_hook_input *hook, t_keymap *kmap,\
							size_t size, size_t offset);
void				hk_close(t_hook_input *hook);
char				*hk_input(t_hook_input *hook);

/*
***					***	HOOK_MANAGE.C	***
*/

char				*hk_flush(t_hook_input *hook);
int					hk_expand_buffer(t_hook_input *hook);
int					hk_reset_buffer(t_hook_input *hook);

/*
***					***	HOOK_BUFFER.C	***
*/

int					hk_push_buffer_to_stack(t_hook_input *hook);
int					hk_push_buffer(t_hook_input *hook, char c);
int					hk_pop_buffer(t_hook_input *hook);

/*
***					***	HOOK_STACK.C	***
*/

int					hk_pop_stack(t_hook_input *hook);
int					hk_push_stack(t_hook_input *hook, char c);
int					hk_push_stack_to_buffer(t_hook_input *hook);

/*
***					***	HOOK_HANDLER_CONF.C	***
*/

int					exit_handler(t_hook_input *hook);
int					nline_handler(t_hook_input *hook);
int					retarr_handler(t_hook_input *hook);
int					suppr_handler(t_hook_input *hook);
int					inser_handler(t_hook_input *hook);

/*
***					***	HOOK_HANDLER_ARROW.C	***
*/

int					right_handler(t_hook_input *hook);
int					left_handler(t_hook_input *hook);
int					up_handler(t_hook_input *hook);
int					down_handler(t_hook_input *hook);

/*
***					***	HOOK_OUTPUT.C
*/

void				hk_output(t_hook_input *hook);

#endif
