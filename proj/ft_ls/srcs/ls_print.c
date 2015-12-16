/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:00:35 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/16 15:47:16 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	p_standard(void *p, size_t size)
{
	t_ls_entry	*e;

	e = (t_ls_entry *)p;
//	ft_printf("DUMP P: k[%s] p[%s] t[%#x]\n", e->key, e->path, e->type);
	if ((ls_env()->o & O_HIDE) == 0 && e->key[0] == '.')
		return ;
	ft_printf("%s\n", e->key);
	(void)size;
}

void	p_cstandard(void *p, size_t size)
{
	t_ls_entry	*e;

	e = (t_ls_entry *)p;
	if (e->type == T_NODIR)
		ft_printf("%s\n", e->key);
	else if (e->type == T_DIR)
		ft_printf("{cyan}%s{eoc}\n", e->key);
	else
		ft_printf("{red}%s{eoc}\n", e->key);
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
