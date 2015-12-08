/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:38:17 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/08 03:53:24 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		fdf_put_rules(char *name)
{
	ft_printf("%s:{ss}%s{eoc}\n\n{green}%s{eoc}%s{green}%s{eoc}%s",\
			name, MSG_RULES, MSG_KESC, MSG_ESC, MSG_KUPDOWN, MSG_UPDOWN);
	return (0);
}

int				ft_err(char *av, char *id, char *msg)
{
	ft_fprintf(2, ERRFMT, av, id, (errno ? strerror(ernno) : msg));
	errno = 0;
	return (0);
}

int				main(int ac, char **av)
{
	int			pid;
	int			fd;
	int			i;

	if (~FORK && ac > 2)
		return (ft_err(av[0], "Masterchief", "'#define FORK 0x1'"));
	fdf_put_rules(av[0]);
	i = 1;
	while (i < ac || ac == 1)
	{
		if (((fd = (ac == 1 ? 0 : open(av[i], O_RDONLY))) < 0) || errno)
			ft_err(av[0], av[i], "Can't open file");
		else if (FORK && (((pid = fork()) < 0) || errno))
			ft_err(av[0], (ac == 1 ? "Stdin" : av[i]), "Can't fork process");
		else if (pid == 0 || ~FORK)
			fdf_mlx(av[0], (ac == 1 ? "Stdin" : av[i]), fd);
		if (fd > 0)
			close(fd);
		if (ac == 1)
			return (0);
		i++;
	}
	return (0);
}
