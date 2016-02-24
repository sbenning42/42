/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 10:30:50 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/24 13:15:12 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

t_keymap		*g_kmap = NULL;

int					main(void)
{
	t_hook_input	hk;
	char			*input;

	hk_open(&hk);
	input = hk_input(&hk);
	ft_printf("[%s]\n", input);
	hk_close(&hk);
	return (0);
}
