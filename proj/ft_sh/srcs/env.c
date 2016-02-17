/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:06:28 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/17 12:18:29 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			builtin_env(\
			char **arg_v)
{
	int		i;

	i = 0;
	while (ENV[i])
		ft_printf("%s\n", ENV[i++]);
	(void)arg_v;
	return (1);
}

int			builtin_setenv(\
			char **arg_v)
{
	(void)arg_v;
	return (1);
}

int			builtin_unsetenv(\
			char **arg_v)
{
	(void)arg_v;
	return (1);
}
