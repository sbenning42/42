/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 10:37:57 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/23 16:52:13 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook_private.h"

int						hook_init(t_hook_input *hk)
{
	t_dlist				*elem;

	elem = ft_dlstnew_empty(sizeof(char) * (POSIX_INPUT_MAX + 1));
	if (!elem)
		return (1);
	ft_dlstaddn(&hk->inputs, elem);
	hk->buffer.flush = 0;
	hk->buffer.buffer = (char *)elem->content;
	hk->buffer.curs = hk->buffer.buffer;
	hk->buffer.stack_curs = hk->buffer.stack + POSIX_INPUT_STACK;
	ft_bzero((void *)hk->buffer.stack, sizeof(char) * POSIX_INPUT_STACK + 1);
	return (0);
}

int						hook_open(t_hook_input *hk)
{
	hk->inputs = NULL;
	if (hook_init(hk))
		return (1);
	if (tcgetattr(0, &hk->standard_attr) < 0)
		return (1);
	hk->hook_attr = hk->standard_attr;
	hk->hook_attr.c_lflag &= ~(ICANON | ECHO | ISIG);
	hk->hook_attr.c_cc[VTIME] = 0;
	hk->hook_attr.c_cc[VMIN] = 1;
	if (tcsetattr(0, TCSANOW, &hk->hook_attr) < 0)
		return (1);
	return (0);
}

int						hook_close(t_hook_input *hk)
{
	ft_dlstdel(&hk->inputs, NULL);
	if (tcsetattr(0, TCSANOW, &hk->standard_attr))
		return (1);
	return (0);
}
