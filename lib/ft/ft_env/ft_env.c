/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 13:05:35 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/19 13:35:38 by sbenning         ###   ########.fr       */
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
		if (!ft_strncmp(*env, key, len))
			return (*env + len + 1);
		env++;
	}
	return (NULL);
}
