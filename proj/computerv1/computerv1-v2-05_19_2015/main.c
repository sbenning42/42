#include "computerv1.h"


static void		cmp_initdis(t_dis *delta)
{
	delta->tcoef[0] = 0.0;
	delta->tcoef[1] = 0.0;
	delta->tcoef[2] = 0.0;
}

int			main(int ac, char **av)
{
	int		i;
	int		end;
	t_dtab		dtab;
	t_dis		delta;
	
	if (ac < 2)
		return (ft_putchar('\n'));
	i = 1;
	while (i < ac)
	{
		end = 0;
		if (!dtab_init(&dtab, OFFSET, sizeof(t_tok)))
		{
			ft_putendl("Malloc error in dynamic array library");
			return (, 1);
		}
		else if (!cmp_parse(&dtab, av[i++]))
			return (ft_putendl("LEX ERR"), 1);
		else if (!cmp_reduce(&dtab, &end))
			return (ft_putendl("PAR ERR"), 1);
		if (end)
			continue ;
		cmp_initdis(&delta);
		cmp_discriminent(&dtab, &delta);
		if (delta.tcoef[2])
			cmp_resolve_sqr(&delta);
		else if (delta.tcoef[1])
			cmp_resolve_sim(&delta);
		else
			cmp_resolve_all();
		dtab_del(&dtab);
	}
	return (write(1, "\n", 1));
}
