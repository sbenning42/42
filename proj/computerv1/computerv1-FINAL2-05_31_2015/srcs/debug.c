/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:04:10 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/01 08:35:04 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void				deb_put(t_tok *token, unsigned int size)
{
	unsigned int	n;
	t_tok			*tmp;

	n = size;
	tmp = token;
	write(1, "\n", 1);
	ft_putstr(MYNAME);
	ft_putendl("Debug token tab.\n");
	while (n--)
	{
		if (token->type == NONE)
			ft_putstr("NONE\t");
		else if (token->type == TOK_COEF)
			ft_putstr("T_COEF  ");
		else if (token->type == TOK_EXP)
			ft_putstr("T_EXP\t");
		else if (token->type == TOK_OP)
			ft_putstr("T_OP\t");
		else if (token->type == TOK_X)
			ft_putstr("T_X\t");
		else if (token->type == TOK_EQ)
			ft_putstr("T_EQ\t");
		else if (token->type == TOK_EOF)
			ft_putstr("T_EOF\t");
		else if (token->type == TOK_SIG)
			ft_putstr("T_SIG\t");
		else if (token->type == ERROR)
			ft_putstr("ERROR\t");
		else
		{
			ft_putnbr((long long int)token->type);
			ft_putstr("\t\t");
		}
		token++;
	}
	write(1, "\n", 1);
	n = size;
	token = tmp;
	while (n--)
	{
		ft_putnbr((long long int)token->val);
		ft_putstr("\t");
		token++;
	}
	write(1, "\n", 1);
}
