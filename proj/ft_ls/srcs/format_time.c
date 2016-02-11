/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:59:53 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/11 18:00:09 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*fmt_yhm(t_ls_entry *e, char *buf)
{
	char			*cp;
	static time_t	now;
	time_t			d;

	if (now == 0)
		now = time(NULL);
	ft_bzero((void *)buf, 6);
	d = e->stat.st_mtimespec.tv_sec;
	if (((d + SIXMONTH) > now) && (d < (now + SIXMONTH)))
	{
		cp = ctime(&e->stat.st_mtimespec.tv_sec) + 11;
		ft_strncpy(buf, cp, 5);
	}
	else
	{
		cp = ctime(&e->stat.st_mtimespec.tv_sec) + 20;
		buf[0] = ' ';
		ft_strncpy(buf + 1, cp, 4);
	}
	return (buf);
}

char				*fmt_month(t_ls_entry *e, char *buf)
{
	char			*cp;

	ft_bzero((void *)buf, 6);
	cp = ctime(&e->stat.st_mtimespec.tv_sec) + 4;
	return (cp);
}

char				*fmt_day(t_ls_entry *e, char *buf)
{
	char			*cp;

	ft_bzero((void *)buf, 6);
	cp = ctime(&e->stat.st_mtimespec.tv_sec) + 8;
	return (cp);
}
