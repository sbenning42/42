/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 16:34:27 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/09 18:53:09 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parser.h"

int				main(int ac, char **av)
{
	t_dtab		token;
	t_res		reseq;

	if (ac < 2)
		return (err_handle(ERR_ARG, &token));
	else if (!dtab_init(&token, OFFSET, sizeof(t_tok)))
			return (err_handle(ERR_ML, &token));
	while (--ac)
	{
		++av;
		if ((err_handle(lex_lexer(&token, *(av)), &token)) < ERR )
			continue ;
		if ((err_handle(par_parser(&token), &token)) < ERR)
			continue ;
		res_resolve(&token, &reseq);
		put_putreseq(&reseq);
		dtab_clr(&token);
		res_clr(&reseq);
	//	deb_put((t_tok *)token.data, token.size);
	}
	dtab_del(&token);
	return (0);
}
