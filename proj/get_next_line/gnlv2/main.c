/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:03:17 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/20 15:25:28 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include "get_next_line.h"
#include <fcntl.h>

int 		main(int ac, char **av)
{
	if (ac > 2)
	{
		ft_fprintf(2, "%s: {red}%s{eoc}\n", av[0], "To many args");
		return (0);
	}
	
	
	
	int		fd;

	if (ac < 2)
		fd = 0;
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
		{
			perror(av[0]);
			return (1);
		}
	}

	
	
	
	char	*line;
	int		ret;

	ret = 1;
	while (42)
	{
		ret = get_next_line(fd, &line);
		if (ret == 0)
			break ;
		else if (ret == -1)
		{
			ft_fprintf(2, "%s: {red}%s{eoc}\n", av[0], "gnl return -1");
			break ;
		}
		else
			ft_printf("%s: [%s]\n", av[0], line);
		ft_memdel((void **)&line);
	}
	ft_printf("%s: %s\n", av[0], "Job is done");
	if (fd > 0)
		close(fd);
	return (0);
}


















