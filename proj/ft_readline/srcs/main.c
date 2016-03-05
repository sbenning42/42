/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:28:13 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 16:04:43 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

char		*ft_getenv(char **ep, const char *key)
{
	while (*ep)
	{
		if (ft_strstr(*ep, key))
			return (ft_strchr(*ep, '=') + 1);
		ep++;
	}
	return (NULL);
}

int			main(int ac, char **av, char **ep)
{
	char	*line;
	char	*prompt;

	prompt = (ac < 2 ? "" : av[1]);
	while (42)
	{
		line = ft_readline(prompt, (RL_GECHO | RL_GHISTORY | RL_GSAVE | RL_GLOAD), ft_getenv(ep, "TERM"));
		if (line)
		{
			if (!ft_strcmp(line, "exit"))
			{
				ft_memdel((void **)&line);
				break ;
			}
			ft_memdel((void **)&line);
		}
	}
	ft_atexit(EXIT_SUCCESS, av[0], "main: Success");
	return (0);
}
