/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 10:30:50 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/23 17:40:39 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int					main(int arg_c, char **arg_v, char **env_p)
{
	t_hook_input	hook;
	char			*input;

	if (hook_open(&hook))
		exit(EXIT_FAILURE);
	input = hook_input(&hook);
	ft_printf("[%s]\n", input);
	if (hook_close(&hook))
		exit(EXIT_FAILURE);
	return (0);
	(void)arg_c;
	(void)arg_v;
	(void)env_p;
}
