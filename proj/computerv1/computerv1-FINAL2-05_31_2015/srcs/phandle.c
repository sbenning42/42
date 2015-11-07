/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phandle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 11:55:15 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/29 13:34:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			phdl_none(t_tok *token, unsigned int size)
{
	if (size <= 1)
		return (ERR_PAR);
	token++;
	if (token->type == TOK_OP || token->type == TOK_EQ)
		return (ERR_PAR);
	return (NO_ERR);
}

int			phdl_coef(t_tok *token, unsigned int size)
{
	if (size <= 1)
		return (ERR_PAR);
	token++;
	if (token->type == TOK_COEF)
		return (ERR_PAR);
	return (NO_ERR);
}

int			phdl_x(t_tok *token, unsigned int size)
{
	t_tok		*tmp;

	tmp =token;
	if (size <= 1)
		return (ERR_PAR);
	token++;
	if (token->type == TOK_X || (tmp->val != 1.0 && (token->type == TOK_OP || token->type == TOK_EQ || token->type == TOK_X)))
		return (ERR_PAR);
	return (NO_ERR);
}

int			phdl_op(t_tok *token, unsigned int size)
{
	if (size <= 1)
		return (ERR_PAR);
	token++;
	if (token->type == TOK_OP || token->type == TOK_EQ)
		return (ERR_PAR);
	return (NO_ERR);
}

int			phdl_eq(t_tok *token, unsigned int size)
{
	if (size <= 1)
		return (ERR_PAR);
	token++;
	if (token->type == TOK_OP || token->type == TOK_EQ)
		return (ERR_PAR);
	return (NO_ERR);
}

int				phdl_sig(t_tok *token, unsigned int size)
{
	if (size <= 1)
		return (ERR_PAR);
	if (token->type == TOK_OP || token->type == TOK_EQ)
		return (ERR_PAR);
	return (NO_ERR);
}

int			phdl_eof(t_tok *token, unsigned int size)
{
	if (size != 1)
		return (ERR_PAR);
	return (NO_ERR);
}
