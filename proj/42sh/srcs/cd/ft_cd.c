/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 14:19:05 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/15 14:46:17 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"

static int		cd_usage(void)
{
	ft_fprintf(2, "Illegal option -- P & L\nUsage: cd [-L|P] [rep]\n");
	return (-1);
}

static int		followlink(char *path, char *rep)
{
	struct stat m_stat;
	char		msg[1024];
	char		*cwd;

	if (lstat(path, &m_stat))
	{
		ft_snprintf(msg, 1024, "Cannot get `stat` of: %s", rep);
		cd_exit(msg);
		return (-1);
	}
	if ((m_stat.st_mode & S_IFLNK) == S_IFLNK)
	{
		if (!(cwd = getcwd_wrapper()))
			return (-1);
		ft_setenv("PWD=", cwd);
		free(cwd);
	}
	else
		ft_setenv("PWD=", path);
	return (0);
}

static int		cd_handle(char *path, char *rep, int opt, int prec)
{
	if (!*path)
		return (0);
	if (access_wrapper(path, rep))
		return (-1);
	if (chdir_wrapper(path, rep))
		return (-1);
	ft_setenv("OLDPWD=", ft_getenv("PWD"));
	if (CD_ISO(opt, CD_O_P))
	{
		if (followlink(path, rep))
			return (-1);
	}
	else
		ft_setenv("PWD=", path);
	if (prec)
		ft_printf("%s\n", ft_getenv("PWD"));
	return (0);
}

static int		cd_opt(int *opt, int ac, char **av)
{
	if ((*opt = cd_getopt(ac, av, "LP")) == -1)
		return (-1);
	if (CD_ISO(*opt, CD_O_P) && CD_ISO(*opt, CD_O_L))
		return (cd_usage());
	return (0);
}

int				ft_cd(int ac, char **av)
{
	int			n;
	int			opt;
	int			prec;
	char		*rep;
	char		*path;

	if (cd_opt(&opt, ac, av))
		return (-1);
	if (!(n = ft_countarg(ac, av)))
		rep = cd_currentrep();
	else
		rep = av[ac - n];
	prec = 0;
	if (!(path = cd_cleanpath(rep, &prec)))
		return (-1);
	return (cd_handle(path, rep, opt, prec));
}
