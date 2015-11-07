/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 19:23:56 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/01 09:34:47 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "libft.h"
# include "dyntab.h"
# include "err.h"

# define CHARSET ".0123456789"
# define NB_TOK 13
# define OFFSET 16
# define MYNAME "ComputerV1: "

typedef enum		e_ttyp
{
	NONE,
	TOK_COEF,
	TOK_EXP,
	TOK_X,
	TOK_OP,
	TOK_EQ,
	TOK_BLK,
	TOK_SIG,
	TOK_EOF,
	ERROR
}					t_ttyp;

typedef struct		s_tok
{
	t_ttyp			type;
	char			*str;
	unsigned int	size;
	float			val;
}					t_tok;

int					lex_lexer(t_dtab *dtab, char *av);
void				deb_put(t_tok *tab, unsigned int size);
void				ini_init_x(t_tok *token, int *i);
void				ini_init_blk(t_tok *token, int *i);
void				ini_init_other(t_tok *token, int *i);
int					err_handle(int err_id, t_dtab *token);

#endif
