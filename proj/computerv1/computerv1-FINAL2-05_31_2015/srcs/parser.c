/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 10:53:19 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/01 11:50:35 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int			par_iseq(t_tok *token, unsigned int size)
{
	int				eq;

	eq = 0;
	while (--size)
	{
		if (token->type == TOK_EQ)
			eq++;
		if (eq > 1)
		{
			token->type = ERROR;
			break ;
		}
		token++;	
	}
	if (!eq)
		token->type = ERROR;
	return (eq == 1 ? NO_ERR : ERR_PAR);
}

static int			par_check_rules(t_tok *token)
{
	t_ttyp			prev;
	t_ttyp			next;

	prev = (token - 1)->type;
	next = (token + 1)->type;
	if (token->type == TOK_COEF && COEF_RULES)
		return (ERR_PAR);
	else if (token->type == TOK_X && X_RULES)
		return (ERR_PAR);
	else if (token->type == TOK_OP && OP_RULES)
		return (ERR_PAR);
	else if (token->type == TOK_SIG && SIG_RULES)
		return (ERR_PAR);
	else if (token->type == TOK_EQ && EQ_RULES)
		return (ERR_PAR);
	return (NO_ERR);
}

static int			par_iserr(t_tok *token, unsigned int size)
{
	while (--size)
	{
		token++;
		if (par_check_rules(token) == ERR_PAR)
		{
			token->type = ERROR;
			return (ERR_PAR);
		}
	}
	return (NO_ERR);
}

int					par_parser(t_dtab *token)
{
	if (par_iseq(TDATA, token->size) == ERR_PAR \
		|| par_iserr(TDATA, token->size) == ERR_PAR)
	{
		return (ERR_PAR);
	}
	else if (exp_polynome(token) == ERR_ML)
		return (ERR_ML);
	do_sub(token);
	do_mult(token);
	do_add(token);
	return (NO_ERR);
}
