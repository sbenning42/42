/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 08:50:54 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/16 15:47:11 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_node	*noarg_tree(void)
{
	t_ls_entry	e;

	ft_bzero((void *)&e, sizeof(t_ls_entry));
	e.type = T_DIR;
	ft_strncpy(e.key, ".", KEYSIZE_LS);
	ft_strncpy(e.path, ".", KEYSIZE_LS);
	if (lstat(e.key, &e.stat) == -1)
		return (NULL);
	return (tree_newnode((void *)&e, sizeof(t_ls_entry)));
}

static t_node	*argv_woo_tree(int ac, int i, char **av, int o)
{
	t_node		*root;
	t_node		*no;
	t_ls_entry	e;

	root = NULL;
	while ((errno = 0) || (i < ac))
	{
		ft_bzero((void *)&e, sizeof(t_ls_entry));
		ft_strcpy(e.key, av[i]);
		//ft_strcpy(e.path, "./");
		ft_strcat(e.path, e.key);
		errno = 0;
		if (lstat(av[i], &e.stat) == -1)
			e.type = T_ERROR;
		else
			e.type = ((e.stat.st_mode & S_IFDIR) == S_IFDIR ? T_DIR : T_NODIR);
		if (!(no = tree_newnode((void *)&e, sizeof(t_ls_entry))))
		{
			tree_del(&root, NULL);
			return ((void *)(long)ft_err(ft_name(av[0]), "Error", "Memory allocation failed", 0));
		}
		tree_add(&root, no, ls_select_argvsort(o));
		i++;
	}
	return (root);
}

t_node		*argv_tree(int ac, char **av, int *o)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (*av[i] != '-')
			break ;
	}
	if (i == ac)
		return (noarg_tree());
	else if (i + 1 != ac)
	{
		*o |= O_PRIVATE_MULTI;
		ls_env()->o = *o;
	}
	return (argv_woo_tree(ac, i, av, *o));
}
