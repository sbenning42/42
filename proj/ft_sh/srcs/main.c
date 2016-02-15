/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 23:53:55 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/15 10:47:55 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			main(\
			int arg_c, char *arg_v[])
{
	shenv_create(arg_c, arg_v);
	if (IS(O_DEBUG, OPT))
		put_shenv();
	while (minishell())
		;
	write(1, "\n", 1);
	shenv_destroy();
	return (EXIT_SUCCESS);
}
