/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 13:02:36 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/22 10:47:56 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_global.h"

char		**g_ft_environ;
char		*g_ft_program_name;

void		ft_initenv(void)
{
	g_ft_environ = environ;
}

void		ft_initname(char *name)
{
	g_ft_program_name = name;
}

void		ft_init(char *name)
{
	ft_initname(name);
	ft_initenv();
}
