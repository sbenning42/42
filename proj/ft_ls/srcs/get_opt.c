/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/22 16:23:08 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/22 16:37:22 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			get_index_opt(const char *cset, char c)
{
	int		i;

	i = 0;
	while (cset[i])
	{
		if (cset[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int			get_opt(const char *cset, int *opt, int ac, char **av)
{
	int		i;
	int		j;
	int		index;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		if (av[i][j] == '-')
		{
			while (av[i][++j])
			{
				if ((index = get_index_opt(cset, av[i][j])) != -1)
					opt[index] = 1;
				else
				{
					ft_printf("ft_ls: '%c' is not a valid option!\n", av[i][j]);
					return (1);
				}
			}
		}
		else
			return (0);
	}
	return (0);
}
