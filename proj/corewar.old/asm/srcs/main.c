/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 10:40:02 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/23 14:13:38 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				main(int ac, char **av)
{
	int			fd;
	int			i;

	if (ac < 2)
		return (0);
	proginfo_init(ac, av, NULL, O_CHARSET);
	ac = proginfo()->oarg_c;
	av = proginfo()->oarg_v;
	i = -1;
	while (++i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd < 0)
			return (-1);
		ft_printf("\nOpen file `%s`:\n\n", av[i]);
		compile(fd);
		ft_printf("\nClose file `%s`:\n\n", av[i]);
		close(fd);
	}
	return (0);
}
