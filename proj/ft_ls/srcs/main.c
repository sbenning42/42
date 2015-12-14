#include "ft_ls.h"

static int	ft_put_usage(char *av, char e)
{
	ft_fprintf(2, FMT_U1, ft_name(av), "illegal option", e);
	ft_fprintf(2, FMT_U2, "usage", ft_name(av), CSET_O, "file ...");
	return (0);
}

static int	(*get_sort(int o))(void *, void *)
{
	int		(*s)(void *, void *);

	s = s_lex;
	if ((o & (O_TIME | O_REVE)))
	{
		s = ((o & (O_TIME | O_REVE)) == O_TIME ? s_time : s);
		s = ((o & (O_TIME | O_REVE)) == O_REVE ? s_rlex : s);
		s = ((o & (O_TIME | O_REVE)) == (O_TIME | O_REVE) ? s_rtime : s);
	}
	return (s);
}

int			main(int ac, char *av[])
{
	int		(*s)(void *, void *);
	int		o;
	char	e;

	e = '\0';
	o = get_opt(CSET_O, ac, av, &e);
	s = get_sort(o);
	if ((o & O_VERBOSE) == O_VERBOSE)
	{
		verbose_get_opt(o, av[0]);
		verbose_get_sort(s, av[0]);
	}
	if ((o & O_PRIVATE_ERROR) == O_PRIVATE_ERROR)
		return (ft_put_usage(av[0], e));
	ft_ls_wopt(ac, av, o, s);
	return (0);
}
