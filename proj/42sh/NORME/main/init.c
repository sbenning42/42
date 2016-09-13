/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 08:42:11 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 14:46:55 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int			bin_create(t_dic_entry **root, char *path)
{
	DIR				*bpath;
	struct dirent	*entry;
	t_dic_entry		*node;
	size_t			len;

	if (!(bpath = opendir(path)))
		return (-1);
	len = ft_strlen(path) + 1;
	while ((entry = readdir(bpath)))
	{
		if (!(node = ft_dicnew(entry->d_name, (void *)path, len)))
		{
			closedir(bpath);
			return (-1);
		}
		ft_dicadd(root, node, dic_sort);
	}
	closedir(bpath);
	return (0);
}

static int			bin_load_path(t_dic_entry **root, char *path)
{
	char			*find;

	while (*path)
	{
		if ((find = ft_strchr(path, ':')))
			*find = '\0';
		if (bin_create(root, path) < 0)
			return (-1);
		if (!find)
			break ;
		path = find + 1;
	}
	return (0);
}

static int			bin_load(t_dic_entry **root)
{
	char			*raw_path;
	char			*path;
	int				ret;

	if (!(raw_path = ft_getenv("PATH")))
		return (-1);
	if (!(raw_path = ft_strdup(raw_path)))
		return (-1);
	path = raw_path;
	ret = bin_load_path(root, path);
	if (ret < 0)
	{
		if (*root)
			ft_dicdel(root, NULL);
	}
	ft_memdel((void **)&raw_path);
	return (ret);
}

void				sh_init(t_sh *sh, int ac, char **av)
{
	int				i;

	sh->bin = NULL;
	if ((sh->o = ft_getopt(ac, av, SH_OPTION)) < 0)
		exit(EXIT_FAILURE);
	if (bin_load(&sh->bin) < 0)
		ft_error("loading binary... Fail");
	if (hist_load(&sh->hist) < 0)
		ft_error("loading history... Fail");
	if (ISO(sh->o, SH_O_PROMPT))
	{
		i = 0;
		while (++i < ac)
		{
			if (av[i][0] != '-')
				break ;
		}
		sh->prompt = av[i];
	}
	else
		sh->prompt = SH_DEFAULT_PROMPT;
	sh->settings = SH_DEFAULT_SETTINGS;
}
