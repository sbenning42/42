#include "ft_ls.h"

static static int	(*get_avsort(int o))(t_node *, t_node *)
{
	int		(*s)(t_node *, t_node *);

	s = avs_lex;
	if ((o & (O_TIME | O_REVE)))
	{
		s = ((o & (O_TIME | O_REVE)) == O_TIME ? avs_time : s);
		s = ((o & (O_TIME | O_REVE)) == O_REVE ? avs_rlex : s);
		s = ((o & (O_TIME | O_REVE)) == (O_TIME | O_REVE) ? avs_rtime : s);
	}
	return (s);
}

static void	(*get_avprint(int o))(t_node *)
{
	void	(*p)(t_node *);

	p = avp_print;
	if ((o & (O_COLOR | O_LONG)) == (O_COLOR | O_LONG))
	{
		p = ((o & (O_COLOR | O_LONG)) == O_COLOR ? avp_cprint : p);
		p = ((o & (O_COLOR | O_LONG)) == O_LONG ? avp_lprint : p);
		p = ((o & (O_COLOR | O_LONG)) == (O_COLOR | O_LONG) ? avp_clprint : p);
	}
	return (p);
}

static int	(*get_sort(int o))(t_node *, t_node *)
{
	int		(*s)(t_node *, t_node *);

	s = s_lex;
	if ((o & (O_TIME | O_REVE)))
	{
		s = ((o & (O_TIME | O_REVE)) == O_TIME ? s_time : s);
		s = ((o & (O_TIME | O_REVE)) == O_REVE ? s_rlex : s);
		s = ((o & (O_TIME | O_REVE)) == (O_TIME | O_REVE) ? s_rtime : s);
	}
	return (s);
}

static void	(*get_print(int o))(t_node *)
{
	void	(*p)(t_node *);

	p = p_print;
	if ((o & (O_COLOR | O_LONG)) == (O_COLOR | O_LONG))
	{
		p = ((o & (O_COLOR | O_LONG)) == O_COLOR ? p_cprint : p);
		p = ((o & (O_COLOR | O_LONG)) == O_LONG ? p_lprint : p);
		p = ((o & (O_COLOR | O_LONG)) == (O_COLOR | O_LONG) ? p_clprint : p);
	}
	return (p);
}

int			main(int ac, char *av[])
{
	t_ls_func	f;
	int		o;
	char	e;

	e = '\0';
	o = get_opt(CSET_O, ac, av, &e);
	f.av_s = get_avsort(o);
	f.av_p = get_avprint(o);
	f.s = get_sort(o);
	f.p = get_print(o);
	if ((o & O_VERBOSE) == O_VERBOSE)
	{
		verbose_get_opt(o, av[0]);
		verbose_get_avsort(s, av[0]);
		verbose_get_avprint(s, av[0]);
	}
	if ((o & O_PRIVATE_ERROR) == O_PRIVATE_ERROR)
		return (ft_put_usage(av[0], e));
	if (ac > 2)
		o |= O_PRIVATE_MULTI;
	ft_avls(ac, av, o, f);
	return (0);
}
