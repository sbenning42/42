/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 13:23:10 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/19 13:37:34 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exit.h"

void		ft_exit(int rval, char *msg)
{
	if (!g_ft_program_name)
		ft_initname();
	if (!msg)
		msg = "success";
	ft_fprintf(2, "%s: %s\n", g_ft_program_name, msg);
	exit(rval);
}
