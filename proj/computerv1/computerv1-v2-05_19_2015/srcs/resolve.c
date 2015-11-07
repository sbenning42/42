#include "computerv1.h"

void		cmp_resolve_sqr(t_dis *delta)
{
	float	x1;
	float	x2;
	float	root;
	char	val[32];

	x1 = 0.0;
	x2 = 0.0;
	root = mt_fsqrt(delta->dis);
	if (delta->dis > 0)
	{
		x1 = (-1 * delta->tcoef[1] - root) / (2 * delta->tcoef[2]);
		x2 = (-1 * delta->tcoef[1] + root) / (2 * delta->tcoef[2]);
		ft_putendl("The discriminent is stricly positive, there is two real solutions:");
		if (x1 < 0)
			ft_putchar('-');
		ft_ftoa(ABS(x1), val, 6);
		ft_putendl(val);
		if (x2 < 0)
			ft_putchar('-');
		ft_ftoa(ABS(x2), val, 6);
		ft_putendl(val);
	}
	else if (delta->dis == 0.0)
	{
		x1 = (-1 * delta->tcoef[1]) / 2 * delta->tcoef[2];
		ft_putendl("The discriminent is stricly null, there is a unique real solution:");
		if (x1 < 0)
			ft_putchar('-');
		ft_ftoa(ABS(x1), val, 6);
		ft_putendl(val);

	}
	else
	{
		ft_putendl("The discriminent is stricly negative, there is two complexes solutions:");
		x1 = (-1 * delta->tcoef[1]) / (2 * delta->tcoef[2]);
		x2 = (mt_fsqrt(ABS(delta->dis))) / (2 * delta->tcoef[2]);
		if (x1 < 0)
			ft_putchar('-');
		ft_ftoa(ABS(x1), val, 6);
		ft_putstr(val);
		ft_putstr(" +i * ");
		ft_ftoa(ABS(x2), val, 6);
		ft_putendl(val);
		if (x1 < 0)
			ft_putchar('-');
		ft_ftoa(ABS(x1), val, 6);
		ft_putstr(val);
		ft_putstr(" -i * ");
		ft_ftoa(ABS(x2), val, 6);
		ft_putendl(val);
	}
}

void		cmp_resolve_sim(t_dis *delta)
{
	char	val[32];
	float	res;

	ft_putendl("The solution is:");
	res = (delta->tcoef[0] * -1) / delta->tcoef[1];
	ft_ftoa(ABS(res), val, 6);
	if (res < 0)
		ft_putchar('-');
	ft_putendl(val);
}

void		cmp_resolve_all(void)
{
	ft_putendl("All member of Real are solution of the equation");
}

void		cmp_discriminent(t_dtab *dtab, t_dis *delta)
{
	unsigned int	i;
	int		flag[3];
	float		coef;
	t_tok		*tab;

	i = 0;
	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	tab = (t_tok *)dtab->data;
	while (i < dtab->size)
	{
		if (tab[i].type == TOK_COEF)
			coef = tab[i].val;
		else if (tab[i].type == TOK_EXP && tab[i].val < 3)
		{
			if (!flag[(int)tab[i].val])
			{
				flag[(int)tab[i].val] = 1;
				delta->tcoef[(int)tab[i].val] = coef;
			}
		}
		i++;
	}
	delta->dis = (delta->tcoef[1] * delta->tcoef[1] - 4 * delta->tcoef[0] * delta->tcoef[2]);
}
