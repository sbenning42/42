/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 08:23:32 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 14:36:39 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void		cmd_destroy(char ***at)
{
	char	**cp;

	cp = *at;
	while (*cp)
	{
		ft_memdel((void **)cp);
		cp++;
	}
	ft_memdel((void **)at);
}

char		**cmd_malloc_arg(t_lxem *list)
{
	char	**arg;
	int		i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	if (!(arg = (char **)ft_memalloc(sizeof(char *) * (i + 1))))
		return (NULL);
	arg[i] = NULL;
	return (arg);
}

char		**cmd_arg(t_lxem *list)
{
	char	**arg;
	t_lxem	*tmp;
	int		j;

	if (!(arg = cmd_malloc_arg(list)))
		return (NULL);
	j = 0;
	tmp = list;
	while (tmp)
	{
		if (!(arg[j] = ft_strdup(tmp->value.str)))
		{
			cmd_destroy(&arg);
			return (NULL);
		}
		j++;
		tmp = tmp->next;
	}
	return (arg);
}

char		**cmd_env(void)
{
	char	**env;
	char	**cp;
	int		i;
	int		j;

	cp = g_ft_environ;
	i = 0;
	while (cp[i])
		i++;
	if (!(env = (char **)ft_memalloc(sizeof(char *) * (i + 1))))
		return (NULL);
	env[i] = NULL;
	j = 0;
	while (j < i)
	{
		if (!(env[j] = ft_strdup(cp[j])))
		{
			cmd_destroy(&env);
			return (NULL);
		}
		j++;
	}
	return (env);
}
