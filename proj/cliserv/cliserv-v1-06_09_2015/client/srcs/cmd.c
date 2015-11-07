/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 00:19:25 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/10 04:12:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	givenv(char *d, char **ep)
{
	int		i;

	i = 0;
	while (*ep && i < BSS_SIZE)
	{
		ft_strncpy(d, *ep, ft_strlen(*ep));
		d[ft_strlen(d)] = '\n';
		d += ft_strlen(*ep) + 1;
		i += ft_strlen(*ep + 1);
		ep++;
	}
}

static void	shut(char *d)
{
	ft_strncpy(d, "Shuting! Try reco in 15\n", 24);
}

void		cmd_handle(char *d, char *s, char **ep)
{
	while (*s)
	{
		if (!ft_strncmp("!givenv\n", s, 8))
			givenv(d, ep);
		else if (!ft_strncmp("!", s, ))
		else if (!ft_strncmp("!shut\n", s, 6))
			shut(d);
		else
		{
			ft_strncpy(d, "666\n", 4);
			return ;
		}
	}
}
