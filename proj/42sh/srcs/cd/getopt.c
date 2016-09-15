/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 09:53:23 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/15 15:01:47 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"

static int	usage(char c)
{
	char	msg[1024];

	ft_sprintf(msg, "Illegal option -- %c\nUsage: cd [-L|P] [rep]", c);
	cd_exit(msg);
	return (-1);
}

static int	getoptinarg(char *arg, char *charset)
{
	char	*tmp;
	int		opt;
	int		i;

	opt = 0;
	while (*arg)
	{
		i = 0x1;
		tmp = charset;
		while (*tmp)
		{
			if (*arg == *tmp)
			{
				opt |= i;
				break ;
			}
			i <<= 0x1;
			tmp++;
		}
		if (!*tmp)
			return (usage(*arg));
		arg++;
	}
	return (opt);
}

int			cd_getopt(int ac, char **av, char *charset)
{
	int		opt;
	int		tmp;
	int		i;

	opt = 0;
	i = 0;
	while (++i < ac)
	{
		if (av[i][0] != '-' || !av[i][1])
			break ;
		if ((tmp = getoptinarg(av[i] + 1, charset)) < 0)
			return (-1);
		opt |= tmp;
	}
	return (opt);
}

int			ft_countarg(int ac, char **av)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] != '-' || !av[i][1])
			break ;
	}
	return (ac - i);
}
