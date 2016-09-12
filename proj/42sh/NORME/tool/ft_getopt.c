/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 18:24:40 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/09 10:16:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	ft_getopt_error(char *name, char *cs)
{
	char	msg[2048];

	ft_bzero((void *)msg, 2048);
	ft_sprintf(msg, "Usage: %s [-%s] [Prompt]", name, cs);
	ft_error(msg);
	return (-1);
}

static int	ft_getopt_solo(char *arg, char *cs)
{
	char	*tmp;
	int		o;
	int		to;

	to = 0x0;
	while (*arg)
	{
		tmp = cs;
		o = 0x1;
		while (*tmp)
		{
			if (*arg == *tmp)
			{
				to += o;
				break ;
			}
			tmp++;
			o <<= 0x1;
		}
		if (!*tmp)
			return (-1);
		arg++;
	}
	return (to);
}

int			ft_getopt(int ac, char **av, char *charset)
{
	int		o;
	int		to;
	int		i;

	to = 0;
	i = 0;
	while (++i < ac)
	{
		if (av[i][0] != '-')
			break ;
		if ((o = ft_getopt_solo(av[i] + 1, charset)) < 0)
			return (ft_getopt_error(av[0], charset));
		to += o;
	}
	return (to);
}
