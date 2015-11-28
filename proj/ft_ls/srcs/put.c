/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/22 17:19:04 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/22 17:51:08 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_put_error_entry(char *name, int err)
{
	ft_printf("ft_ls: '%s' ", name);
	if (err == EACCES)
		ft_printf(EACCES_M);
	else if (err == EBADF)
		ft_printf(EBADF_M);
	else if (err == EFAULT)
		ft_printf(EFAULT_M);
	else if (err == ELOOP)
		ft_printf(ELOOP_M);
	else if (err == ENAMETOOLONG)
		ft_printf(ENAMETOOLONG_M);
	else if (err == ENOENT)
		ft_printf(ENOENT_M);
	else if (err == ENOMEM)
		ft_printf(ENOMEM_M);
	else if (err == ENOTDIR)
		ft_printf(ENOTDIR_M);
	else if (err == EOVERFLOW)
		ft_printf(EOVERFLOW_M);
	ft_printf("\n");
}
