/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 13:02:36 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/19 13:37:10 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_global.h"

char		**g_ft_environ;
char		*g_ft_program_name;

void		ft_initenv(void)
{
	g_ft_environ = environ;
}

void		ft_initname(void)
{
	g_ft_program_name = program_invocation_short_name;
}

void		ft_init(void)
{
	ft_initname();
	ft_initenv();
}
