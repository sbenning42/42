/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 13:05:35 by sbenning          #+#    #+#             */
/*   Updated: 2016/06/30 10:48:43 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"

char		*ft_getenv(char *key)
{
	char	**env;
	size_t	len;

	if (!g_ft_environ)
		ft_initenv();
	env = g_ft_environ;
	len = ft_strlen(key);
	while (*env)
	{
		if (!ft_strncmp(*env, key, len) && (*env)[len] == '=')
			return (*env + len + 1);
		env++;
	}
	return (NULL);
}

int			ft_setenv(char *key, char *value)
{
	char	**env;
	char	**tmp;
	int		i;
	size_t	len;

	if (!g_ft_environ)
		ft_initenv();
	env = g_ft_environ;
	len = ft_strlen(key);
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], key, len))
		{
			free(env[i]);
			if (!(env[i] = ft_strjoin(key, value)))
				return (-1);
			return (0);
		}
		i++;
	}
	tmp = env;
	if (!(env = ft_memalloc(sizeof(char *) * (i + 2))))
		return (-1);
	env[i + 1] = NULL;
	i = 0;
	while (tmp[i])
	{
		env[i] = tmp[i];
		i++;
	}
	if (!(env[i] = ft_strjoin(key, value)))
		return (-1);
	free(tmp);
	g_ft_environ = env;
	return (0);
}
