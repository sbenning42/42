/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/22 16:23:08 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/09 15:52:52 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_solo_opt(const char *cset, char c)
{
	int		opt;

	opt = 0x1;
	while (*cset)
	{
		opt <<= 0x1;
		if (*cset++ == c)
			return (opt);
	}
	return (PRIV_ERROR_O);
}

int			get_opt(const char *cset, int ac, char **av, char *err)
{
	int		i;
	int		j;
	int		opt;

	i = 0;
	opt = 0x0;
	while (++i < ac)
	{
		j = 0;
		if (av[i][j++] == '-')
		{
			while (av[i][j] && (opt |= get_solo_opt(cset, av[i][j])))
			{
				*err = ((!(opt & PRIV_ERROR_O) || *err) ? *err : av[i][j]);
				j++;
			}
		}
		else
			break ;
	}
	return (opt);
}
