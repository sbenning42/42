#ifndef COMPUTERV1_H
# define COMPUTERV1_H

# include "libft.h"
# include "dyntab.h"

# define ABS(x) x < 0 ? x * -1 : x
# define CHARSET ".0123456789"
# define NB_TOK 8
# define OFFSET 32
# define ERR_LEX 0
# define ERR_RED 0
# define ERR_ML -1
# define NO_ERR 1

typedef enum	e_ttyp
{
	TOK_COEF,
	TOK_X,
	TOK_EXP,
	TOK_OP,
	TOK_EQ,
	TOK_BLK,
	TOK_SIG,
	TOK_EOF
}		t_ttyp;

typedef struct	s_tok
{
	t_ttyp	type;
	char	*str;
	unsigned int size;
	float	val;
}		t_tok;

typedef struct	s_dis
{
	float	tcoef[3];
	float	dis;
}		t_dis;

void		par_debug_put(t_tok *tab, unsigned int size);
int		cmp_parse(t_dtab *udtab, char *av);
int		cmp_reduce(t_dtab *dtab, int *end);
int		cmp_resolve(t_dtab *dtab);
void		cmp_discriminent(t_dtab *dtab, t_dis *delta);
void		cmp_resolve_all(void);
void		cmp_resolve_sim(t_dis *delta);
void		cmp_resolve_sqr(t_dis *delta);
void		ft_ftoa(float f, char* s, int dec);
float		ft_atof(char *s);
float		mt_fsqrt(float a);

#endif
