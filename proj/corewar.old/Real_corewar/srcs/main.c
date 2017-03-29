/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:45:42 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/28 18:24:00 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				main(int ac, char **av)
{
	t_parser	*parser;
	t_token		*lst;
	t_token		*drive;
	int			fd;
	int			ret;
	char		*test;
	char		*tmp;

	if (ac < 2)
		return (0);
	parser = g_asm_grammar;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_fprintf(2, ASM_OPEN_ERROR_FMT, av[0], av[1]);
		return (1);
	}
	reset_posotion();
	ft_printf("Parsing %s. . .\n\n", av[1]);
	while ((ret = get_next_line(fd, &test)) > 0)
	{
		if (!*test)
		{
			inc_li_position(1);
			ft_memdel((void **)&test);
			continue ;
		}
		tmp = test;
		lst = ft_parse(parser, &tmp, NULL);
		ft_memdel((void **)&test);
		if (!lst)
		{
			ft_printf("Syntax error on (%d, %d)\n", single_position()->line, single_position()->column);
			return (1);
		}
		drive = lst;
		while (drive)
		{
			ft_printf("(%03d, %03d) ---> %-20s: [%s]\n",\
					drive->position.line, drive->position.column,\
					g_asm_grammar[drive->id].key, drive->value);
			drive = drive->next;
		}
		del_token(&lst);
		inc_li_position(1);
		ft_printf("\n");
	}
	close(fd);
	return (0);
	(void)ac;
	(void)av;
}
