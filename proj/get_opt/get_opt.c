#include "get_opt.h"

void		print_opt(char *cs, int *opt)
{
	int	id;

	id = 0;
	while (*cs)
	{
		if (*cs == ':')
		{
			id++;
			cs++;
			continue ;
		}
		else if (opt[id])
			ft_printf("%[Gr|Gree]c", *cs);
		else
			ft_printf("%[Gr|Red]c", *cs);
		cs++;
		if (*cs)
			ft_printf(":");
	}
	ft_printf("\n");
}

static void	err_opt(char c, char *cs)
{
	ft_printf("%s: Error '%c'\nUsage: %s -[%s] [...]\n", GO_NAME, c, GO_NAME, cs);
	exit(0);
}

static size_t	len_opt(char *cs)
{
	size_t	c;
	size_t	i;

	i = 0;
	c = i;
	while (cs[i])
	{
		if (cs[i] != ':')
			c++;
		i++;
	}
	return (c);
}

static void	get_av_opt(char *cs, char *av, int *opt)
{
	char	*cp;
	int	id;

	cp = cs;
	while (*av)
	{
		id = 0;
		while (*cs)
		{
			if (*cs == ':')
				id++;
			else if (*av == *cs)
			{
				opt[id] = 1;
				break ;
			}
			cs++;
		}
		if (!*cs)
			err_opt(*av, cp);
		cs = cp;
		av++;
	}
}

int		get_opt(char *cs, int *opt, int ac, char **av)
{
	int	i;

	i = 1;
	ft_bzero((void *)opt, sizeof(int) * len_opt(cs));
	while (i < ac)
	{
		if (*av[i] != '-')
			break ;
		get_av_opt(cs, av[i++] + 1, opt);
	}
	return (i);
}
