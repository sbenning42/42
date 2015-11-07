/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 20:21:20 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/01 09:53:03 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void		ini_init_x(t_tok *token, int *i)
{
	token[++(*i)].type = TOK_X;
	token[*i].str = "X^";
	token[*i].size = 2;
	token[++(*i)].type = TOK_X;
	token[*i].str = "x^";
	token[*i].size = 2;
	token[++(*i)].type = TOK_X;
	token[*i].str = "X";
	token[*i].size = 1;
	token[*i].val = 1.0;
	token[++(*i)].type = TOK_X;
	token[*i].str = "x";
	token[*i].size = 1;
	token[*i].val = 1.0;
}

void		ini_init_blk(t_tok *token, int *i)
{
	token[++(*i)].type = TOK_BLK;
	token[*i].str = " ";
	token[*i].size = 1;
	token[++(*i)].type = TOK_BLK;
	token[*i].str = "\t";
	token[*i].size = 1;
	token[++(*i)].type = TOK_EOF;
	token[*i].str = "\0";
	token[*i].size = 1;
}

void		ini_init_other(t_tok *token, int *i)
{
	token[++(*i)].type = TOK_EQ;
	token[*i].str = "=";
	token[*i].size = 1;
	token[++(*i)].type = TOK_OP;
	token[*i].str = "*";
	token[*i].size = 1;
	token[*i].val = 1.0;
	token[++(*i)].type = TOK_OP;
	token[*i].str = "/";
	token[*i].size = 1;
	token[++(*i)].type = TOK_OP;
	token[*i].str = "%";
	token[*i].size = 1;
	token[++(*i)].type = TOK_SIG;
	token[*i].str = "+";
	token[*i].size = 1;
	token[++(*i)].type = TOK_SIG;
	token[*i].str = "-";
	token[*i].size = 1;
	token[*i].val = 1.0;
}

