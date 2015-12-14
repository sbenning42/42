/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/22 16:23:08 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/14 16:03:38 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_solo_opt(const char *cset, char c)
{
	int		o;

	o = 0x1;
	while (*cset)
	{
		o <<= 0x1;
		if (*cset++ == c)
			return (o);
	}
	return (O_PRIVATE_ERROR);
}

int			get_opt(const char *cset, int ac, char **av, char *err)
{
	int		i;
	int		j;
	int		o;

	i = 0;
	o = 0x0;
	while (++i < ac)
	{
		j = 0;
		if (av[i][j++] == '-')
		{
			while (av[i][j] && (o |= get_solo_opt(cset, av[i][j])))
			{
				*err = ((!(o & O_PRIVATE_ERROR) || *err) ? *err : av[i][j]);
				j++;
			}
		}
		else
			break ;
	}
	return (o);
}
