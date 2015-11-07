/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computerv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 16:42:46 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/26 18:27:18 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTERV1_H
# define COMPUTERV1_H

# include "libft.h"
# include "dyntab.h"

# define ABS(x) x < 0 ? x * -1 : x
# define CHARSET ".0123456789"
# define NB_TOK 8
# define OFFSET 32
# define A_COEF 2
# define B_COEF 1
# define C_COEF 0
# define CONTINUE 0
# define END 1
# define ERROR -1
# define ERR_LEX 0
# define ERR_PAR -1
# define ERR_ML -1
# define NO_ERR 1

typedef enum		e_ttyp
{
	TOK_COEF,
	TOK_X,
	TOK_EXP,
	TOK_OP,
	TOK_EQ,
	TOK_BLK,
	TOK_SIG,
	TOK_EOF
}					t_ttyp;

typedef struct		s_tok
{
	t_ttyp			type;
	char			*str;
	unsigned int	size;
	float			val;
}					t_tok;

typedef struct		s_dis
{
	float			coef[3];
	float			dis;
}					t_dis;

void				par_debug_put(t_tok *tab, unsigned int size);
int					lex_lexer(t_dtab *dtab, char *av);
int					par_parser(t_dtab *dtab);
void				res_resolve(t_dtab *dtab);
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

#endif
