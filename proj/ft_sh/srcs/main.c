/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 23:53:55 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/17 16:38:49 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			main(\
			int arg_c, char *arg_v[])
{
	shenv_create(arg_c, arg_v);
	debug_env();
	while (minishell())
		;
	shenv_destroy();
	return (EXIT_SUCCESS);
}
