/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 10:56:53 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/18 11:45:15 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			entry_tree(t_node **ar, struct dirent *entry, char *path, int o)
{
	struct stat	statbuf;
	t_ls_entry	e;
	t_node		*no;

	ft_strcpy(e.key, entry->d_name);
	ft_strcpy(e.path, path);
	if (e.path[ft_strlen(e.path) - 1] != '/')
		ft_strcat(e.path, "/");
	ft_strcat(e.path, e.key);
	if (lstat(e.path, &statbuf) == -1)
	{
		ft_printf("buf:[%s]\n", e.path);
		e.type = T_ERROR;
	}
	else
	{
		e.stat = statbuf;
		e.type = ((statbuf.st_mode & S_IFDIR) == S_IFDIR ? T_DIR : T_NODIR);
	}
	if (!(no = tree_newnode((void *)&e, sizeof(t_ls_entry))))
		return (ft_err(ft_name(env()->av), "Error", "Memory allocation failed", 0));
	tree_add(ar, no, ls_select_sort(o));
	return (1);
}
/*
char		*ft_rname(char *n)
{
	char	*f;

	f = ft_strchr(n, '/');
	if (!f || f == n)
		return (n);
	return (f + 1);
}
*/
void				ls_rec(t_node *root, int o)
{
	if ((o & O_RECU) == O_RECU)
	{
		env()->o |= O_PRIVATE_MULTI;
		env()->i++;
		tree_doinf(root, ls_dir);
	}
}

t_node				*dir_tree(t_ls_entry *e, int o, DIR *dir)
{
	t_node			*root;
	struct dirent	*entry;

	root = NULL;
	while ((entry = readdir(dir)))
	{
		if (!entry_tree(&root, entry, e->path, o))
		{
			tree_del(&root, NULL);
			return (NULL);
		}
	}
	closedir(dir);
	return (root);
}

int					must_return(t_ls_entry *e, int o)
{
	if (e->type != T_DIR)
		return (1);
	else if (e->key[0] == '.' && !((o & O_HIDE) == O_HIDE))
		return (1);
	else if (!ft_strcmp(".", e->key) && ft_strcmp(".", e->path))
		return (1);
	else if (!ft_strcmp("..", e->key) && ft_strcmp("..", e->path))
		return (1);
	return (0);
}

static void			handle_path(char *name)
{
	char			*f;

	if (!name)
	{
		f = ft_strrchr(env()->path, '/');
		if (f)
			*f = 0;
	}
	else
	{
		ft_strcat(env()->path, "/");
		ft_strcat(env()->path, name);
		if (env()->i > 0)
		{
			if (env()->i == 1)
				ft_printf("%s:\n", env()->path);
			else
				ft_printf("\n%s:\n", env()->path);
		}
		env()->i++;
	}
}

void				ls_dir(void *p, size_t size)
{
	t_ls_entry		*e;
	t_node			*root;
	DIR				*dir;

	e = (t_ls_entry *)p;
	if (e->type != T_DIR || !e->handle)
		return ;
	handle_path(e->name);
	dir = opendir(env()->path);
	ft_err(env()->av, env()->path);
	if (!dir)
		return ;
	if (!(root = dir_tree(e, env()->o, dir)))
		return ;
	tree_doinf(root, ls_select_print(env()->o));
	ls_rec(root, env()->o);
	handle_path(NULL);
	tree_del(&root, NULL);
	(void)size;
}
