/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cleanpath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 09:53:32 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/15 14:58:43 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"

static char		*prec_path(int *prec)
{
	char		*path;

	if (!(path = ft_getenv("OLDPWD")))
	{
		cd_exit("OLDPWD needed in the environ");
		return (NULL);
	}
	*prec = 1;
	return (ft_strdup(path));
}

static int		relative_clean(char *cpath, char *path)
{
	char		*pref;

	if (!(pref = ft_getenv("PWD")))
	{
		cd_exit("PWD needed in the environ");
		return (-1);
	}
	ft_sprintf(cpath, "%s/%s/", pref, path);
	return (0);
}

char			*cd_cleanpath(char *path, int *prec)
{
	t_dlist		*lst;
	t_dlist		*clean;
	char		cpath[2048];

	if (!path)
		return (NULL);
	if (!ft_strcmp("-", path))
		return (prec_path(prec));
	else if (*path != '/')
	{
		if (relative_clean(cpath, path))
			return (NULL);
	}
	else if (!ft_strcmp("/", path))
		return (ft_strdup("/"));
	else
		ft_sprintf(cpath, "%s/", path);
	if (!(lst = makelst(cpath)))
		return (NULL);
	if (!(clean = ft_dlstmap(lst, cleanlst)))
		return (NULL);
	ft_dlstdel(&lst, NULL);
	clean = cleanlstparent(clean);
	return (convertlst(&clean));
}
