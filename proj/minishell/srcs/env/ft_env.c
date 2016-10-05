/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:40:18 by sbenning          #+#    #+#             */
/*   Updated: 2016/10/05 12:01:08 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_env.h"

void		env_dump(char **tab)
{
	while (tab && *tab)
	{
		ft_printf("%s\n", *tab);
		tab++;
	}
}

void		env_merge(char **env, int i, char **entries)
{
	int		j;

	j = 0;
	while (entries[j])
		env[i++] = entries[j++];
}

int			fill_env(char **cp_env, char **env, char **entries, int o)
{
	int		i;

	i = 0;
	if (!IS_O(o, ENV_O_EMPTY))
	{
		while (env[i])
		{
			if (!(cp_env[i] = ft_strdup(env[i])))
			{
				env_destroy(&cp_env);
				env_destroy(&entries);
				return (-1);
			}
			i++;
		}
	}
	env_merge(cp_env, i, entries);
	ft_memdel((void **)&entries);
	return (0);
}

int			ft_env(int ac, char **av, t_dic_entry *bin)
{
	int		o;
	int		begin;
	char	**env;
	char	**cp_env;

	o = ft_getopt(ac, av, "i");
	env = g_ft_environ;
	if (!(cp_env = get_cmd_env(ac, av, env, o)))
		return (env_error("Memory allocation failed"));
	begin = env_begin_cmd(ac, av);
	if (av[begin])
		env_exec_cmd(av[begin], bin, av + begin, cp_env);
	else
		env_dump(cp_env);
	env_destroy(&cp_env);
	return (0);
}
