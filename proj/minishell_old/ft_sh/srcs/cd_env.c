/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 11:21:26 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/19 11:25:21 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			cdenv(\
			char *nwd_path, char put)
{
	char	*cwd_path;

	if (!(cwd_path = intern_getenv("PWD")))
		cd_error(Unknow, NULL, EXIT_SUCCESS);
	else if (!intern_setenv("OLDPWD", cwd_path))
		cd_error(Malloc, NULL, EXIT_FAILURE);
	else if (chdir(nwd_path))
		cd_error(Chdir, nwd_path, EXIT_SUCCESS);
	else if (!intern_setenv("PWD", constructpwd(nwd_path, cwd_path)))
		cd_error(Malloc, NULL, EXIT_FAILURE);
	else if (put)
		ft_printf((IS(O_COLOR, OPT) ? "{cyan}%s{eoc}\n" : "%s\n"), nwd_path);
	return (1);
}

int			fcdenv(\
			char *nwd_path, char put)
{
	char	*cp;
	char	cwd_path[FT_SH_CWD_PATH_SIZE + 1];

	ft_bzero((void *)cwd_path, sizeof(char) * (FT_SH_CWD_PATH_SIZE + 1));
	if (!(cp = intern_getenv("PWD")))
		cd_error(Unknow, NULL, EXIT_SUCCESS);
	else if (!intern_setenv("OLDPWD", cp))
		cd_error(Malloc, NULL, EXIT_FAILURE);
	else if (chdir(nwd_path))
		cd_error(Chdir, nwd_path, EXIT_SUCCESS);
	else if (!getcwd(cwd_path, FT_SH_CWD_PATH_SIZE))
		cd_error(Getcwd, NULL, EXIT_SUCCESS);
	else if (!intern_setenv("PWD", cwd_path))
		cd_error(Malloc, NULL, EXIT_FAILURE);
	else if (put)
		ft_printf((IS(O_COLOR, OPT) ? "{cyan}%s{eoc}\n" : "%s\n"), cwd_path);
	return (1);
}
