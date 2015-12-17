#include "ft_ls.h"

t_env				*env(void)
{
	static t_env	e;

	return (&e);
}

void				ls_argv(void *p, size_t size)
{
	t_ls_entry		*e;
	void			(*print)(void *, size_t);
	
	e = (t_ls_entry *)p;
	(void)size;
	print = ls_select_print(env()->o);
	if (e->type == T_ERROR)
		ft_err(env()->av, e->name, e->msg, 0);
	else if (e->type == T_FILE)
	{
		env()->i++;
		print((void *)e, sizeof(t_ls_entry));
	}
	else
		ls_dir((void *)e, sizeof(t_ls_entry));
}

static int			ft_put_usage(char e)
{
	ft_fprintf(2, FMT_U1, env()->av, "illegal option", e);
	ft_fprintf(2, FMT_U2, "usage", env()->av, CSET_O, "file ...");
	return (0);
}

int					main(int ac, char *av[])
{
	t_node			*root;
	char			e;

	e = 0;
	env()->i = 0;
	env()->av = ft_name(av[0]);
	env()->o = get_opt(CSET_O, ac, av, &e);
	if ((env()->o & O_VERBOSE) == O_VERBOSE)
		verbose_get_opt();
	if ((env()->o & O_PRIVATE_ERROR) == O_PRIVATE_ERROR)
		return (ft_put_usage(e));
	if ((root = argv_tree(ac, av)))
	{
		tree_doinf(root, ls_argv);
		tree_del(&root, NULL);
	}
	return (0);
}
