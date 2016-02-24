/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:52:01 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/24 16:59:26 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

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
