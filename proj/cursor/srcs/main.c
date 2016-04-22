/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 14:19:40 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/22 11:55:25 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int				main(int ac, char *av[])
{
	t_hist		hist;
	char		*line;

	ft_initname(av[0]);
	hist_load(&hist);
	while (42)
	{
		line = ft_readline((ac > 1 ? av[1] : "$>"), &hist, RL_ECHO | RL_HISTORY);
		ft_printf("line: [%s]\n", line);
		if (line)
		{
			if (!ft_strcmp(line, "exit"))
			{
				free(line);
				break ;
			}
			free(line);
		}
	}
	hist_save(&hist);
	ft_dlstdel(&hist.list, NULL);
	return (0);	
	(void)ac;
	(void)av;
}
