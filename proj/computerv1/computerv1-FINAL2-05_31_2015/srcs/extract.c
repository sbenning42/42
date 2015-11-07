/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 18:56:35 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/09 22:57:00 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"computerv1.h"

float		xtr_degree(t_dtab *token)
{
	t_tok	*tok;
	float	flag;
	float	degree;

	flag = 0.0;
	degree = 0.0;
	tok = (t_tok *)token->data;
	while (tok->type != T_EOF)
	{
		if (tok->type == T_EXP)
		{
			if (tok->val > degree)
				degree = tok->val;
			if (flag == 0.0 && (tok->val < 0.0 || tok->val > 2.0))
				flag = tok->val;
		}
		tok++;
	}
	return (flag != 0.0 ? flag : degree);
}

float				xtr_dis(t_dtab *token, float *exp)
{
	float			coef;
	float			sig;
	t_tok			*tok;


	sig = 1.0;
	tok = (t_tok *)token->data;
	while (tok->type != T_EOF)
	{
		if (tok->type == T_EQ)
			sig *= -1.0;
		else if (tok->type == TOK_COEF)
			coef = tok->val * sig;
		else if (tok->type == TOK_EXP)
				exp[(int)tok->val] = coef;
		tok++;
	}
	return (exp[B_COEF] * exp[B_COEF] - 4 * exp[A_COEF] * exp[C_COEF]);
}
