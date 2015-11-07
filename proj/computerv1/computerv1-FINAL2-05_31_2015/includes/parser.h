/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 13:01:59 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/01 10:26:05 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"

# define COEF_PR  (prev == TOK_COEF || (prev == TOK_X && (token - 1)->val == 1.0))
# define COEF_NR (next == TOK_COEF)
# define COEF_RULES (COEF_PR || COEF_NR)

# define X_PR (prev == TOK_X)
# define X_CNR1 (token->val == 1.0 && next == TOK_COEF)
# define X_CNR2 (token->val == 0.0 && (next == TOK_OP || next == TOK_EQ || next == TOK_EOF))
# define X_NR (next == TOK_X || X_CNR1 || X_CNR2)
# define X_RULES (X_PR || X_NR)

# define OP_PR (prev == TOK_OP || prev == TOK_SIG || prev == TOK_EQ || prev == NONE)
# define OP_NR (next == TOK_OP || next == TOK_EQ || next == TOK_EOF)
# define OP_RULES (OP_PR || OP_NR)

# define SIG_CPR1 (prev == TOK_X && (token - 1)->val == 0.0)
# define SIG_CPR2 (prev == TOK_SIG || SIG_CPR1 || prev == TOK_OP || prev == TOK_EQ)
# define SIG_PR (SIG_CPR2 && next == TOK_SIG)
# define SIG_NR (next == TOK_OP || next == TOK_EQ || next == TOK_EOF)
# define SIG_RULES (SIG_PR || SIG_NR)

# define EQ_PR (prev == NONE || prev == TOK_SIG || prev == TOK_OP)
# define EQ_NR (next == TOK_OP || next == TOK_EOF)
# define EQ_RULES (EQ_PR || EQ_NR)

# define TDATA ((t_tok *)token->data)

# define INS_COEF_CR1 (TDATA[i-1].type == TOK_OP && TDATA[i-2].type != TOK_COEF)
# define INS_COEF_CR2 (TDATA[i-1].type != TOK_COEF && TDATA[i-1].type != TOK_OP)
# define INS_COEF_CR3_1 (TDATA[i-1].type != TOK_COEF)
# define INS_COEF_CR3_2 (TDATA[i-1].type == TOK_OP)
# define INS_COEF_CR3_3 (TDATA[i-1].val == 1)
# define INS_COEF_CR3 (INS_COEF_CR3_1 && INS_COEF_CR3_2 && INS_COEF_CR3_3)
# define INS_COEF_RULES (INS_COEF_CR1 || INS_COEF_CR2 || INS_COEF_CR3)

int					par_parser(t_dtab *token);
int					exp_polynome(t_dtab *dtab);
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
