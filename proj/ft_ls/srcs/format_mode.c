/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:53:13 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/11 18:01:57 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			fmt_filemode(t_ls_entry *e)
{
	if (IS(S_IFBLK, e->stat.st_mode))
		return ('b');
	else if (IS(S_IFDIR, e->stat.st_mode))
		return ('d');
	else if (IS(S_IFLNK, e->stat.st_mode))
		return ('l');
	else if (IS(S_IFCHR, e->stat.st_mode))
		return ('c');
	else if (IS(S_IFSOCK, e->stat.st_mode))
		return ('s');
	else if (IS(S_IFIFO, e->stat.st_mode))
		return ('p');
	else if (IS(S_IFREG, e->stat.st_mode))
		return ('-');
	else
		return ('?');
}

char			*fmt_owner_perm(t_ls_entry *e, char *perm)
{
	ft_bzero((void *)perm, 6);
	perm[0] = (IS(0x100, e->stat.st_mode) ? 'r' : '-');
	perm[1] = (IS(0x80, e->stat.st_mode) ? 'w' : '-');
	if (!IS(0x40, e->stat.st_mode) && IS(S_ISUID, e->stat.st_mode))
		perm[2] = 'S';
	else if (IS(0x40, e->stat.st_mode) && IS(S_ISUID, e->stat.st_mode))
		perm[2] = 's';
	else if (IS(0x40, e->stat.st_mode))
		perm[2] = 'x';
	else if (!IS(0x40, e->stat.st_mode) && !IS(S_ISUID, e->stat.st_mode))
		perm[2] = '-';
	else
		perm[2] = '?';
	return (perm);
}

char			*fmt_group_perm(t_ls_entry *e, char *perm)
{
	ft_bzero((void *)perm, 6);
	perm[0] = (IS(0x20, e->stat.st_mode) ? 'r' : '-');
	perm[1] = (IS(0x10, e->stat.st_mode) ? 'w' : '-');
	if (!IS(0x8, e->stat.st_mode) && IS(S_ISGID, e->stat.st_mode))
		perm[2] = 'S';
	else if (IS(0x8, e->stat.st_mode) && IS(S_ISGID, e->stat.st_mode))
		perm[2] = 's';
	else if (IS(0x8, e->stat.st_mode))
		perm[2] = 'x';
	else if (!IS(0x8, e->stat.st_mode) && !IS(S_ISGID, e->stat.st_mode))
		perm[2] = '-';
	else
		perm[2] = '?';
	return (perm);
}

char			*fmt_other_perm(t_ls_entry *e, char *perm)
{
	ft_bzero((void *)perm, 6);
	perm[0] = (IS(0x4, e->stat.st_mode) ? 'r' : '-');
	perm[1] = (IS(0x2, e->stat.st_mode) ? 'w' : '-');
	if (IS(0x1, e->stat.st_mode) && !IS(S_ISVTX, e->stat.st_mode))
		perm[2] = 'x';
	else if (!IS(0x1, e->stat.st_mode) && !IS(S_ISVTX, e->stat.st_mode))
		perm[2] = '-';
	else if (IS(S_ISVTX, e->stat.st_mode) && !IS(0x1, e->stat.st_mode))
		perm[2] = 'T';
	else if (IS(S_ISVTX, e->stat.st_mode) && IS(0x1, e->stat.st_mode))
		perm[2] = 't';
	else
		perm[2] = '?';
	return (perm);
}

char			fmt_attr(t_ls_entry *e)
{
	char		absname[PATHSIZE_LS];
	char		c;
	int			ret_list;
	acl_t		acl;
	acl_entry_t	dum;

	ft_strcpy(absname, env()->path);
	ft_strcat(absname, "/");
	ft_strcat(absname, e->name);
	c = ' ';
	if ((ret_list = listxattr(absname, NULL, 0, XATTR_NOFOLLOW)) > 0)
		c = '@';
	else if ((acl = acl_get_link_np(absname, ACL_TYPE_EXTENDED)))
	{
		if (acl_get_entry(acl, ACL_FIRST_ENTRY, &dum) != -1)
			c = '+';
		acl_free((void *)acl);
	}
	errno = 0;
	return (c);
}
