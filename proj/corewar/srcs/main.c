/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:45:42 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/29 10:05:22 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			main(int ac, char **av)
{
	int		fd;
	int		i;

	proginfo_init(ac, av, NULL, ASM_OPT_CHARSET);
	ac = proginfo()->oarg_c;
	av = proginfo()->oarg_v;
	i = -1;
	while (++i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) < 0)
		{
			open_error(av[i]);
			continue ;
		}
		else if (asm_compile(fd, av[i]))
			compile_error(fd, av[i]);
		close(fd);
	}
	return (0);
}
