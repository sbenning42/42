/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 18:44:51 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/15 17:10:44 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

/*
***		Have to put an error msg in case of opendir failure
*/

static int			extract_binary(\
					char *path)
{
	t_dic			*entry;
	char			binpath[FT_SH_BINARY_PATH_SIZE + 1];
	DIR				*dir;
	struct dirent	*direntry;

	if (!(dir = opendir(path)))
	{
		opendir_error(path);
		return (1);
	}
	while ((direntry = readdir(dir)))
	{
		ft_bzero((void *)binpath, sizeof(char) * (FT_SH_BINARY_PATH_SIZE + 1));
		ft_strcpy(binpath, path);
		ft_strcat(binpath, "/");
		ft_strcat(binpath, direntry->d_name);
		if (!(entry = ft_dicnew(direntry->d_name, (void *)binpath\
						, sizeof(char) * (ft_strlen(binpath) + 1))))
		{
			closedir(dir);
			return (0);
		}
		ft_dicadd(&BINARY, entry, alpha_sort);
	}
	closedir(dir);
	return (1);
}

static void			free_paths(\
					char ***atab)
{
	char			**cp;

	cp = *atab;
	while (*cp)
	{
		ft_memdel((void **)cp);
		cp++;
	}
	ft_memdel((void **)atab);
}

static void			myprint(\
					t_dic *e)
{
	if (!e)
		return ;
	ft_printf((IS(O_COLOR, OPT) ? FMT_CBINARY : FMT_BINARY),\
			e->id, (char *)e->content);
}

void				dic_binary(\
					void)
{
	int				i;
	char			*path;
	char			**paths;

	BINARY = NULL;
	if (!(path = get_shenv("PATH")))
	{
		ft_fprintf(2, "No PATH in system environ...\n");
		return ;
	}
	paths = ft_strsplit(path, ':');
	i = 0;
	while (paths[i])
	{
		if (!extract_binary(paths[i]))
		{
			free_paths(&paths);
			binary_error();
		}
		i++;
	}
	free_paths(&paths);
	if (IS(O_DEBUG, OPT))
		ft_dicdoinf(BINARY, myprint);
}
