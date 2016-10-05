/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 14:54:30 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/15 14:59:42 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"

t_dlist			*makelst(char *path)
{
	char		*start;
	t_dlist		*lst;
	t_dlist		*elem;

	lst = NULL;
	start = ++path;
	while (*path)
	{
		if (*path == '/')
		{
			if (*start != '/')
			{
				elem = ft_dlstnew((void *)start, sizeof(char) * (path - start));
				if (!elem)
					return (NULL);
				ft_dlstaddn(&lst, elem);
			}
			start = path + 1;
		}
		path++;
	}
	return (lst);
}

t_dlist			*cleanlst(t_dlist *e)
{
	if (e->content_size == 1 && *(char *)e->content == '.')
		return (ft_dlstnew(NULL, 0));
	return (ft_dlstnew(e->content, e->content_size));
}

t_dlist			*cleanlstparent(t_dlist *lst)
{
	t_dlist		*drive;
	t_dlist		*tmp;

	drive = lst;
	while (drive)
	{
		if (drive->content_size == 2\
			&& *(char *)drive->content == '.'\
			&& *((char *)drive->content + 1) == '.')
		{
			ft_memdel((void **)&drive->content);
			tmp = drive->p;
			while (tmp)
			{
				if (tmp->content)
				{
					ft_memdel((void **)&tmp->content);
					break ;
				}
				tmp = tmp->p;
			}
		}
		drive = drive->n;
	}
	return (lst);
}

char			*convertlst(t_dlist **alst)
{
	char		path[2048];
	t_dlist		*drive;

	ft_bzero((void *)path, 2048);
	drive = *alst;
	while (drive)
	{
		if (drive->content)
		{
			ft_strcat(path, "/");
			ft_strncat(path, (char *)drive->content, drive->content_size);
		}
		drive = drive->n;
	}
	ft_dlstdel(alst, NULL);
	return (ft_strdup(path));
}
