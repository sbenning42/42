/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explicit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 01:30:52 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/31 16:47:14 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void			exp_handle_x2(t_dtab *token)
{
	unsigned int	i;

	i = 0;
	while (++i < token->size)
	{
		if (((t_tok *)token->data)[i].type == TOK_X)
			dtab_remove(token, i);
	}
}

static int			exp_handle_x(t_dtab *token)
{
	t_tok			tmp;
	unsigned int	i;

	i = 0;
	get_coef(&tmp);
	while (++i < token->size)
	{
		if (((t_tok *)token->data)[i].type == TOK_X)
		{
			if (((t_tok *)token->data)[i].val == 1.0)
			{
				if (!dtab_insert(token, i + 1, &tmp))
					return (ERR_ML);
			}
			if ((((t_tok *)token->data)[i - 1].type == TOK_OP && ((t_tok *)token->data)[i - 2].type != TOK_COEF) || (((t_tok *)token->data)[i - 1].type != TOK_COEF && ((t_tok *)token->data)[i - 1].type != TOK_OP) || (((t_tok *)token->data)[i - 1].type != TOK_COEF && ((t_tok *)token->data)[i - 1].type == TOK_OP && ((t_tok *)token->data)[i - 1].val == 1))
			{
				if (!dtab_insert(token, i++, &tmp))
					return (ERR_ML);
			}
		}
	}
	return (NO_ERR);
}

int       			exp_polynome(t_dtab *token)
{
	if (exp_handle_x(token) == ERR_ML)
		return (ERR_ML);
	hdl_val(token);
	if (hdl_sig(token) == ERR_ML)
		return (ERR_ML);
	hdl_exp(token);
	hdl_op(token);
	if (hdl_coef(token) == ERR_ML)
		return (ERR_ML);
	exp_handle_x2(token);
	return (NO_ERR);
}
