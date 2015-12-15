/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:00:35 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/15 17:03:38 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_print(void *p, size_t size)
{
	t_ls_entry	*e;

	e = (t_ls_entry *)p;
	ft_printf("%s\n", e->key);
	(void)size;
}

void	ls_long_print(void *p, size_t size)
{
	(void)p;
	(void)size;
}

void	ls_cprint(void *p, size_t size)
{
	(void)p;
	(void)size;
}

void	ls_long_cprint(void *p, size_t size)
{
	(void)p;
	(void)size;
}
