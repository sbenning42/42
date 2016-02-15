/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 11:57:30 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/15 10:20:23 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	get_solo_opt(\
			const char *cset, char c, char *e)
{
	int		o;

	o = 0x1;
	while (*cset)
	{
		if (*cset++ == c)
			return (o);
		o <<= 0x1;
	}
	if (!*e)
		*e = c;
	return (O_PRIVATE_ERROR);
}

int			get_opt(\
			const char *cset, int ac, char **av, char *err)
{
	int		i;
	int		j;
	int		o;

	i = 0;
	o = 0x0;
	while (++i < ac)
	{
		if ((av[i][0] != '-') || (ft_strlen(av[i]) == 1))
			break ;
		else if (ft_isdigit(av[i][1]))
			break ;
		j = 0;
		while (av[i][++j])
			o |= get_solo_opt(cset, av[i][j], err);
	}
	return (o);
}

int			go_over_opt(\
			int ac, char **av)
{
	int		skip;

	skip = 0;
	while (++skip < ac)
	{
		if ((av[skip][0] != '-') || (ft_strlen(av[skip]) == 1))
			break ;
		else if (ft_isdigit(av[skip][1]))
			break ;
	}
	return (skip);
}
