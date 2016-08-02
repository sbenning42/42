/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 23:53:55 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/19 12:39:12 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void		handle_env_corruption(\
				int arg_c, char *arg_v[])
{
	static char	*path;
	char		*cp;

	cp = intern_getenv("PATH");
	if (!cp)
		cp = corrupt_path(path);
	if (!intern_getenv("PWD"))
		corrupt_pwd();
	if (!intern_getenv("OLDPWD"))
		corrupt_oldpwd();
	if (!intern_getenv("HOME"))
		corrupt_home();
	if (!path)
		path = intern_getenv("PATH");
	else if (cp && ft_strcmp(path, cp))
	{
		ft_printf("debug: reset env\n");
		shenv_destroy();
		shenv_create(arg_c, arg_v);
		path = intern_getenv("PATH");
		debug_env();
	}
}

int				main(\
				int arg_c, char *arg_v[])
{
	int			finish;

	shenv_create(arg_c, arg_v);
	debug_env();
	finish = 1;
	while (finish)
	{
		handle_env_corruption(arg_c, arg_v);
		finish = minishell();
	}
	shenv_destroy();
	return (EXIT_SUCCESS);
}
