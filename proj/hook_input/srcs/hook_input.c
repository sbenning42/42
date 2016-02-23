/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:8:05 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/23 18:18:13 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook_private.h"

void				hook_handle_output(t_hook_input *hk)
{
	(void)hk;
/*	char			stack_return[POSIX_INPUT_STACK + 1];
	size_t			offset;

	offset = hk->buffer.curs - hk->buffer.buffer;
	write(1, hk->buffer.buffer, offset);
	offset = (hk->buffer.stack + POSIX_INPUT_STACK) - hk->buffer.stack_curs;
	write(1, hk->buffer.stack_curs, offset);
	ft_memset((void *)stack_return, '\b', offset);
	write(1, stack_return, offset);
*/}

static t_keymap			g_keymap[TAB_KEY_SIZE] = {\
	{{27, 91, 65, 0, 0, 0}, up_arrow_handler},\
	{{27, 91, 66, 0, 0, 0}, down_arrow_handler},\
	{{0, 0, 0, 0, 0, 0}, NULL}\
};

int					hook_handle_input(t_hook_input *hk)
{
	if (ft_isprint(hk->buffer.curs[0]))
		hk->buffer.curs++;
	else if (hk->buffer.curs[0] == 10)
	{
		hk->buffer.curs[0] = 0;
		hk->buffer.curs--;
		hk->buffer.flush = 1;
	}
	else
	{
		int	i = -1;
		while (++i < TAB_KEY_SIZE)
		{
			if (!ft_memcmp(g_keymap[i].key, hk->buffer.curs, POSIX_INPUT_SIZE))
				return (g_keymap[i].handle(hk));
		}
	}
	return (0);
}

char				*hook_input(t_hook_input *hk)
{
	int				ret;
	size_t			offset;
	char			*buffer;

	offset = hk->buffer.curs - hk->buffer.buffer;
	while (offset + POSIX_INPUT_SIZE < POSIX_INPUT_MAX)
	{
		ret = read(0, hk->buffer.curs, POSIX_INPUT_SIZE);
		if (ret < 0)
			continue ;
		hk->buffer.curs[ret] = 0;
		char *cp = hk->buffer.curs;
		ft_printf("[%d][%d][%d][%d][%d][%d]\n", (int)cp[0], (int)cp[1], (int)cp[2], (int)cp[3], (int)cp[4], (int)cp[5]);
		if (hook_handle_input(hk))
			return (NULL);
		hook_handle_output(hk);
		if (hk->buffer.flush)
		{
			buffer = hk->buffer.buffer;
			hook_init(hk);
			return (buffer);
		}
		offset = hk->buffer.curs - hk->buffer.buffer;
	}
	return (NULL);
}
