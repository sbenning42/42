#include "computerv1.h"

static void		red_handle_put(t_tok *tab, unsigned int size, int eq, float degree)
{
	unsigned int	i;
	float			coef;
	
	//DEBUG:
	ft_putendl_fd("\tred_handle_put: Start", 2);
	//
	i = 0;
	ft_putstr("Reduced form: ");
	while (degree >= 0)
	{
		while (i < size)
		{	
			if (tab[i].type == TOK_COEF)
			{
				//DEBUG:
				ft_putstr_fd("\tred_handle_put: get a coef: ", 2);
				ft_putnbr_fd(tab[i].val, 2);
				ft_putstr_fd(" at tab + ", 2);
				ft_putnbr_fd(i, 2);
				ft_putchar_fd('\n', 2);
				//
				coef = tab[i].val;
			}
			else if (tab[i].type == TOK_EXP && tab[i].val == degree /*&& coef != 0*/)
			{
				//DEBUG:
				ft_putstr_fd("\tred_handle_put: put polynom for degree: ", 2);
				ft_putnbr_fd(degree, 2);
				ft_putstr_fd(" at tab + ", 2);
				ft_putnbr_fd(i, 2);
				ft_putchar_fd('\n', 2);
				//
				((coef >= 0 && i < eq) || (coef < 0 && i > eq)) ? ft_putstr(" + ") : ft_putstr (" - ");
				ft_putnbr(coef >= 0 ? coef : coef * -1);
				ft_putstr(" * X^");
				ft_putnbr(degree);
				ft_putchar(' ');
				break ;
			}
			i++;
			//DEBUG:
			//ft_putendl_fd("\tred_handle_put: Increment i", 2);
			//
		}
		//DEBUG:
		//ft_putendl_fd("\tred_handle_put: Decrement degree & i = 0", 2);
		//
		degree--;
		i = 0;
	}
	ft_putendl(" = 0");
}

static float	red_handle_exp(t_tok *tab, unsigned int size, float degree, int eq)
{
	int	i;
	float			coef;
	float			tcoef;
	
	//DEBUG:
	ft_putendl_fd("\t\ttred_handle_exp: Start", 2);
	//
	i = 0;
	tcoef = 0.0;
	while (i < size)
	{
		if (tab[i].type == TOK_COEF)
		{
			//DEBUG:
			ft_putstr_fd("\t\ttred_handle_exp: get a coef: ", 2);
			ft_putnbr_fd(tab[i].val, 2);
			ft_putstr_fd(" at tab + ", 2);
			ft_putnbr_fd(i, 2);
			ft_putchar_fd('\n', 2);
			//
			coef = tab[i].val;
		}
		else if (tab[i].type == TOK_EXP && tab[i].val == degree)
		{
			//DEBUG:
			ft_putstr_fd("\t\ttred_handle_exp: degree match at tab + ", 2);
			ft_putnbr_fd(i, 2);
			ft_putchar_fd('\n', 2);
			//
			tcoef += (i < eq) ? coef : (coef * -1);
			//DEBUG:
			ft_putstr_fd("\t\ttred_handle_exp: tcoef: ", 2);
			ft_putnbr_fd(tcoef, 2);
			ft_putchar_fd('\n', 2);
			//
		}
		i++;
		//DEBUG:
		//ft_putendl_fd("\t\ttred_handle_exp: Increment i", 2);
		//
	}
	return (tcoef);
	
}

static void		red_handle_coef(t_tok *tab, unsigned int size, float *degree, int eq)
{
	unsigned int	i;
	float			*coef;
	float			tmp;
	
	//DEBUG:
	ft_putendl_fd("\ttred_handle_coef: Start", 2);
	//
	i = 0;
	tmp = *degree;
	while (*degree >= 0.0)
	{
		while (i < size)
		{
			if (tab[i].type == TOK_COEF)
			{
				//DEBUG:
				ft_putstr_fd("\ttred_handle_coef: get a coef: ", 2);
				ft_putnbr_fd(tab[i].val, 2);
				ft_putstr_fd(" at tab + ", 2);
				ft_putnbr_fd(i, 2);
				ft_putchar_fd('\n', 2);
				//
				coef = &(tab[i].val);
			}
			else if (tab[i].type == TOK_EXP && tab[i].val == *degree)
			{
				//DEBUG:
				ft_putstr_fd("\ttred_handle_coef: handle coef for exp: ", 2);
				ft_putnbr_fd(*degree, 2);
				ft_putstr_fd(" at tab + ", 2);
				ft_putnbr_fd(i, 2);
				ft_putchar_fd('\n', 2);
				//
				*coef += red_handle_exp(tab + ++i, size - i, *degree, eq - i);
				//DEBUG:
				ft_putstr_fd("\ttred_handle_coef: final coef for exp: ", 2);
				ft_putnbr_fd(*degree, 2);
				ft_putstr_fd(" is ", 2);
				ft_putnbr_fd(*coef, 2);
				ft_putstr_fd(" at tab + ", 2);
				ft_putnbr_fd(i, 2);
				ft_putchar_fd('\n', 2);
				//
				if (*coef == 0.0 && *degree == tmp)
					tmp--;
				break ;
			}
			i++;
			//DEBUG:
			//ft_putendl_fd("\ttred_handle_coef: Increment i", 2);
			//
		}
		//DEBUG:
		//ft_putendl_fd("\ttred_handle_coef: Decrement degree & i = 0", 2);
		//
		(*degree)--;
		i = 0;
	}
	*degree = tmp;
}

static int	red_tokchr(t_tok *tab, unsigned int size, t_ttyp type)
{
	int	i;
	
	//DEBUG:
	ft_putendl_fd("\ttred_tokchr: Start", 2);
	//
	i = 0;
	while (i < size)
	{
		if (tab[i].type == type)
		{
			//DEBUG:
			ft_putstr_fd("\tred_tokchr: type: ", 2);
			ft_putnbr_fd(type, 2);
			ft_putstr_fd("is found at tab + ", 2);
			ft_putnbr_fd(i, 2);
			ft_putchar_fd('\n', 2);
			//
			return (i);
		}
		i++;
		//DEBUG:
		//ft_putendl_fd("\ttred_tokchr: Increment i", 2);
		//
	}
	return (ERR_RED);
}
static float	red_handle_degree(t_tok *tab, unsigned int size)
{
	unsigned int	i;
	float		coef;
	float		degree;

	//DEBUG:
	ft_putendl_fd("\ttred_handle_degree: Start", 2);
	//
	i = 0;
	degree = 0.0;
	while (i < size)
	{
		if (tab[i].type == TOK_COEF)
		{
			//DEBUG:
			ft_putstr_fd("\tred_handle_degree: get a coef: ", 2);
			ft_putnbr_fd(tab[i].val, 2);
			ft_putstr_fd(" at tab + ", 2);
			ft_putnbr_fd(i, 2);
			ft_putchar_fd('\n', 2);
			//
			coef = tab[i].val;
		}
		else if (coef != 0.0 && tab[i].type == TOK_EXP && degree < tab[i].val)
		{
			//DEBUG:
			ft_putstr_fd("\tred_handle_degree: get a degree: ", 2);
			ft_putnbr_fd(tab[i].val, 2);
			ft_putstr_fd(" at tab + ", 2);
			ft_putnbr_fd(i, 2);
			ft_putchar_fd('\n', 2);
			//
			degree = tab[i].val;
		}
		i++;
		//DEBUG:
		//ft_putendl_fd("\ttred_handle_degree: Increment i", 2);
		//
	}
	return (degree);
}
static void		red_handle_sig(t_tok *tab, unsigned int size)
{
	unsigned int	i;
	char			flag;

	//DEBUG:
	ft_putendl_fd("\ttred_handle_sig: Start", 2);
	//
	i = 0;
	flag = 0;
	while (i < size)
	{
		if (tab[i].type == TOK_SIG && !ft_strncmp(tab[i].str, "-", tab[i].size))
		{
			//DEBUG:
			ft_putstr_fd("\tred_handle_sig: '-' found at tab + ", 2);
			ft_putnbr_fd(i, 2);
			ft_putchar_fd('\n', 2);
			//
			flag = 1;
		}
		else if (tab[i].type == TOK_COEF && flag)
		{
			//DEBUG:
			ft_putstr_fd("\tred_handle_sig: tab + ", 2);
			ft_putnbr_fd(i, 2);
			ft_putendl_fd(" is negative", 2);
			//
			flag = 0;
			tab[i].val *= -1;
		}
		i++;
		//DEBUG:
		//ft_putendl_fd("\ttred_handle_sig: Increment i", 2);
		//
	}
}

int			cmp_reduce(t_dtab *dtab)
{
	t_tok		*tab;
	float		degree;
	int	eq;

	//DEBUG:
	ft_putendl_fd("cmp_reduce: debug: Start", 2);
	//
	eq = -1;
	degree = 0.0;
	tab = (t_tok *)dtab->data;
	eq = red_tokchr(tab, dtab->size, TOK_EQ);
	//DEBUG:
	ft_putstr_fd("cmp_reduce: debug: eq: ", 2);
	ft_putnbr_fd(eq, 2);
	ft_putchar_fd('\n', 2);
	//
	if (eq == ERR_RED)
		return (ERR_RED);
	red_handle_sig(tab, dtab->size);
	//DEBUG:
	ft_putendl_fd("cmp_reduce: debug: red_handle_sig: Ok", 2);
	//
	degree = red_handle_degree(tab, dtab->size);
	//DEBUG:
	ft_putstr_fd("cmp_reduce: debug: degree: ", 2);
	ft_putnbr_fd((int)degree, 2);
	ft_putchar_fd('\n', 2);
	//
	red_handle_coef(tab, dtab->size, &degree, eq);
	//DEBUG:
	ft_putendl_fd("cmp_reduce: debug: red_handle_coef: Ok", 2);
	//
	ft_putstr("Reduced form: ");
	red_handle_put(tab, dtab->size, eq, degree);
	//DEBUG:
	ft_putendl_fd("cmp_reduce: debug: red_handle_put: Ok", 2);
	//
	if (degree <= 2.0)
	{
		ft_putstr("Polynomial degree: ");
		ft_putnbr(degree);
		ft_putchar('\n');
	}
	else
		ft_putstr("Can't reduce\n");
	//DEBUG
	ft_putendl_fd("cmp_reduce: debug: red_put_degree: Ok", 2);
	//
	return (NO_ERR);
}
