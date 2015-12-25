/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 02:20:50 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/20 02:39:05 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

int			main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
		{
			perror(av[0]);
			return (errno);
		}
	}
	else
		fd = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ft_printf("%s: [{cyan}%s{eoc}]\n", av[0], line);
		ft_memdel((void **)&line);
	}
	ft_printf("%s: %s\n", av[0], "Job done");
	return (0);
}
