/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:45:42 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/30 17:01:21 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	compile_file(int *fd, char *file)
{
	if ((*fd = open(file, O_RDONLY)) < 0)
		open_error(file);
	else if (asm_compile(*fd, file))
		compile_error(file);
}

int			main(int ac, char **av)
{
	int		*fd;
	int		i;

	proginfo_init(ac, av, NULL, ASM_OPT_CHARSET);
	ac = proginfo()->oarg_c;
	av = proginfo()->oarg_v;
	if (!(fd = ft_memalloc(sizeof(int) * ac)))
		return (-1);
	i = -1;
	while (++i < ac)
		compile_file(fd + i, av[i]);
	i = -1;
	while (++i < ac)
		close(fd[i]);
	return (0);
}
