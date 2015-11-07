/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 08:40:59 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/31 17:03:38 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static float	do_get_degree(t_dtab *token, unsigned int i, float degree, unsigned int eq)
{
	float		res;
	unsigned int			meq;

	res = 0.0;
	meq = 0;
	//++i;
	while (((t_tok *)token->data)[i].type != TOK_EOF && i < token->size)
	{
		if (((t_tok *)token->data)[i].type == TOK_EQ)
			meq = i;
		else if (((t_tok *)token->data)[i].type == TOK_EXP && ((t_tok *)token->data)[i].val == degree)
		{
			printf("DEBUG:\teq:\t%u\tmeq:\t%u\n", eq, meq);
			if (!eq && meq)
				res += (((t_tok *)token->data)[i - 1].val * -1);
			else
				res += ((t_tok *)token->data)[i - 1].val;
			dtab_remove(token, i--);
			dtab_remove(token, i--);
			if (((t_tok *)token->data)[i].type != TOK_EQ)
				dtab_remove(token, i--);
		}
		++i;
	}
	return (res);
}

void			do_sub(t_dtab *token)
{
	unsigned int	i;
	t_tok			tmp;

	i = 0;
	get_op(&tmp);
	while (((t_tok *)token->data)[++i].type != TOK_EOF && i < token->size)
	{
		if (((t_tok *)token->data)[i].type == TOK_OP && ((t_tok *)token->data)[i].val == -1.0)
		{
			((t_tok *)token->data)[i + 1].val *= -1;
			dtab_remove(token, i);
			dtab_insert(token, i, &tmp);
		}
	}
}

void			do_mult(t_dtab *token)
{
	unsigned int	i;
	t_tok			tmp;

	i = 0;
	get_op(&tmp);
	while (((t_tok *)token->data)[++i].type != TOK_EOF && i < token->size)
	{
		if (((t_tok *)token->data)[i].type == TOK_OP && ((t_tok *)token->data)[i].val == 1.0)
		{
			((t_tok *)token->data)[i - 2].val *= ((t_tok *)token->data)[i + 1].val;
			((t_tok *)token->data)[i - 1].val += ((t_tok *)token->data)[i + 2].val;
			dtab_remove(token, i);
			dtab_remove(token, i);
			dtab_remove(token, i--);
		}
	}
}

void			do_add(t_dtab *token)
{
	unsigned int	i;
	unsigned int	eq;
	t_tok			tmp;

	i = 0;
	eq = 0;
	get_op(&tmp);
	while (((t_tok *)token->data)[++i].type != TOK_EOF && i < token->size)
	{
		
		if (((((t_tok *)token->data)[i].type == TOK_OP) && ((t_tok *)token->data)[i].val == 0.0) || (((t_tok *)token->data)[i].type == TOK_EQ))
			((t_tok *)token->data)[i - 2].val += do_get_degree(token, i, ((t_tok *)token->data)[i - 1].val, eq);
		if (((t_tok *)token->data)[i].type == TOK_EQ)
			eq = i;
	}
}
