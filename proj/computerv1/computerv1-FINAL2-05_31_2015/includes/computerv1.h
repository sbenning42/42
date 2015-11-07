/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computerv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 16:42:46 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/09 19:03:45 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTERV1_H
# define COMPUTERV1_H

# include "libft.h"
# include "dyntab.h"
# include "lexer.h"
# include "err.h"

# define ABS(x) x < 0 ? x * -1 : x
//# define CHARSET ".0123456789"
//# define NB_TOK 11
# define OFFSET 32
# define A_COEF 2
# define B_COEF 1
# define C_COEF 0
# define CONTINUE 0
# define END 1
/*
# define ERROR -1
# define ERR_LEX 0
# define ERR_PAR -1
# define ERR_ML -1
# define NO_ERR 1
*/
/*
# define MALLOC_MSG "Computerv1: Malloc error appear."
//# define LEXER_MSG "Computerv1: Lexer error appear."
# define PARSER_MSG "Computerv1: Parser error appear"
*/
# define MSG1 "The polynomial degree is stricly "
# define MSG2 MSG1"greater than 2, I can't solve.\n"
# define DISCRI "The discriminent is stricly "
# define POS_DELTA DISCRI"positive, there is two real solutions:"
# define NUL_DELTA DISCRI"null, there is a unique real solution:"
# define NEG_DELTA DISCRI"negative, there is two complexes solutions:"

typedef struct		s_res
{
	float			degree;
	float			dis;
	float			x1;
	float			x2;
}					t_res;

typedef struct		s_dis
{
	float			coef[3];
	float			dis;
}					t_dis;

//int					lex_lexer(t_dtab *dtab, char *av);
int					par_parser(t_dtab *dtab);
void				red_put_polynom(float coef, float degree, \
					int ieq, int flag);
void				res_resolve(t_dtab *token, t_res reseq);
void				res_positive_delta(t_dis *delta);
void				res_null_delta(t_dis *delta);
void				res_negative_delta(t_dis *delta);
void				cmp_discriminent(t_dtab *dtab, t_dis *delta);
void				cmp_resolve_all(void);
void				cmp_resolve_sim(t_dis *delta);
void				cmp_resolve_sqr(t_dis *delta);
void				ft_ftoa(float f, char *s, int dec);
float				ft_atof(char *s);
float				mt_fsqrt(float a);
void				dis_initdis(t_dis *delta);
void				dis_getdis(t_dtab *dtab, t_dis *delta);
int					err_malloc(t_dtab *dtab);
int					err_lexer(t_dtab *dtab);
int					err_parser(t_dtab *dtab);
void				hdl_handle_coef(t_tok *tab, unsigned int size, \
					float *degree, int eq);
void				hdl_handle_put(t_tok *tab, unsigned int size, \
					int eq, float degree);
void				hdl_handle_sig(t_tok *tab, unsigned int size);
void				hdl_handle_degree(t_tok *tab, unsigned int size, \
					float *degree);
float				xtr_degree(t_dtab *token);
#endif
