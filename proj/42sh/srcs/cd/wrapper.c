/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 14:21:16 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/15 14:23:51 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"

char			*getcwd_wrapper(void)
{
	char		*cwd;
	char		msg[1024];

	if ((cwd = getcwd(NULL, 0)))
		return (cwd);
	ft_snprintf(msg, 1024, "Can't get Current Working Dir via SysCall");
	cd_exit(msg);
	return (NULL);
}

int				access_wrapper(char *path, char *rep)
{
	char		msg[1024];

	if (!access(path, F_OK))
		return (0);
	ft_snprintf(msg, 1024, "No such directory: %s", rep);
	cd_exit(msg);
	return (-1);
}

int				chdir_wrapper(char *path, char *rep)
{
	char		msg[1024];

	if (!chdir(path))
		return (0);
	ft_snprintf(msg, 1024, "Permission denied: %s", rep);
	cd_exit(msg);
	return (-1);
}
