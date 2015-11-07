/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 08:40:59 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/31 22:35:39 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static float		do_get_degree(t_dtab *token, unsigned int i, float degree, \
					unsigned int eq)
{
	float			res;
	unsigned int	meq;

	res = 0.0;
	meq = 0;
	while (TDATA[i].type != TOK_EOF && i < token->size)
	{
		if (TDATA[i].type == TOK_EQ)
			meq = i;
		else if (TDATA[i].type == TOK_EXP && TDATA[i].val == degree)
		{
			if (!eq && meq)
				res += (TDATA[i - 1].val * -1);
			else
				res += TDATA[i - 1].val;
			dtab_remove(token, i--);
			dtab_remove(token, i--);
			if (TDATA[i].type != TOK_EQ)
				dtab_remove(token, i--);
		}
		++i;
	}
	return (res);
}

void				do_sub(t_dtab *token)
{
	unsigned int	i;
	t_tok			tmp;

	i = 0;
	get_op(&tmp);
	while (TDATA[++i].type != TOK_EOF && i < token->size)
	{
		if (TDATA[i].type == TOK_OP && TDATA[i].val == -1.0)
		{
			TDATA[i + 1].val *= -1;
			dtab_remove(token, i);
			dtab_insert(token, i, &tmp);
		}
	}
}

void				do_mult(t_dtab *token)
{
	unsigned int	i;
	t_tok			tmp;

	i = 0;
	get_op(&tmp);
	while (TDATA[++i].type != TOK_EOF && i < token->size)
	{
		if (TDATA[i].type == TOK_OP && TDATA[i].val == 1.0)
		{
			TDATA[i - 2].val *= TDATA[i + 1].val;
			TDATA[i - 1].val += TDATA[i + 2].val;
			dtab_remove(token, i);
			dtab_remove(token, i);
			dtab_remove(token, i--);
		}
	}
}

void				do_add(t_dtab *token)
{
	unsigned int	i;
	unsigned int	eq;
	t_tok			tmp;

	i = 0;
	eq = 0;
	get_op(&tmp);
	while (((t_tok *)token->data)[++i].type != TOK_EOF && i < token->size)
	{
		if ((TDATA[i].type == TOK_OP && TDATA[i].val == 0.0) \
			|| TDATA[i].type == TOK_EQ)
			TDATA[i - 2].val += do_get_degree(token, i, TDATA[i - 1].val, eq);
		if (TDATA[i].type == TOK_EQ)
			eq = i;
	}
}
