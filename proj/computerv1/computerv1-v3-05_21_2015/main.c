/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 16:34:27 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/26 16:35:26 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.h"

static void		cmp_puteq(char *av)
{
	ft_putstr("\nEquation: ");
	ft_putstr(av);
}

int				main(int ac, char **av)
{
	int			i;
	int			ret;
	t_dtab		dtab;

	if (ac < 2)
		return (write(1, "\n", 1));
	i = 0;
	while (++i < ac)
	{
		cmp_puteq(av[i]);
		if (!dtab_init(&dtab, OFFSET, sizeof(t_tok)))
			err_malloc(&dtab);
		else if ((ret = lex_lexer(&dtab, av[i])) <= 0)
			ret == 0 ? err_lexer(&dtab) : err_malloc(&dtab);
		else if ((ret = par_parser(&dtab)) == ERR_PAR)
			err_parser(&dtab);
		else if (ret != END)
		{
			res_resolve(&dtab);
			dtab_del(&dtab);
		}
	}
	return (0);
}
