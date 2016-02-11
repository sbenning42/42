/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:17:20 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/11 16:10:51 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	ft_bzero((void *)env()->path, PATHSIZE_LS);
	e = (t_ls_entry *)p;
	(void)size;
	print = g_ls_select_print(env()->o);
	if (e->type == T_ERROR)
		ft_fprintf(2, "%s: %s: %s\n", env()->av, e->name, e->msg);
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

static void			ini_env(void)
{
	env()->i = 0;
	env()->nlinkpad = 0;
	env()->sizepad = 0;
	env()->ownerlen = 0;
	env()->grplen = 0;
}

int					main(int ac, char *av[])
{
	t_node			*root;
	char			e;

	ini_env();
	env()->av = ft_name(av[0]);
	e = 0;
	env()->o = get_opt(CSET_O, ac, av, &e);
	if (IS(O_PRIVATE_ERROR, env()->o))
		return (ft_put_usage(e));
	if ((root = argv_tree(ac, av)))
	{
		tree_doinf(root, ls_argv);
		tree_del(&root, NULL);
	}
	return (0);
}
