/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:28:13 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/02 14:59:25 by sbenning         ###   ########.fr       */
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
	line = ft_readline(prompt, (RL_GECHO | RL_GHISTORY), ft_getenv(ep, "TERM"));
	ft_printf("%s: line=[%s]\n", av[0], line);
	if (line)
		ft_memdel((void **)&line);
	ft_atexit(EXIT_SUCCESS, av[0], "main: Success");
	return (0);
}
