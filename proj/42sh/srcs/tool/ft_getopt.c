/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 18:24:40 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/28 18:45:08 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_getopt(int ac, char **av, char *charset)
{
	int		o;
	int		to;
	int		i;
	int		j;
	char	*tmp;
	char	msg[2048];

	to = 0;
	j = 0;
	while (++j < ac)
	{
		if (av[j][0] != '-')
			break ;
		i = 0;
		while (av[j][++i])
		{
			tmp = charset;
			o = 0x1;
			while (*tmp)
			{
				if (av[j][i] == *tmp)
				{
					to += o;
					break ;
				}
				o <<= 1;
				tmp++;
			}
			if (!*tmp)
			{
				ft_bzero((void *)msg, 2048);
				ft_sprintf(msg, "Usage: %s [-%s] [Prompt]", av[0], charset);
				ft_error(msg);
				return (-1);
			}
		}
	}
	return (to);
}
