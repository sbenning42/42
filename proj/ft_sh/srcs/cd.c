/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:05:42 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/17 14:47:07 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int	cd_handle_arg_v(\
			char **arg_v)
{
	if (arg_v[1] && !ft_strcmp("~", arg_v[1]))
	{
		free(arg_v[1]);
		if (!(arg_v[1] = ft_strdup(intern_getenv("HOME"))))
			error(Malloc, NULL, EXIT_FAILURE);
	}
	else if (arg_v[1] && !ft_strcmp("-", arg_v[1]))
	{
		free(arg_v[1]);
		if (!(arg_v[1] = ft_strdup(intern_getenv("OLDPWD"))))
			error(Malloc, NULL, EXIT_FAILURE);
	}
	return (1);
}
/*
int			builtin_cd(\
			char **arg_v)
{
	char	cwd_path[FT_SH_CWD_PATH_SIZE + 1];

	ft_bzero((void *)cwd_path, sizeof(char) * (FT_SH_CWD_PATH_SIZE + 1));
	if (!cd_handle_arg_v(arg_v))
		error(Malloc, NULL, EXIT_FAILURE);
	else if (!getcwd(cwd_path, FT_SH_CWD_PATH_SIZE))
	{
		error(Getcwd, NULL, EXIT_SUCCESS);
		return (1);
	}
	else if (chdir((arg_v[1] ? arg_v[1] : intern_getenv("HOME"))))
	{
		error(Chdir, arg_v[1], EXIT_SUCCESS);
		return (1);
	}
	if (!intern_setenv("OLDPWD", cwd_path))
		error(Malloc, NULL, EXIT_FAILURE);
	else if (!getcwd(cwd_path, FT_SH_CWD_PATH_SIZE))
	{
		error(Getcwd, NULL, EXIT_SUCCESS);
		return (1);
	}
	if (!intern_setenv("PWD", cwd_path))
		error(Malloc, NULL, EXIT_FAILURE);
	return (1);
}
*/
static int	getargc(\
			char **arg_v)
{
	int		i;

	i = 0;
	while (*arg_v)
		i++;
	return (i);
}

int			builtin_cd(\
			char **arg_v)
{
	int		o;
	char	e;

	o = get_opt("LP", getargc(arg_v), arg_v, &e);
	if (IS(O_PRIVATE_ERROR, o))
		return (cd_usage(e));
	return (1);
}
