/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 10:30:50 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/24 15:49:12 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int				nl_handle(t_hook_input *hook)
{
	hook->buffer.flag |= 0x1;
	return (0);
}

int				ex_handle(t_hook_input *hook)
{
	hk_close(hook);
	exit(EXIT_SUCCESS);
	return (0);
}

t_keymap		g_kmap[] = {\
	{0xA, nl_handle},\
	{0x3, nl_handle},\
	{0x4, ex_handle}\
};
size_t			g_size = 3;

int					main(void)
{
	t_hook_input	hk;
	char			*input;

	hk.keymap = g_kmap;
	hk.size = g_size;
	hk_open(&hk);
	
	
	
	input = hk_input(&hk);
	
	
	
	/*
	t_dlist *cp = hk.inputs;
	while (cp)
	{
		ft_printf("[%s]\n", (char *)cp->content);
		cp = cp->n;
	}*/
	hk_close(&hk);
	return (0);
}
