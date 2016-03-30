/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 14:19:40 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 23:15:56 by sbenning         ###   ########.fr       */
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
		line = ft_readline("$>", RL_ECHO);
	ft_printf("line: [%s]\n", line);
	free(line);
	return (0);
	
//	char		s[1024];
//	int			len;

	ft_initname(av[0]);
	cur_initterm();
	cur_init();

	cur_goto(cur_get_scrli() / 2, cur_get_scrco() / 2);
	sleep(5);
	cur_do();
	sleep(5);

	cur_resetterm();
	return (0);
	(void)ac;/*
	ft_initname(av[0]);
	cur_initterm();
	cur_init();

	int len = ((cur_get_scrco() + 1) * 5) - (cur_get_scrco() / 2) - 127;
	char s[1024];
	ft_memset(s, 'A', len);

	cur_write("zzzzzzzzzz", 10);
	cur_write("zzzzzzzzzz", 10);
	cur_write("yyyyyyyyyy", 10);
	cur_write("zzzzzzzzzz", 10);
	cur_write("zzzzzzzzzp", 10);
	ft_fprintf(2, "li: %d\nco: %d\n", cur_get_li(), cur_get_co());
	cur_static_write(s, len);
	sleep(5);
	ft_fprintf(2, "li: %d\nco: %d\n", cur_get_li(), cur_get_co());
	
	cur_resetterm();
	return (0);
	(void)ac;
*/}
