/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 12:48:53 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/30 17:20:26 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

int			nohome(char *id)
{
	char	msg[1024];

	ft_sprintf(msg, "%s: \" HOME \" undefined\n", id);
	ft_fprintf(2, "%s", msg);
	return (1);
}

int			usage(char *id, char e)
{
	char	msg[1024];

	ft_sprintf(msg, "%s: Usage: %s [-LP] [dest]\n", id, id , e);
	ft_fprintf(2, "%s", msg);
	return (1);
}

char		*getrep(int ac, char **av)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] != '-'||(av[i][0] == '-' && !av[i][1]))
			return (av[i]);
	}
	return (ft_getenv("HOME"));
}

int			main(int ac, char **av, char **ep)
{
	int		o;
	char	e;
	char	*rep;

	ft_init(av[0]);
	if ((o = get_opt("PL", ac, av, &e)) < 0)
		return (usage(av[0], e));
	if (!(rep = getrep(ac, av)))
		return (nohome(av[0]));
	if (rep[0] == '-' && !rep[1])
	{
		rep = ft_getenv("OLDPWD");
	}
	ft_printf("Dest: %s, L: %d, P: %d\n", rep, O_IS(o, O_L), O_IS(o, O_P));
	return (0);
	(void)ep;
}
