/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:38:17 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/14 11:12:11 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_put_rules(char *name)
{
	ft_printf(FMT_1RULE, name, MSG_RULES, \
			MSG_KESC, MSG_ESC, \
			MSG_KUPDOWN, MSG_UPDOWN);
	ft_printf(FMT_2RULE, \
			MSG_KPLUSMINUS, MSG_PLUSMINUS, \
			MSG_KFIVE, MSG_FIVE);
	return (0);
}

int			main(int ac, char **av)
{
	char	buf[FDF_SNPRINTF_BS];
	int		pid;
	int		fd;
	int		i;

	ft_snprintf(buf, FDF_SNPRINTF_BS, FMT_FORK, "# define FORK", "1");
	if ((pid = 1) && !FORK && ac > 2)
		return (ft_err(av[0], "Multi-map", buf));
	fdf_put_rules(av[0]);
	i = 0;
	while (++i < ac || ac == 1)
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
	}
	return (0);
}
