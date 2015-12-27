/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/25 10:14:11 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/27 15:06:24 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_err(char *av, char *id, char *msg, int rvalue)
{
	ft_fprintf(2, "%s: %s: %s\n", av, id, msg);
	return (rvalue);
}

int				main(int ac, char **av)
{
	t_tetrimino	*tetrimino_set;
	int			i;
	char		c;

	if (ac != 2)
		return (ft_err(av[0], "Arg_v", "error", 0));
	tetrimino_set = parse(av[1]);
	if (!tetrimino_set)
		return (1);
	i = 0;
	c = '0';
	while (tetrimino_set[i] != USHRT_MAX)
	{
		if (i)
			ft_putendl("\n********************************************************");
		put_tetrimino(tetrimino_set[i++], c++);
	}
	return (0);
}
