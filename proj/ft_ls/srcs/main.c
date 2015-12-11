#include "ft_ls.h"

static int	ft_put_usage(char *av, char e)
{
	char	*id;

	ft_fprintf(2, U1FMT, NAME(av, id), "illegal option", e);
	ft_fprintf(2, U2FMT, "usage", NAME(av, id), O_CSET, UMSG);
	return (0);
}

static void	verbose_get_opt(int o, char *av)
{
	char	*ostr[O_SIZE + 1];
	char	*id;
	int		i;
	int		flag;

	ostr[0] = "Illegal";
	ostr[1] = "Hide";
	ostr[2] = "Long";
	ostr[3] = "Recursif";
	ostr[4] = "Reverse";
	ostr[5] = "Time";
	ostr[6] = "Verbose";
	ft_printf(OFMT, NAME(av, id), VERBOSEID, "option(s)");
	i = 0;
	flag = 0x1;
	while (flag < MAX_O)
	{
		if (((o & flag) == flag) && (flag != PRIV_ERROR_O))
			ft_printf("[{cyan|gr}%s{eoc}] ", ostr[i]);
		else if (((o & flag) == flag) && (flag == PRIV_ERROR_O))
			ft_printf("[{red|gr|ss}%s{eoc}] ", ostr[i]);
		i++;
		flag <<= 0x1;
	}
	ft_printf("\n");
}

int			main(int ac, char *av[])
{
	int		(*s)(void *, void *);
	char	*id;
	int		o;
	char	e;

	e = '\0';
	o = get_opt(O_CSET, ac, av, &e);
	if ((o & VERBOSE_O) == VERBOSE_O)
		verbose_get_opt(o, av[0]);
	if ((o & PRIV_ERROR_O) == PRIV_ERROR_O)
		return (ft_put_usage(av[0], e));
	s = s_lex;
	if ((o & (TIME_O | REVE_O)))
	{
		s = ((o & (TIME_O | REVE_O)) == TIME_O ? s_time : s);
		s = ((o & (TIME_O | REVE_O)) == REVE_O ? s_rlex : s);
		s = ((o & (TIME_O | REVE_O)) == (TIME_O | REVE_O) ? s_rtime : s);
	}
	ft_ls_wopt(ac, av, o, s);
	ft_printf(((o & VERBOSE_O) == VERBOSE_O ? MASFMT : ""), ARGMAS);
	return (0);
}
