/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corrupt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 12:27:48 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/18 14:21:37 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char		*corrupt_path(\
			char *oldpath)
{
	if (!oldpath)
		error(Path_corruption, NULL, EXIT_SUCCESS);
	else
	{
		error(Minim_path_corruption, oldpath, EXIT_SUCCESS);
		if (!intern_setenv("PATH", oldpath))
			error(Malloc, NULL, EXIT_FAILURE);
		return (oldpath);
	}
	return (NULL);
}

void		corrupt_pwd(\
			void)
{
	char	cwd_path[FT_SH_CWD_PATH_SIZE + 1];

	ft_bzero((void *)cwd_path, sizeof(char) * (FT_SH_CWD_PATH_SIZE + 1));
	error(Pwd_corruption, NULL, EXIT_SUCCESS);
	if (!getcwd(cwd_path, FT_SH_CWD_PATH_SIZE))
		error(Getcwd, NULL, EXIT_FAILURE);
	if (!intern_setenv("PWD", cwd_path))
		error(Malloc, NULL, EXIT_FAILURE);
}

void		corrupt_oldpwd(\
			void)
{
	char	*pwd;
	int		is;

	is = 1;
	if (!(pwd = intern_getenv("PWD")))
		is = 0;
	error(Oldpwd_corruption, (is ? pwd : NULL), EXIT_SUCCESS);
	if (!is)
		error(Unknow, "No way to get a valid PWD. Please fix it", EXIT_FAILURE);
	if (!intern_setenv("OLDPWD", pwd))
		error(Malloc, NULL, EXIT_FAILURE);
}

void		corrupt_home(\
			void)
{
	error(Home_corruption, NULL, EXIT_SUCCESS);
}
