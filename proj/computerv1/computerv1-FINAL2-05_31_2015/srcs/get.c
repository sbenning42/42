/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:31:40 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/31 15:33:22 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void				get_op(t_tok *tok)
{
	tok->type = TOK_OP;
	tok->str = NULL;
	tok->size = 0;
	tok->val = 0.0;
}

void				get_exp(t_tok *tok)
{
	tok->type = TOK_EXP;
	tok->str = NULL;
	tok->size = 0;
	tok->val = 0.0;
}

void				get_coef(t_tok *tok)
{
	tok->type = TOK_COEF;
	tok->str = NULL;
	tok->size = 0;
	tok->val = 1.0;
}
