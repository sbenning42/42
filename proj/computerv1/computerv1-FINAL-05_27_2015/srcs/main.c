/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 16:34:27 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/27 14:31:46 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.h"










static void		par_debug_puttype(t_ttyp type)
{
	if (type == TOK_BLK)
		ft_putstr("TOK_BLK");
	else if (type == TOK_COEF)
		ft_putstr("TOK_COEF");
	else if (type == TOK_EOF)
		ft_putstr("TOK_EOF");
	else if (type == TOK_EQ)
		ft_putstr("TOK_EQ");
	else if (type == TOK_EXP)
		ft_putstr("TOK_EXP");
	else if (type == TOK_OP)
		ft_putstr("TOK_OP");
	else if (type == TOK_SIG)
		ft_putstr("TOK_SIG");
	else if (type == TOK_X)
		ft_putstr("TOK_X");
}

void		par_debug_put(t_tok *tab, unsigned int size)
{
	unsigned int	i;
	
	i = 0;
	while (i < size)
	{
		ft_putstr("\nTOK:\n\tType:\t");
		par_debug_puttype(tab[i].type);
//		ft_putstr("\n\tStr:\t");
//		ft_putstr(tab[i].str);
		ft_putstr("\n\tVal:\t");
		ft_putnbr(tab[i].val);
		ft_putstr("\n");
		i++;
	}
	ft_putstr("\n");
}













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
		return ((int)write(1, "\n", 1));
	i = 0;
	while (++i < ac)
	{
		if (ac > 2)
			cmp_puteq(av[i]);
		if (!dtab_init(&dtab, OFFSET, sizeof(t_tok)))
			err_malloc(&dtab);
		else if ((ret = lex_lexer(&dtab, av[i])) <= 0)
			ret == 0 ? err_lexer(&dtab) : err_malloc(&dtab);
		par_debug_put(dtab.data, dtab.size);
		if ((ret = par_parser(&dtab)) == ERR_PAR)
			err_parser(&dtab);
	/*	else if (ret != END)
		{
			res_resolve(&dtab);
			dtab_del(&dtab);
		}
		*/
	}
	return (0);
}
