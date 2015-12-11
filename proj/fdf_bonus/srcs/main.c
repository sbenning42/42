/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:38:17 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/11 17:36:54 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		fdf_put_rules(char *name)
{
	ft_printf(FDF_1RULEFMT, name, MSG_RULES, \
			MSG_KESC, MSG_ESC, \
			MSG_KUPDOWN, MSG_UPDOWN);
	ft_printf(FDF_2RULEFMT, \
			MSG_KPLUSMINUS, MSG_PLUSMINUS, \
			MSG_KFIVE, MSG_FIVE);
	return (0);
}

int				ft_err(char *av, char *id, char *msg)
{
	ft_fprintf(2, ERRFMT, av, id, (errno ? strerror(errno) : msg));
	errno = 0;
	return (0);
}

int				main(int ac, char **av)
{
	int			pid;
	int			fd;
	int			i;

	if (!FORK && ac > 2)
		return (ft_err(av[0], "Multi-map", "'#define FORK 1'"));
	fdf_put_rules(av[0]);
	i = 1;
	while (i < ac || ac == 1)
	{
		if ((fd = (ac == 1 ? 0 : open(av[i], O_RDONLY))) < 0)
			ft_err(av[0], av[i], "Can't open file");
		else if (FORK && ((pid = fork()) < 0))
			ft_err(av[0], (ac == 1 ? "Stdin" : av[i]), "Can't fork process");
		else if (pid == 0 || !FORK)
			fdf_mlx(av[0], (ac == 1 ? "Stdin" : av[i]), fd);
		if (fd > 0)
			close(fd);
		if (ac == 1)
			return (0);
		i++;
	}
	return (0);
}
