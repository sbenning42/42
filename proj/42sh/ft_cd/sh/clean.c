/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 11:16:18 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 15:06:01 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"

static char			*clean(char *path, char *cpath)
{
	t_dlist			*lst;
	t_dlist			*clean;

	if (!(lst = makelst(cpath)))
	{
		ft_error("Memory allocation failed");
		return (NULL);
	}
	if (!(clean = ft_dlstmap(lst, cleanlst)))
	{
		ft_error("Memory allocation failed");
		return (NULL);
	}
	ft_dlstdel(&lst, NULL);
	clean = cleanlstparent(clean);
	return (convertlst(&clean));
	(void)path;
}

char				*cd_cleanpath(char *path)
{
	char			cpath[2048];
	char			*pref;

	if (!ft_strcmp("-", path))
		return (cd_oldpwd());
	else if (*path != '/')
	{
		if (!(pref = ft_getenv("PWD")))
		{
			ft_error("PWD missing");
			return (NULL);
		}
		ft_sprintf(cpath, "%s/%s/", pref, path);
	}
	else
		ft_sprintf(cpath, "%s/", path);
	return (clean(path, cpath));
}
