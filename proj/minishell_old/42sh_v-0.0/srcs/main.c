/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 10:30:50 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/22 17:13:51 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int					main(int arg_c, char **arg_v, char **env_p)
{
	char			*buffer;

	if (hook_open())
		exit(EXIT_FAILURE);
	if (hook_input(&buffer))
		exit(EXIT_FAILURE);
	ft_printf("%s: Buffer=[%s]\n", arg_v[0], buffer);
	ft_memdel((void **)&buffer);
	if (hook_close())
		exit(EXIT_FAILURE);
	return (0);
	(void)arg_c;
	(void)env_p;
}
