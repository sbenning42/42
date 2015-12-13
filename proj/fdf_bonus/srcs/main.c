/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:38:17 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/12 17:02:44 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_put_rules(char *name)
{
	ft_printf(FDF_1RULEFMT, name, MSG_RULES, \
			MSG_KESC, MSG_ESC, \
			MSG_KUPDOWN, MSG_UPDOWN);
	ft_printf(FDF_2RULEFMT, \
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

	ft_snprintf(buf, FDF_SNPRINTF_BS, FDF_FORKFMT, "# define FORK", "1");
	if (!FORK && ac > 2)
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
	sleep(1);
	return (0);
}
