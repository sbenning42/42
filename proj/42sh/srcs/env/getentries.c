/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getentries.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 09:17:30 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/16 09:30:28 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_env.h"

static int	entries_size(int ac, char **av)
{
	int		size;
	int		flag;
	int		i;

	size = 0;
	i = 0;
	flag = 0;
	while (++i < ac)
	{
		if (ft_strchr(av[i], '='))
		{
			size++;
			flag = 1;
		}
		else if (flag)
			break ;
	}
	return (size);
}

static int	fill_entries(int ac, char **av, char **entries)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = 0;
	flag = 0;
	while (++i < ac)
	{
		if (!ft_strchr(av[i], '='))
		{
			if (flag)
				break ;
			else
				continue ;
		}
		flag = 1;
		if (!(entries[j++] = ft_strdup(av[i])))
		{
			env_destroy(&entries);
			return (-1);
		}
	}
	return (0);
}

char		**env_getentries(int ac, char **av, int *size)
{
	char	**entries;

	*size = entries_size(ac, av);
	if (!(entries = (char **)ft_memalloc(sizeof(char *) * (*size + 1))))
	{
		env_error("Memory allocation failed");
		return (NULL);
	}
	entries[*size] = NULL;
	if (fill_entries(ac, av, entries))
		return (NULL);
	return (entries);
}
