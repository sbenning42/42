/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 10:30:50 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/24 17:13:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

t_keymap		g_kmap[] = {\
	{0xA, nline_handler},\
	{0x4, exit_handler}\
};

size_t			g_size = 2;

int					main(void)
{
	t_hook_input	hook;

	hook.keymap = g_kmap;
	hook.size = g_size;
	hk_open(&hook, g_kmap, g_size, POSIX_INPUT_OFFSET);
	ft_printf("buffer: [%s]\n", hk_input(&hook));
	hk_close(&hook);
	return (0);
}
