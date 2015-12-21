/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 08:50:54 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/21 17:53:14 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls_entry			ls_newentry(char *name, char *absname)
{
	t_ls_entry		e;

	ft_bzero((void *)&e, sizeof(t_ls_entry));
	e.handle = 1;
	ft_strncpy(e.name, name, NAMESIZE_LS);
	errno = 0;
	lstat(absname, &e.stat);
	if (errno)
	{
		e.type = T_ERROR;
		e.msg = strerror(errno);
		errno = 0;
		return (e);
	}
	if ((e.stat.st_mode & S_IFDIR) == S_IFDIR)
		e.type = T_DIR;
	else
		e.type = T_FILE;
	/*f ((e.stat.st_mode & S_IFLNK) == S_IFLNK)
		lstat(absname, &e.stat);
	*/return (e);
}

static t_node		*argv_woa_tree()
{
	t_ls_entry		e;

	e = ls_newentry(".", ".");
	return (tree_newnode((void *)&e, sizeof(t_ls_entry)));
}

static t_node	*argv_wa_tree(int ac, int i, char **av)
{
	int				(*s)(void *, void *);
	t_node			*root;
	t_node			*no;
	t_ls_entry		e;

	root = NULL;
	s = ls_select_argvsort(env()->o);
	while (i < ac)
	{
		e = ls_newentry(av[i], av[i]);
		errno = 0;
		if (!(no = tree_newnode((void *)&e, sizeof(t_ls_entry))))
		{
			ft_err(env()->av, av[i]);
			errno = 0;
			tree_del(&root, NULL);
			return (NULL);
		}
		tree_add(&root, no, s);
		i++;
	}
	return (root);
}

t_node				*argv_tree(int ac, char **av)
{
	int				i;

	i = 0;
	while (++i < ac)
	{
		if (*av[i] != '-' || ft_strlen(av[i]) == 1)
			break ;
	}
	if (i + 1 < ac)
		env()->i++;
	return ((i == ac ? argv_woa_tree() : argv_wa_tree(ac, i, av)));
}
