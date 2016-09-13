/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 09:51:52 by sbenning          #+#    #+#             */
/*   Updated: 2016/06/30 11:00:40 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"

static int		cd_usage(void)
{
 	ft_fprintf(2, "Illegal option -- P & L\nUsage: cd [-L|P] [rep]\n");
 	return (-1);
}

int				main(int ac, char **av)
{
	int			n;
	int     	opt;
	char    	*oldrep;
	char    	*rep;
	char		*tmp;
	char		msg[2048];

	ft_init(av[0]);
	opt = ft_getopt(ac, av, "LP");
	if (!(n = ft_countarg(ac, av)))
		oldrep = cd_currentrep();
	else
		oldrep = av[ac - n];
	if (!(rep = cd_cleanpath(oldrep)))
		ft_exit(1, "Memory allocation fail");
	if (CD_ISO(opt, CD_O_P) && CD_ISO(opt, CD_O_L))
		return (cd_usage());
	tmp = getcwd(NULL, 0);
	if (access(rep, F_OK))
	{
		ft_sprintf(msg, "No such directory: %s", oldrep);
		ft_error(msg);
		return (-1);
	}
	if (chdir(rep))
	{
		ft_sprintf(msg, "Permission denied: %s", oldrep);
		ft_error(msg);
		return (-1);
	}
	ft_setenv("OLDPWD=", ft_getenv("PWD"));
	if (CD_ISO(opt, CD_O_P))
		ft_setenv("PWD=", tmp);
	else
		ft_setenv("PWD=", rep);
	free(tmp);
	ft_printf("%s\n", ft_getenv("PWD"));
	return (0);
}
