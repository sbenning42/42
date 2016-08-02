/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:21:53 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/22 18:01:18 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook_private.h"

void				hook_flush_cc(void)
{
	hook_buffer()->flush = 1;
	write(1, "\n", 1);
}

static int			hook_input_eq(char* input, char *iref)
{
	int				i;

	i = -1;
	while (++i < HOOK_PRIVATE_INPUT_SIZE)
	{
		if (input[i] != iref[i])
			return (0);
	}
	return (1);
}

static char			g_input_code[HOOK_PRIVATE_CC][HOOK_PRIVATE_INPUT_SIZE] = {\
	{10, 0, 0, 0}};
static t_input_h	g_input_handler[HOOK_PRIVATE_CC] = {\
	hook_flush_cc};

int			hook_control(char *input)
{
	int		i;

	i = -1;
	while (++i < HOOK_PRIVATE_CC)
	{
		if (hook_input_eq(g_input_code[i], input))
		{
			g_input_handler[i]();
			return (1);
		}
	}
	return (0);
}
