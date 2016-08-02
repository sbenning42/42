/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:06:28 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/19 12:29:59 by sbenning         ###   ########.fr       */
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

static void	intern_unset(\
			char *key)
{
	int		i;
	size_t	len;

	i = -1;
	len = ft_strlen(key);
	while (ENV[++i])
	{
		if (!ft_strncmp(key, ENV[i], len))
		{
			free(ENV[i]);
			while (ENV[i])
			{
				ENV[i] = ENV[i + 1];
				i++;
			}
			return ;
		}
	}
}

int			builtin_unsetenv(\
			char **arg_v)
{
	int		i;

	if (!arg_v[1])
		return (unset_usage());
	i = 0;
	while (arg_v[++i])
		intern_unset(arg_v[i]);
	return (1);
}
