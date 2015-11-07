#include "ft_ls.h"

int		ft_ls(int *opt, int ac, char *av, int i)
{
}

int		main(int arg_c, char *arg_v[])
{
	int	opt[NOPT];
	int	i;

	i = get_opt("a:l:r:R:t", opt, ac, av);
	if (i == ac)
		ft_ls(opt, 0, NULL, 0)
	else
		ft_ls(opt, ac, av, i)
	return (0);
}
