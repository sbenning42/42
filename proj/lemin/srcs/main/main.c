/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:19:21 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/09 14:23:43 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	lemin_loop(int file_count)
{
	char	*file_name;
	int		fd;
	int		i;

	i = -1;
	while (++i < file_count)
	{
		file_name = proginfo()->oarg_v[i];
		fd = open(file_name, O_RDONLY);
		if (fd < 0)
		{
			ft_fprintf(2, FMT_EOPEN, proginfo()->name, file_name);
			continue ;
		}
		lemin(fd);
		close(fd);
	}
}

int			main(int ac, char **av, char **ep)
{
	int		file_count;

	proginfo_init(ac, av, ep, CS_O);
	file_count = proginfo()->oarg_c;
	if (!file_count)
		lemin(0);
	else
		lemin_loop(file_count);
	return (0);
}
