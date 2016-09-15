/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 08:42:11 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/15 12:11:49 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int			bin_create(t_dic_entry **root, char *path)
{
	DIR				*bpath;
	struct dirent	*entry;
	t_dic_entry		*node;
	size_t			len;

	if (!(bpath = opendir(path)))												//Open the entry path
		return (-1);
	len = ft_strlen(path) + 1;
	while ((entry = readdir(bpath)))											//For all entries in path
	{
		if (!(node = ft_dicnew(entry->d_name, (void *)path, len)))
		{
			closedir(bpath);
			return (-1);
		}
		ft_dicadd(root, node, dic_sort);										//Add a couple 'name'+'path' as a KEY+VALUE in the 'root' dictionnary
	}
	closedir(bpath);
	return (0);
}

static int			bin_load_path(t_dic_entry **root, char *path)
{
	char			*find;

	while (*path)
	{
		if ((find = ft_strchr(path, ':')))										//Split on ':'
			*find = '\0';
		if (bin_create(root, path) < 0)											//Get the binary collection pointed by a entry in the ENVIRON PATH
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

	if (!(raw_path = ft_getenv("PATH")))										//Get the ENVIRON PATH
		return (-1);
	if (!(raw_path = ft_strdup(raw_path)))										//Duping it so it can be modified
		return (-1);
	path = raw_path;
	ret = bin_load_path(root, path);											//Load the binary collection pointed by path
	if (ret < 0)
	{
		if (*root)																//If an error occurs, clean memory if necessary
			ft_dicdel(root, NULL);
	}
	ft_memdel((void **)&raw_path);
	return (ret);
}

void				sh_init(t_sh *sh, int ac, char **av)
{
	int				i;

	sh->bin = NULL;
	if ((sh->o = ft_getopt(ac, av, SH_OPTION)) < 0)								//Extract option from arg_v
		exit(EXIT_FAILURE);
	if (bin_load(&sh->bin) < 0)													//Parse the ENVIRON PATH and open it to load the binary collection (KEY=name, VALUE=path)
		ft_error("loading binary... Fail");
	if (hist_load(&sh->hist) < 0)												//Parse '.42sh_history' to load all past command
		ft_error("loading history... Fail");
	if (ISO(sh->o, SH_O_PROMPT))												//If '-p' specified in arg_v, get the specified prompt name also in arg_v
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
		sh->prompt = SH_DEFAULT_PROMPT;											//Or set it to it's default value
	sh->settings = SH_DEFAULT_SETTINGS;											//Set the default ft_readline settings
}
