/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 17:01:38 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/24 21:12:12 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

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
	hook->buffer.flag &= ~HOOK_F_FLUSH;
	return (0);
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

char					*hk_flush(t_hook_input *hook)
{
	char				*cp;

	write(1, "\n", 1);
	cp = *hook->buffer.acontent;
	ft_strcpy(hook->buffer.curs, hook->buffer.stack);
	if (hk_reset_buffer(hook))
		return (NULL);
	return (cp);
}
