/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:56:35 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/11 17:59:00 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*fmt_owner(t_ls_entry *e)
{
	return (getpwuid(e->stat.st_uid)->pw_name);
}

char		*fmt_group(t_ls_entry *e)
{
	return (getgrgid(e->stat.st_gid)->gr_name);
}

int			fmt_nblink(t_ls_entry *e)
{
	return (e->stat.st_nlink);
}

int			fmt_size(t_ls_entry *e)
{
	return (e->stat.st_size);
}

char		*fmt_link(t_ls_entry *e, char *buf)
{
	char	absname[PATHSIZE_LS + 1];

	ft_bzero((void *)buf, LINKSIZE_LS + 1);
	ft_bzero((void *)absname, PATHSIZE_LS + 1);
	ft_strcpy(absname, env()->path);
	ft_strcat(absname, "/");
	ft_strcat(absname, e->name);
	if (readlink(absname, buf, (size_t)LINKSIZE_LS) > 0)
		ft_err(env()->av, e->name);
	return (buf);
}
