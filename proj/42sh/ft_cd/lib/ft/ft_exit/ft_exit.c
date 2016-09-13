/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 13:23:10 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/22 10:48:49 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exit.h"

void		ft_error(char *msg)
{
	if (!g_ft_program_name)
		ft_initname("Unnamed");
	if (!msg)
		msg = "success";
	ft_fprintf(2, "%s: %s\n", g_ft_program_name, msg);
}

void		ft_exit(int rval, char *msg)
{
	ft_error(msg);
	exit(rval);
}
