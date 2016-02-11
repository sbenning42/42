/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 10:56:53 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/11 18:21:03 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					entry_tree(t_node **ar, struct dirent *entry, \
						quad_t *blocks, int *i)
{
	char			absname[PATHSIZE_LS];
	t_ls_entry		e;
	t_node			*no;

	ft_strcpy(absname, env()->path);
	ft_strcat(absname, "/");
	ft_strcat(absname, entry->d_name);
	e = ls_newentry(entry->d_name, absname);
	if (entry->d_name[0] == '.' && !((env()->o & O_HIDE) == O_HIDE))
		e.handle = 0;
	if (e.handle)
	{
		*i += 1;
		*blocks += e.stat.st_blocks;
	}
	if (!ft_strcmp(entry->d_name, ".") || !ft_strcmp(entry->d_name, ".."))
		e.handle = 0;
	if (!(no = tree_newnode((void *)&e, sizeof(t_ls_entry))))
		return (ft_err(env()->av, absname));
	tree_add(ar, no, g_ls_select_sort(env()->o));
	maj_env(e);
	return (1);
}

t_node				*dir_tree(DIR *dir)
{
	t_node			*root;
	struct dirent	*entry;
	long long int	block;
	int				i;

	env()->nlinkpad = 0;
	env()->sizepad = 0;
	env()->ownerlen = 0;
	env()->grplen = 0;
	block = 0;
	i = 0;
	root = NULL;
	while ((entry = readdir(dir)))
	{
		if (!entry_tree(&root, entry, &block, &i))
		{
			tree_del(&root, NULL);
			return (NULL);
		}
	}
	ft_err(env()->av, env()->path);
	closedir(dir);
	if (((env()->o & O_LONG) == O_LONG) && (i > 0))
		ft_printf("total %lld\n", block);
	return (root);
}

static void			maj_path_wo_name(void)
{
	char			*f;

	if ((f = ft_strrchr(env()->path, '/')))
		*f = 0;
	if (!ft_strlen(env()->path))
		ft_strcpy(env()->path, "/");
}

static void			handle_path(char *name)
{
	if (!name)
		maj_path_wo_name();
	else
	{
		if (ft_strcmp(name, env()->path))
		{
			ft_strcat(env()->path, (env()->path[0] && \
					env()->path[ft_strlen(env()->path) - 1] != '/') ? "/" : "");
			ft_strcat(env()->path, name);
		}
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
	if (e->type != T_DIR || !e->handle || \
			(e->stat.st_mode & S_IFSOCK) == S_IFSOCK || \
			(e->stat.st_mode & S_IFLNK) == S_IFLNK)
		return ;
	handle_path(e->name);
	dir = opendir(env()->path);
	ft_err(env()->av, ft_name(env()->path));
	if (!dir)
		handle_path(NULL);
	else if (!(root = dir_tree(dir)))
		handle_path(NULL);
	else
	{
		tree_doinf(root, g_ls_select_print(env()->o));
		if ((env()->o & O_RECU) == O_RECU)
			tree_doinf(root, ls_dir);
		handle_path(NULL);
		tree_del(&root, NULL);
	}
	(void)size;
}
