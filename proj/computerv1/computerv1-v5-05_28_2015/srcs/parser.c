/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 10:53:19 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/31 16:48:46 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int			par_check_rules(t_tok *token)
{
	t_ttyp			prev;
	t_ttyp			next;

	prev = (token - 1)->type;
	next = (token + 1)->type;
	if (token->type == TOK_COEF && \
		(prev == TOK_COEF || (prev == TOK_X && (token - 1)->val == 1.0) || next == TOK_COEF))
		return (ERR_PAR);
	else if (token->type == TOK_X && \
			(prev == TOK_X || next == TOK_X || (token->val == 1.0 && next == TOK_COEF) || (token->val == 0.0 && (next == TOK_OP || next == TOK_EQ || next == TOK_EOF))))
		return (ERR_PAR);
	else if (token->type == TOK_OP && \
			(prev == TOK_OP || prev == TOK_SIG || prev == TOK_EQ || prev == NONE || next == TOK_OP || next == TOK_EQ || next == TOK_EOF))
		return (ERR_PAR);
	else if (token->type == TOK_SIG && \
			(((prev == TOK_SIG || (prev == TOK_X && (token - 1)-> val == 0.0) || prev == TOK_OP || prev == TOK_EQ) && next == TOK_SIG) || next == TOK_OP || next == TOK_EQ || next == TOK_EOF))
		return (ERR_PAR);
	else if (token->type == TOK_EQ && \
			(prev == NONE || prev == TOK_SIG || prev == TOK_OP || next == TOK_OP || next == TOK_EOF))
		return (ERR_PAR);
	return (NO_ERR);
}

static int			par_iserr(t_tok *token, unsigned int size)
{
	int				occ;

	occ = 0;
	while (--size)
	{
		token++;
		if (par_check_rules(token) == ERR_PAR)
			return (ERR_PAR);
		else if (token->type == TOK_EQ)
			occ++;
	}
	return (occ == 1 ? NO_ERR : ERR_PAR);
}

int					par_parser(t_dtab *token)
{
	t_tok			*tok;

	tok = (t_tok *)token->data;
	if (par_iserr(tok, token->size) == ERR_PAR)
		return (ERR_PAR);
	else if (exp_polynome(token) == ERR_ML)
		return (ERR_ML);
	do_sub(token);
	do_mult(token);
	do_add(token);
	return (NO_ERR);
}
