/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/22 16:23:08 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/21 18:00:47 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_solo_opt(const char *cset, char c, char *e)
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

int			get_opt(const char *cset, int ac, char **av, char *err)
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
		j = 0;
		while (av[i][++j])
			o |= get_solo_opt(cset, av[i][j], err);
	}
	while (i < ac)
	{
		if (ft_strlen(av[i]) < 1)
		{
			ft_printf("ft_ls: fts_open: No such file or directory\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (o);
}
