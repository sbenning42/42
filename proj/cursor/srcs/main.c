/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 14:19:40 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/19 10:57:49 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int				main(int ac, char *av[])
{
	char		*line;

	ft_initname(av[0]);
	if (ac > 1)
		line = ft_readline(av[1], RL_ECHO);
	else
		line = ft_readline("$>", 0);
	ft_printf("line: [%s]\n", line);
	if (line)
		free(line);
	return (0);	
}
