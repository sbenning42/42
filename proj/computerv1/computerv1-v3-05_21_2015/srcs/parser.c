#include "computerv1.h"

static int			red_put_degree(float degree)
{
	ft_putstr("Polynomial degree: ");
	ft_putnbr(degree);
	ft_putchar('\n');
	if (degree > 2.0)
	{
		ft_putstr("The polynomial degree is stricly \
		greater than 2, I can't solve.\n");
		return (END);
	}
	return (CONTINUE);
}

static void			red_put_polynom(float coef, float degree, int ieq, int flag)
{
	char			val[32];

	ft_bzero(val, sizeof(char) * 32);
	coef *= ieq > 0 ? 1 : -1;
	if (flag)
		coef >= 0 ? ft_putstr("+ ") : ft_putstr ("- ");
	else if (coef < 0)
		ft_putstr ("-");
	ft_ftoa(ABS(coef), val, 2);
	ft_putstr(val);
	ft_putstr(" * X^");
	ft_putnbr(degree);
	ft_putchar(' ');
}

static void			red_handle_put(t_tok *tab,\
					unsigned int size, int eq, float degree)
{
	unsigned int	i;
	float			coef;
	float			tmp;

	i = 0;
	tmp = degree;
	ft_putstr("\nReduced form: ");
	while (degree >= 0)
	{
		while (i < size)
		{
			if (tab[i].type == TOK_COEF)
				coef = tab[i].val;
			else if (tab[i].type == TOK_EXP && tab[i].val == degree)
			{
				red_put_polynom(coef, degree, eq - i, tmp == degree ? 0 : 1);
				break ;
			}
			i++;
		}
		degree--;
		i = 0;
	}
	ft_putendl("= 0");
}

static float		red_handle_exp(t_tok *tab,\
					unsigned int size, float degree, int eq)
{
	int				i;
	float			coef;
	float			tcoef;

	i = 0;
	tcoef = 0.0;
	while (i < (int)size)
	{
		if (tab[i].type == TOK_COEF)
			coef = tab[i].val;
		else if (tab[i].type == TOK_EXP && tab[i].val == degree)
			tcoef += (i < eq) ? coef : (coef * -1);
		i++;
	}
	return (tcoef);
}

static void			red_handle_coef(t_tok *tab, \
					unsigned int size, float *degree, int eq)
{
	unsigned int	i;
	float			*coef;
	float			tmp;

	tmp = *degree;
	while (i = 0, *degree >= 0.0)
	{
		while (i < size)
		{
			if (tab[i].type == TOK_COEF)
				coef = &(tab[i].val);
			else if (tab[i].type == TOK_EXP && tab[i].val == *degree)
			{
				++i;
				*coef += red_handle_exp(tab + i, size - i, *degree, eq - i);
				if (tmp && *coef == 0.0 && *degree == tmp)
					tmp--;
				break ;
			}
			i++;
		}
		(*degree)--;
	}
	*degree = tmp;
}

static int			red_tokchr(t_tok *tab, unsigned int size, t_ttyp type)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i].type == type)
			return ((int)i);
		i++;
	}
	return (ERR_PAR);
}

static void			red_handle_degree(t_tok *tab,\
					unsigned int size, float *degree)
{
	unsigned int	i;
	float			coef;

	i = 0;
	while (i < size)
	{
		if (tab[i].type == TOK_COEF)
			coef = tab[i].val;
		else if (coef != 0.0 && tab[i].type == TOK_EXP && *degree < tab[i].val)
			*degree = tab[i].val;
		i++;
	}
}

static void			red_handle_sig(t_tok *tab, unsigned int size)
{
	unsigned int	i;
	char			flag;

	i = 0;
	flag = 0;
	while (i < size)
	{
		if (tab[i].type == TOK_SIG && !ft_strncmp(tab[i].str, "-", tab[i].size))
			flag = 1;
		else if (tab[i].type == TOK_COEF && flag)
		{
			flag = 0;
			tab[i].val *= -1;
		}
		i++;
	}
}

int					par_parser(t_dtab *dtab)
{
	t_tok			*tab;
	float			degree;
	int				ret;

	degree = 0.0;
	tab = (t_tok *)dtab->data;
	ret = red_tokchr(tab, dtab->size, TOK_EQ);
	if (ret == ERR_PAR)
		return (ERR_PAR);
	red_handle_sig(tab, dtab->size);
	red_handle_degree(tab, dtab->size, &degree);
	red_handle_coef(tab, dtab->size, &degree, ret);
	red_handle_put(tab, dtab->size, ret, degree);
	ret = red_put_degree(degree);
	if (ret == END)
		return (END);
	return (CONTINUE);
}
