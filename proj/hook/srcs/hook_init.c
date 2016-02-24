/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 10:37:57 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/24 12:57:53 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void					ft_atexit(int code, char *msg)
{
	ft_fprintf(2, "Error occured: %s\n", msg);
	exit(code);
}

int						hk_expand_buffer(t_hook_input *hook)
{
	char				*tmp;
	char				*tmp_stack;
	size_t				offset;

	tmp = *hook->buffer.acontent;
	tmp_stack = hook->buffer.stack;
	offset = tmp + hook->buffer.max - tmp_stack;
	hook->buffer.max += hook->buffer.offset;
	if (!(*hook->buffer.acontent = ft_strnew(hook->buffer.max + 1)))
		return (1);
	hook->buffer.stack = *hook->buffer.acontent + hook->buffer.max - offset;
	hook->buffer.curs = *hook->buffer.acontent + (hook->buffer.curs - tmp);
	ft_strcpy(*hook->buffer.acontent, tmp);
	ft_strcpy(hook->buffer.stack, tmp_stack);
	ft_memdel((void **)&tmp);
	return (0);
}

int						hk_push_stack_to_buffer(t_hook_input *hook)
{
	char				c;

	if (hook->buffer.curs >= hook->buffer.stack)
		return (1);
	c = *hook->buffer.stack;
	*hook->buffer.stack = 0;
	hook->buffer.stack++;
	*hook->buffer.curs = c;
	hook->buffer.curs++;
	return (0);
}

int						hk_push_buffer_to_stack(t_hook_input *hook)
{
	char				c;

	if (hook->buffer.curs >= hook->buffer.stack)
		return (1);
	hook->buffer.curs--;
	c = *hook->buffer.curs;
	*hook->buffer.curs = 0;
	hook->buffer.stack--;
	*hook->buffer.stack = c;
	return (0);
}

int						hk_push_stack(t_hook_input *hook, char c)
{
	if (hook->buffer.stack > *hook->buffer.acontent + hook->buffer.max)
		return (1);
	if (hook->buffer.curs >= hook->buffer.stack)
		return (1);
	if (*hook->buffer.asize + 1 >= hook->buffer.max)
	{
		if (hk_expand_buffer(hook))
			return (1);
	}
	hook->buffer.stack -= 1;
	*hook->buffer.stack = c;
	*hook->buffer.asize += 1;
	return (0);
}

int						hk_pop_stack(t_hook_input *hook)
{
	if (hook->buffer.stack >= *hook->buffer.acontent + hook->buffer.max)
		return (1);
	*hook->buffer.stack = 0;
	hook->buffer.stack += 1;
	*hook->buffer.asize -= 1;
	return (0);
}

int						hk_pop_buffer(t_hook_input *hook)
{
	if (hook->buffer.curs <= *hook->buffer.acontent || *hook->buffer.asize <= 0)
		return (1);
	*hook->buffer.asize -= 1;
	*hook->buffer.curs = 0;
	hook->buffer.curs--;
	return (0);
}

int						hk_push_buffer(t_hook_input *hook, char c)
{
	if (*hook->buffer.asize + 1 >= hook->buffer.max)
	{
		if (hk_expand_buffer(hook))
			return (1);
	}
	*hook->buffer.curs = c;
	hook->buffer.curs++;
	*hook->buffer.asize += 1;
	return (0);
}

int						hk_reset_buffer(t_hook_input *hook)
{
	t_dlist				*empty;

	if (!(empty = ft_dlstnew_empty(sizeof(char) * (hook->buffer.offset + 1))))
		return (1);
	empty->content_size = 0;
	ft_dlstaddn(&hook->inputs, empty);
	hook->input_curs = empty;
	hook->buffer.acontent = (char **)&empty->content;
	hook->buffer.curs = (char *)empty->content;
	hook->buffer.stack = empty->content + (sizeof(char) * hook->buffer.offset);
	hook->buffer.max = (sizeof(char) * hook->buffer.offset);
	hook->buffer.asize = &empty->content_size;
	return (0);
}

char					*hk_flush(t_hook_input *hook)
{
	char				*cp;

	cp = *hook->buffer.acontent;
	ft_strcpy(hook->buffer.curs, hook->buffer.stack);
	if (hk_reset_buffer(hook))
		return (NULL);
	return (cp);
}

extern t_keymap			*g_kmap;

void					hk_open(t_hook_input *hook)
{
	if (tcgetattr(0, &hook->term.std) < 0)
		ft_atexit(EXIT_FAILURE, "hk_open: tcgetattr");
	hook->term.hook = hook->term.std;
	hook->term.hook.c_lflag &= ~(ICANON | ECHO | ISIG);
	hook->term.hook.c_cc[VTIME] = 0;
	hook->term.hook.c_cc[VMIN] = 1;
	if (tcsetattr(0, TCSANOW, &hook->term.hook) < 0)
		ft_atexit(EXIT_FAILURE, "hk_open: tcsetattr");
	hook->term.lin = 0;
	hook->term.col = 0;
	hook->inputs = NULL;
	hook->keymap = (hook->keymap ? hook->keymap : g_kmap);
	hook->buffer.flag = 0x0;
	hook->buffer.offset = (sizeof(char) * POSIX_INPUT_OFFSET);
	if (hk_reset_buffer(hook))
		ft_atexit(EXIT_FAILURE, "hk_open: hk_reset_buffer");
}

void					hk_close(t_hook_input *hook)
{
	t_dlist				*cp;
	int					fd;

	if (tcsetattr(0, TCSANOW, &hook->term.std) < 0)
	{
		ft_dlstdel(&hook->inputs, NULL);
		ft_atexit(EXIT_FAILURE, "hk_close: tcsetattr");
	}
	if (hook->inputs->n)
	{
		if ((fd = open(HOOK_INPUTS_FILE, O_CREAT | O_WRONLY, 0750)) < 0)
		{
			ft_dlstdel(&hook->inputs, NULL);
			ft_atexit(EXIT_FAILURE, "hk_close: open");
		}
		cp = hook->inputs;
		while (cp)
		{
			write(fd, (char *)cp->content, cp->content_size);
			write(fd, "\n", 1);
			cp = cp->n;
		}
		close(fd);
	}
	ft_dlstdel(&hook->inputs, NULL);
}
