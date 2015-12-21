/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 21:48:40 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/21 04:34:27 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	fmt_filemode(t_ls_entry *e)
{
	if ((e->stat.st_mode & S_IFBLK) == S_IFBLK)
		return ('b');
	else if ((e->stat.st_mode & S_IFCHR) == S_IFCHR)
		return ('c');
	else if ((e->stat.st_mode & S_IFDIR) == S_IFDIR)
		return ('d');
	else if ((e->stat.st_mode & S_IFLNK) == S_IFLNK)
		return ('l');
	else if ((e->stat.st_mode & S_IFSOCK) == S_IFSOCK)
		return ('s');
	else if ((e->stat.st_mode & S_IFIFO) == S_IFIFO)
		return ('p');
	else if ((e->stat.st_mode & S_IFREG) == S_IFREG)
		return ('-');
	else
		return ('?');
}

char		*fmt_owner_perm(t_ls_entry *e, char *perm)
{
	ft_bzero((void *)perm, 6);
	perm[0] = ((e->stat.st_mode & 0x100) == 0x100 ? 'r' : '-');
	perm[1] = ((e->stat.st_mode & 0x80) == 0x80 ? 'w' : '-');
	if (!((e->stat.st_mode & 0x40) == 0x40) && ((e->stat.st_mode & S_ISUID) == S_ISUID))
		perm[2] = 'S';
	else if (((e->stat.st_mode & 0x40) == 0x40) && ((e->stat.st_mode & S_ISUID) == S_ISUID))
		perm[2] = 's';
	else if ((e->stat.st_mode & 0x40) == 0x40)
		perm[2] = 'x';
	else if (!((e->stat.st_mode & 0x40) == 0x40) && !((e->stat.st_mode & S_ISUID) == S_ISUID))
		perm[2] = '-';
	else
		perm[2] = '?';
	return (perm);
}

char		*fmt_group_perm(t_ls_entry *e, char *perm)
{
	ft_bzero((void *)perm, 6);
	perm[0] = ((e->stat.st_mode & 0x20) == 0x20 ? 'r' : '-');
	perm[1] = ((e->stat.st_mode & 0x10) == 0x10 ? 'w' : '-');
	if (!((e->stat.st_mode & 0x8) == 0x8) && ((e->stat.st_mode & S_ISGID) == S_ISGID))
		perm[2] = 'S';
	else if (((e->stat.st_mode & 0x8) == 0x8) && ((e->stat.st_mode & S_ISGID) == S_ISGID))
		perm[2] = 's';
	else if ((e->stat.st_mode & 0x8) == 0x8)
		perm[2] = 'x';
	else if (!((e->stat.st_mode & 0x8) == 0x8) && !((e->stat.st_mode & S_ISGID) == S_ISGID))
		perm[2] = '-';
	else
		perm[2] = '?';
	return (perm);
}

char		*fmt_other_perm(t_ls_entry *e, char *perm)
{
	ft_bzero((void *)perm, 6);
	perm[0] = ((e->stat.st_mode & 0x4) == 0x4 ? 'r' : '-');
	perm[1] = ((e->stat.st_mode & 0x2) == 0x2 ? 'w' : '-');
	if ((e->stat.st_mode & 0x1) == 0x1)
		perm[2] = 'x';
	else if (!((e->stat.st_mode & 0x1) == 0x1) && !((e->stat.st_mode & S_ISVTX) == S_ISVTX))
		perm[2] = '-';
	else if (((e->stat.st_mode & S_ISVTX) == S_ISVTX) && !((e->stat.st_mode & 0x1) == 0x1))
		perm[2] = 'T';
	else if (((e->stat.st_mode & S_ISVTX) == S_ISVTX) && ((e->stat.st_mode & 0x1) == 0x1))
		perm[2] = 't';
	else
		perm[2] = '?';
	return (perm);
}

int		fmt_nblink(t_ls_entry *e)
{
	return (e->stat.st_nlink);
}

char				*fmt_owner(t_ls_entry *e)
{
	return (getpwuid(e->stat.st_uid)->pw_name);
}

char				*fmt_group(t_ls_entry *e)
{
	return (getgrgid(e->stat.st_gid)->gr_name);
}

int					fmt_size(t_ls_entry *e)
{
	return (e->stat.st_size);
}

char				*fmt_yhm(t_ls_entry *e, char *buf)
{
	char			*cp;

	ft_bzero((void *)buf, 6);
	//ft_printf("debug: [%ld][%ld][%ld]", time(NULL), e->stat.st_mtimespec.tv_sec, (long)ABS(time(NULL) - e->stat.st_mtimespec.tv_sec));
	if (((time(NULL) - e->stat.st_mtimespec.tv_sec) > SIXMONTH) || ((time(NULL) - e->stat.st_mtimespec.tv_sec) < -SIXMONTH))
	{
		cp = ctime(&e->stat.st_mtimespec.tv_sec) + 20;
		buf[0] = ' ';
		ft_strncpy(buf + 1, cp, 4);
	}
	else
	{
		cp = ctime(&e->stat.st_mtimespec.tv_sec) + 11;
		ft_strncpy(buf, cp, 5);
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



















