/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:40:18 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/16 09:49:54 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_env.h"

void		env_dump(char **tab)
{
	ft_printf("DUMPING\n\n");
	while (tab && *tab)
	{
		ft_printf("%s\n", *tab);
		tab++;
	}
	ft_printf("\n\nEND DUMP\n");
}

void		env_merge(char **env, int i, char **entries)
{
	int		j;

	j = 0;
	while (entries[j])
		env[i++] = entries[j++];
}

int			ft_env(int ac, char **av)
{
	int		o;
	int		i;
	int		size;
	char	**env;
	char	**cp_env;
	char	**entries;

	o = ft_getopt(ac, av, "i");
	env = g_ft_environ;
	i = 0;
	if (!IS_O(o, ENV_O_EMPTY))
	{
		while (env[i])
			i++;
	}
	if (!(entries = env_getentries(ac, av, &size)))
		return (env_error("Memory allocation failed"));
	if (!(cp_env = (char **)ft_memalloc(sizeof(char *) * (size + i + 1))))
	{
		env_destroy(&entries);
		return (env_error("Memory allocation failed"));
	}
	cp_env[size + i] = NULL;
	i = 0;
	if (!IS_O(o, ENV_O_EMPTY))
	{
		while (env[i])
		{
			if (!(cp_env[i] = ft_strdup(env[i])))
			{
				env_destroy(&cp_env);
				env_destroy(&entries);
				return (env_error("Memory allocation failed"));
			}
			i++;
		}
	}
	env_merge(cp_env, i, entries);
	ft_memdel((void **)&entries);

	env_destroy(&cp_env);
	return (0);
}
