/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 17:16:57 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/09 19:41:33 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.h"

void				res_square(t_res *reseq, float *exp)
{
	if (reseq->dis > 0)
		sqr_posdis(reseq);
	else if (reseq->dis == 0.0)
		sqr_nuldis(reseq);
	else
		sqr_negdis(reseq);
}

void				res_simple(t_res *reseq, float *exp)
{
	reseq->x1 = (exp[C_COEF] * -1.0) / exp[B_COEF];
	reseq->x2 = reseq->x1;
}

static void			initexp(float exp[3])
{
	exp[A_COEF] = 0.0;
	exp[B_COEF] = 0.0;
	exp[C_COEF] = 0.0;
}

void				res_resolve(t_dtab *token, t_res *reseq)
{
	float			exp[3];
	
	reseq->degree = xtr_degree(token);
	if (reseq->degree > 2.0 || reseq->degree < 0.0)
		return ;
	initexp(exp);
	reseq->dis = xtr_dis(token, exp);
	if (reseq->degree == 2.0)
		res_square(reseq, exp);
	else if (reseq->degree == 1.0)
		res_simple(reseq, exp);
}
