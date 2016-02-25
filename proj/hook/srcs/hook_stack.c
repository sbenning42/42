/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:58:43 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/25 16:10:41 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int			hk_push_buffer_to_stack(t_hook_input *hook)
{
	char	c;

	if (hook->buffer.curs == *hook->buffer.acontent)
		return (1);
	hook->buffer.curs -= 1;
	c = *hook->buffer.curs;
	*hook->buffer.curs = 0;
	hook->buffer.stack -= 1;
	*hook->buffer.stack = c;
	return (0);
}

int			hk_push_stack(t_hook_input *hook, char c)
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

int			hk_pop_stack(t_hook_input *hook)
{
	if (hook->buffer.stack >= *hook->buffer.acontent + hook->buffer.max)
		return (1);
	*hook->buffer.stack = 0;
	hook->buffer.stack += 1;
	*hook->buffer.asize -= 1;
	return (0);
}
