/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 11:46:31 by sbenning          #+#    #+#             */
/*   Updated: 2016/10/05 11:51:08 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_env.h"

char		**get_cmd_env(int ac, char **av, char **env, int o)
{
	int		i;
	int		size;
	char	**entries;
	char	**cp_env;

	i = 0;
	if (!IS_O(o, ENV_O_EMPTY))
	{
		while (env[i])
			i++;
	}
	if (!(entries = env_getentries(ac, av, &size)))
		return (NULL);
	if (!(cp_env = (char **)ft_memalloc(sizeof(char *) * (size + i + 1))))
	{
		env_destroy(&entries);
		return (NULL);
	}
	cp_env[size + i] = NULL;
	if (fill_env(cp_env, env, entries, o))
		return (NULL);
	return (cp_env);
}

int			env_begin_cmd(int ac, char **av)
{
	int		i;
	int		begin;

	i = 0;
	begin = 1;
	while (++i < ac)
	{
		if (av[i][0] == '-')
			begin++;
		else if (ft_strchr(av[i], '='))
			begin++;
		else
			break ;
	}
	return (begin);
}

void		env_exec_cmd(char *name, t_dic_entry *bin, char **av, char **env)
{
	char	cmd[2048];
	pid_t	pid;

	if (ft_strncmp(name, "./", 2))
		ft_strcpy(cmd, ft_dicget(bin, name));
	else
		ft_strcpy(cmd, name);
	if (!(pid = fork()))
	{
		execve(cmd, av, env);
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(pid, NULL, 0);
}
