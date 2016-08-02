/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 09:49:33 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/17 12:23:21 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char		*intern_getenv(\
			char *key)
{
	size_t	keylen;
	char	**ep;

	keylen = ft_strlen(key);
	ep = ENV;
	while (*ep)
	{
		if (!ft_strncmp(key, *ep, keylen))
			return (*ep + keylen + 1);
		ep++;
	}
	return (NULL);
}

static int	envappend(\
			char *s, int len)
{
	char	**ep;
	int		i;

	if (!(ep = ft_memalloc(sizeof(char *) * (len + 1))))
		return (0);
	ep[len] = NULL;
	i = 0;
	while (ENV[i])
	{
		ep[i] = ENV[i];
		i++;
	}
	ep[i] = s;
	free(ENV);
	ENV = ep;
	return (1);
}

static char	*enventry(\
			char *key, size_t keylen, char *value)
{
	char	*s;

	if (!(s = ft_strnew(keylen + ft_strlen(value) + 1)))
		return (NULL);
	ft_strcat(s, key);
	ft_strcat(s, "=");
	ft_strcat(s, value);
	return (s);
}

int			intern_setenv(\
			char *key, char *value)
{
	size_t	keylen;
	char	*newcouple;
	int		i;

	keylen = ft_strlen(key);
	if (!(newcouple = enventry(key, keylen, value)))
		return (0);
	i = 0;
	while (ENV[i])
	{
		if (!ft_strncmp(key, ENV[i], keylen))
		{
			free(ENV[i]);
			ENV[i] = newcouple;
			return (1);
		}
		i++;
	}
	if (!envappend(newcouple, i + 1))
		return (0);
	return (1);
}
