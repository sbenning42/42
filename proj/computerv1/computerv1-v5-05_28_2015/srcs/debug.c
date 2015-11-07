/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:04:10 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/31 15:29:27 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void			deb_debug(t_tok *token, unsigned int size)
{
	ft_putstr(MYNAME);
	ft_putendl("Debug token tab.");
	while (size--)
	{
		ft_putstr("\nTYPE:\t\t");
		if (token->type == NONE)
			ft_putstr("NONE");
		else if (token->type == TOK_COEF)
			ft_putstr("TOK_COEF");
		else if (token->type == TOK_EXP)
			ft_putstr("TOK_EXP");
		else if (token->type == TOK_OP)
			ft_putstr("TOK_OP");
		else if (token->type == TOK_X)
			ft_putstr("TOK_X");
		else if (token->type == TOK_EQ)
			ft_putstr("TOK_EQ");
		else if (token->type == TOK_EOF)
			ft_putstr("TOK_EOF");
		else if (token->type == ERROR)
			ft_putstr("ERROR");
		else
			ft_putnbr((long long int)token->type);
		ft_putstr("\nSTR:\t\t");
		write(1, token->str, token->size);
		ft_putstr("\nSIZE:\t\t");
		ft_putnbr((long long int)token->size);
		ft_putstr("\nVAL:\t\t");
		ft_putnbr((long long int)token->val);
		write(1, "\n", 1);
		token++;
	}
	write(1, "\n", 1);
}
