/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:00:35 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/21 04:33:08 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	p_standard(void *p, size_t size)
{
	t_ls_entry	*e;

	e = (t_ls_entry *)p;
	if (!e->handle && !((env()->o & O_HIDE) == O_HIDE))
		return ;
	env()->i++;
	ft_printf("%s\n", e->name);
	(void)size;
}

void	p_cstandard(void *p, size_t size)
{
	t_ls_entry	*e;

	e = (t_ls_entry *)p;
	if (e->type == T_FILE)
		ft_printf("%s\n", e->name);
	else if (e->type == T_DIR)
		ft_printf("{cyan}%s{eoc}\n", e->name);
	else
		ft_printf("{red}%s{eoc}\n", e->name);
	(void)size;
}

void	p_long(void *p, size_t size)
{
	t_ls_entry	*e;
	char		buf[6][6];

	e = (t_ls_entry *)p;
	if (!e->handle && !((env()->o & O_HIDE) == O_HIDE))
		return ;
	env()->i++;
	ft_printf("%c%s%s%s%c %*d %s  %s %*d %.3s %.2s %s %s\n",\
			fmt_filemode(e),\
			fmt_owner_perm(e, buf[0]),\
			fmt_group_perm(e, buf[1]),\
			fmt_other_perm(e, buf[2]),\
			' ', /* ACL + ATTR*/\
			env()->nlinkpad,\
			fmt_nblink(e),\
			fmt_owner(e),\
			fmt_group(e),\
			env()->sizepad + 1,\
			fmt_size(e),\
			fmt_month(e, buf[3]),\
			fmt_day(e, buf[4]),\
			fmt_yhm(e, buf[5]),\
			e->name);
/*	ft_printf("[%#x]\n\t", e->stat.st_mode);
	ft_printf("[%#x] ", e->stat.st_mode & 0x80);
	ft_printf("[%#x] ", e->stat.st_mode & 0x40);
	ft_printf("[%#x] ", e->stat.st_mode & 0x20);
	ft_printf("[%#x] ", e->stat.st_mode & 0x10);
	ft_printf("[%#x] ", e->stat.st_mode & 0x8);
	ft_printf("[%#x] ", e->stat.st_mode & 0x4);
	ft_printf("[%#x] ", e->stat.st_mode & 0x2);
	ft_printf("[%#x]\n", e->stat.st_mode & 0x1);
*/	
	(void)size;
}

void	p_clong(void *p, size_t size)
{
	(void)p;
	(void)size;
}
