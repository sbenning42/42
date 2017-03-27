/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:45:42 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/27 12:32:45 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				main(int ac, char **av)
{
	t_parser	*parser;
	t_token		*lst;
	t_token		*drive;
	char		*test;
	char		*tmp;

	if (ac < 2)
		return (0);
	test = av[1];
	tmp = test;
	parser = g_numexpr_grammar;

	reset_posotion();
	lst = ft_parse(parser, &tmp, NULL);
	if (!lst)
		ft_printf("Syntax error on (%d, %d)\n", single_position()->line, single_position()->column);
	drive = lst;
	while (drive)
	{
		ft_printf("(%03d, %03d) ---> %-20s: [%s]\n",\
				drive->position.line, drive->position.column,\
				g_numexpr_grammar[drive->id].key, drive->value);
		drive = drive->next;
	}
	del_token(&lst);

	return (0);
	(void)ac;
	(void)av;
}
