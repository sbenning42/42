/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:00:35 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/18 17:51:47 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	p_standard(void *p, size_t size)
{
	t_ls_entry	*e;

	e = (t_ls_entry *)p;
/*//	ft_printf("DUMP P: k[%s] p[%s] t[%#x]\n", e->name, e->path, e->type);
	if ((env()->o & O_HIDE) == 0 && e->name[0] == '.')
*/	
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
	(void)p;
	(void)size;
}

void	p_clong(void *p, size_t size)
{
	(void)p;
	(void)size;
}
