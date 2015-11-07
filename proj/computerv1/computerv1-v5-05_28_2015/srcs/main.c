/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 16:34:27 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/31 17:03:40 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parser.h"

static void			put_reduce(t_dtab *token)
{
	t_tok			*tok;
	unsigned int	i;
	int				eq;

	eq = 0;
	i = 1;
	tok = (t_tok *)token->data;
	ft_putstr("Reduced form:\t");
	while (i < token->size && tok[i].type != TOK_EOF)
	{
		if (tok[i].type == TOK_COEF)
			ft_putnbr((long long int)tok[i].val);
		else if (tok[i].type == TOK_OP && tok[i + 1].val > 0.0)
			ft_putstr("+ ");
		else if (tok[i].type == TOK_EXP)
		{
			ft_putstr(" * X^");
			ft_putnbr((long long int)tok[i].val);
			ft_putstr(" ");
		}
		else if (tok[i].type == TOK_EQ)
		{
			eq = 42;
			ft_putstr("= ");
		}
		i++;
	}
	if (!eq)
		ft_putstr(" = 0");
	ft_putendl("");
}

int				main(int ac, char **av)
{
	t_dtab		token;

	if (ac < 2)
		return (err_handle(ERR_ARG));
	else if (!dtab_init(&token, OFFSET, sizeof(t_tok)))
			return (err_handle(ERR_ML));
	while (--ac)
	{
		if ((err_handle(lex_lexer(&token, *(av + 1)))) < ERR )
			continue ;
		else if ((err_handle(par_parser(&token))) < ERR)
			continue ;
		put_reduce(&token);
		//err_handle(res_resolve(&polynome, *av));
	}
	dtab_del(&token);
	return (0);
}
