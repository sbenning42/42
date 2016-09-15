/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:40:18 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/15 17:45:56 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_env(int ac, char **av)
{
	int		o;
	int		i;
	char	**env;

	o = ft_getopt(ac, av, "i");
	ft_printf("%#X\n", o);
	env = NULL;
	if ((o & 0x1) == 0x1)
	{
		i  = 0;
		while (++i < ac)
	
		}
	}
	else
	{
		env = g_ft_environ;
	}
}
