#include "ft_ls.h"

static void			debug_dump_opt(int *opt)
{
	ft_printf("OPT: ");
	if (*opt)
		ft_printf("a");
	if (*(opt + 1))
		ft_printf("l");
	if (*(opt + 2))
		ft_printf("r");
	if (*(opt + 3))
		ft_printf("R");
	if (*(opt + 4))
		ft_printf("t");
	ft_printf("\n");
}

void				ft_ls_fic_handle(int ac, char **av)
{
	struct stat		entry_info;
	int				i;

	i = 0;
	while (++i < ac)
	{
		if (*av[i] == '-' || !*av[i])
			continue ;
		/*
		 *	Clean stat
		*/
		ft_bzero((void *)&entry_info, sizeof(struct stat));
		/*
		 *	If there is a fic print it
		*/
		if (stat(av[i], &entry_info) == -1)
			ft_ls_put_error_entry(av[i], errno);
		else if ((entry_info.st_mode & S_IFDIR) != S_IFDIR)
		{
			ft_printf("%s\n", av[i]);
			*av[i] = 0;
		}
	}
}

void				ft_ls_error_handle(int ac, char **av)
{
	struct stat		entry_info;
	int				i;

	i = 0;
	while (++i < ac)
	{
		if (*av[i] == '-')
			continue ;
		/*
		 *	Clean stat
		*/
		ft_bzero((void *)&entry_info, sizeof(struct stat));
		/*
		 *	If there is an error call put err
		*/
		if (stat(av[i], &entry_info) == -1)
		{
			ft_ls_put_error_entry(av[i], errno);
			*av[i] = 0;
		}
	}
}

int		main(int ac, char *av[])
{
	int	opt[OPT_SIZE];

	ft_bzero((void *)opt, sizeof(int) * OPT_SIZE);
	/*
	 *	set opt array while av
	*/
	if (get_opt(OPT_CSET, opt, ac, av))
		return (0);
	/*
	 *	dump opt array
	*/
	debug_dump_opt(opt);
	/*
	 *	print error in arg
	*/
	if (!(lav = ft_ls_sort_av(opt, ac, av)))
		return ;
	ft_ls_error_handle(lav);
	ft_ls_fic_handle(lav);
	ft_ls(opt, lav);
	return (0);
}
