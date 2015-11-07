/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:33:59 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/01 11:50:34 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void				hdl_exp(t_dtab *token)
{
	unsigned int	i;

	i = 0;
	while (++i < token->size)
	{
		if (((t_tok *)token->data)[i].type == TOK_X && ((t_tok *)token->data)[i + 1].type == TOK_COEF)
			((t_tok *)token->data)[i + 1].type = TOK_EXP;
	}
}

int					hdl_coef(t_dtab *token)
{
	unsigned int	i;
	t_tok			tmp;

	get_exp(&tmp);
	i = 0;
	while (++i < token->size)
	{
		if (((t_tok *)token->data)[i].type == TOK_COEF && (((t_tok *)token->data)[i + 1].type == TOK_OP || ((t_tok *)token->data)[i + 1].type == TOK_EQ || ((t_tok *)token->data)[i + 1].type == TOK_EOF))
		{
			if (!dtab_insert(token, i + 1, &tmp))
				return (ERR_ML);
		}
	}
	return (NO_ERR);
}

void				hdl_op(t_dtab *token)
{
	unsigned int	i;

	i = 0;
	while (++i < token->size)
	{
		if (((t_tok *)token->data)[i].type == TOK_OP && ((t_tok *)token->data)[i - 1].type == TOK_COEF && ((t_tok *)token->data)[i + 1].type == TOK_X)
			dtab_remove(token, i);
	}
}

int					hdl_sig(t_dtab *token)
{
	unsigned int	i;
	t_tok			tmp;

	i = 0;
	get_op(&tmp);
	while (++i < token->size)
	{
		if (((t_tok *)token->data)[i].type == TOK_SIG)
		{
			((t_tok *)token->data)[i].val = ((t_tok *)token->data)[i].val == 1.0 ? -1 : 0;
			((t_tok *)token->data)[i].type = TOK_OP;
		}
		else if (((t_tok *)token->data)[i].type == TOK_COEF && ((t_tok *)token->data)[i + 1].type == TOK_COEF)
		{
			if (!dtab_insert(token, i + 1, &tmp))
				return (ERR_ML);
		}
	}
	return (NO_ERR);
}

void				hdl_val(t_dtab *token)
{
	unsigned int	i;

	i = 0;
	while (++i < token->size)
	{
		if (((t_tok *)token->data)[i].type == TOK_COEF && ((t_tok *)token->data)[i].str)
			((t_tok *)token->data)[i].val = ft_atof(((t_tok *)token->data)[i].str);
		if (((t_tok *)token->data)[i].type == TOK_COEF && ((t_tok *)token->data)[i - 1].type == TOK_SIG)
		{
			if (((t_tok *)token->data)[i - 1].val == 1.0)
				((t_tok *)token->data)[i].val *= -1;
			dtab_remove(token, i - 1);
		}
	}
}
