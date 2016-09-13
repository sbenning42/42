/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 09:51:52 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 15:40:50 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"

static int		cd_usage(void)
{
	ft_fprintf(2, "Illegal option -- P & L\nUsage: cd [-L|P] [rep]\n");
	return (-1);
}

static int		cd_opt(int *opt, int ac, char **av)
{
	if ((*opt = ft_getopt(ac, av, "LP")) == -1)
		return (-1);
	if (CD_ISO(*opt, CD_O_P) && CD_ISO(*opt, CD_O_L))
		return (cd_usage());
	return (0);
}

static int		cd_handle(char *path, char *rep, int opt)
{
	char		msg[2048];
	char		*tmp;
	struct stat m_stat;

	tmp = getcwd(NULL, 0);
	if (access(path, F_OK))
	{
		ft_sprintf(msg, "No such directory: %s", rep);
		ft_error(msg);
		return (-1);
	}
	if (chdir(path))
	{
		ft_sprintf(msg, "Permission denied: %s", rep);
		ft_error(msg);
		return (-1);
	}
	ft_setenv("OLDPWD=", ft_getenv("PWD"));
	if (CD_ISO(opt, CD_O_P))
	{
		lstat(path, &m_stat);
		if ((m_stat.st_mode & S_IFLNK) == S_IFLNK)
		{
			tmp = getcwd(NULL, 0);
			ft_setenv("PWD=", tmp);
		}
		else
			ft_setenv("PWD=", path);
	}
	else
		ft_setenv("PWD=", path);
	free(tmp);
	ft_printf("%s\n", ft_getenv("PWD"));
	ft_printf("P : [%s] // L : [%s]\n", tmp, path);
	return (0);
}

int				cd(int ac, char **av)
{
	int			n;
	int			opt;
	char		*rep;
	char		*path;

	if (cd_opt(&opt, ac, av))
		return (-1);
	if (!(n = ft_countarg(ac, av)))
		rep = cd_currentrep();
	else
		rep = av[ac - n];
	if (!(path = cd_cleanpath(rep)))
		return (-1);
	return (cd_handle(path, rep, opt));
}

int				main(void)
{
	char		*av[3];

	av[0] = "minishell";
	av[1] = "..";
	cd(2, av);

	return (0);
}
