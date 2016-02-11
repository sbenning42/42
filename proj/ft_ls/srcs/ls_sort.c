/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:18:00 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/11 16:26:01 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		s_lex(void *s1, void *s2)
{
	t_ls_entry	*e1;
	t_ls_entry	*e2;

	e1 = (t_ls_entry *)s1;
	e2 = (t_ls_entry *)s2;
	return ((ft_strcmp(e1->name, e2->name) < 0));
}

int		s_rlex(void *s1, void *s2)
{
	t_ls_entry	*e1;
	t_ls_entry	*e2;

	e1 = (t_ls_entry *)s1;
	e2 = (t_ls_entry *)s2;
	return ((ft_strcmp(e1->name, e2->name) > 0));
}

int		s_modt(void *s1, void *s2)
{
	t_ls_entry	*e1;
	t_ls_entry	*e2;

	e1 = (t_ls_entry *)s1;
	e2 = (t_ls_entry *)s2;
	if (e1->stat.st_mtimespec.tv_sec - e2->stat.st_mtimespec.tv_sec > 0)
		return (1);
	else if (e1->stat.st_mtimespec.tv_sec - e2->stat.st_mtimespec.tv_sec < 0)
		return (0);
	else
		return (s_lex(s1, s2));
}

int		s_rmodt(void *s1, void *s2)
{
	t_ls_entry	*e1;
	t_ls_entry	*e2;

	e1 = (t_ls_entry *)s1;
	e2 = (t_ls_entry *)s2;
	if (e1->stat.st_mtimespec.tv_sec - e2->stat.st_mtimespec.tv_sec > 0)
		return (0);
	else if (e1->stat.st_mtimespec.tv_sec - e2->stat.st_mtimespec.tv_sec < 0)
		return (1);
	else
		return (s_rlex(s1, s2));
}
