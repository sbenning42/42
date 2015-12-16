/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 10:56:53 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/16 15:48:39 by sbenning         ###   ########.fr       */
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
		return (ft_err(ft_name(ls_env()->av), "Error", "Memory allocation failed", 0));
	tree_add(ar, no, ls_select_sort(o));
	return (1);
}

char		*ft_rname(char *n)
{
	char	*f;

	f = ft_strchr(n, '/');
	if (!f || f == n)
		return (n);
	return (f + 1);
}

void			ls_dir(void *p, size_t size)
{
	t_ls_entry	*e;
	int		o;
	t_node	*root;
	DIR		*dir;
	struct dirent	*entry;

	e = (t_ls_entry *)p;
	o = ls_env()->o;
	if (e->type != T_DIR || ((o & O_HIDE) == 0 && e->key[0] == '.') || ((!ft_strcmp(".", e->key) && ft_strcmp(".", e->path)) || (!ft_strcmp("..", e->key) && ft_strcmp("..", e->path))))
		return /*(NULL)*/;
	if ((o & O_PRIVATE_MULTI) == O_PRIVATE_MULTI && e->type == T_DIR)
	{
		ft_printf((ls_env()->i++ ? "\n%s:\n" : "%s:\n"), e->path);
	}
	if (!(dir = opendir(e->path)))
	{
		ft_err(ft_name(ls_env()->av), e->key, (errno ? strerror(errno) : "Can't open dir"), 0);
		errno = 0;
		return /*(NULL)*/;
	}
	root = NULL;
	while ((entry = readdir(dir)))
	{
		if (!entry_tree(&root, entry, e->path, o))
		{
			tree_del(&root, NULL);
			return /*(NULL)*/;
		}
	}
	closedir(dir);
	tree_doinf(root, ls_select_print(o));
	if ((o & O_RECU) == O_RECU)
	{
		ls_env()->o |= O_PRIVATE_MULTI;
		ls_env()->i++;
		tree_doinf(root, ls_dir);
	}
	tree_del(&root, NULL);
	(void)size;
//	return (root);
}
