/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 13:01:59 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/31 16:48:45 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "lexer.h"

int					par_parser(t_dtab *token);
int       			exp_polynome(t_dtab *dtab);
void				hdl_val(t_dtab *token);
int					hdl_sig(t_dtab *token);
void				hdl_op(t_dtab *token);
int					hdl_coef(t_dtab *token);
void				hdl_exp(t_dtab *token);
void				do_sub(t_dtab *token);
void				do_mult(t_dtab *token);
void				do_add(t_dtab *token);
void				get_op(t_tok *tok);
void				get_exp(t_tok *tok);
void				get_coef(t_tok *tok);

#endif
