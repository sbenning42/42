#include "ft_ls.h"

t_ls_env	*ls_env(void)
{
	static t_ls_env	e;

	return (&e);
}

void		ls_argv(void *p, size_t size)
{
	t_ls_entry	*e;
	void		(*print)(void *, size_t);
	
	e = (t_ls_entry *)p;
	(void)size;
	print = ls_select_print(ls_env()->o);
	if (e->type == T_ERROR)
		ft_err("ft_ls", e->key, "No such file or directory", 0);
	else if (e->type == T_NODIR)
	{
		ls_env()->i++;
		print((void *)e, sizeof(t_ls_entry));
	}
	else
		ls_dir((void *)e, sizeof(t_ls_entry));
}

int	ft_put_usage(char *av, char e)
{
	ft_fprintf(2, FMT_U1, ft_name(av), "illegal option", e);
	ft_fprintf(2, FMT_U2, "usage", ft_name(av), CSET_O, "file ...");
	return (0);
}

int			main(int ac, char *av[])
{
	t_node	*root;
	int		o;
	char	e;

	e = '\0';
	o = get_opt(CSET_O, ac, av, &e);
	ls_env()->av = av[0];
	ls_env()->o = o;
	ls_env()->i = 0;
	root = argv_tree(ac, av, &o);
	if ((o & O_VERBOSE) == O_VERBOSE)
		verbose_get_opt(o, av[0]);
	if ((o & O_PRIVATE_ERROR) == O_PRIVATE_ERROR)
		return (ft_put_usage(av[0], e));
	tree_doinf(root, ls_argv);
	tree_del(&root, NULL);
	return (0);
}
