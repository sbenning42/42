/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:28:13 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/04 19:26:18 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

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
	t_lex	*lst;

	while (42)
	{
		if (!(line = ft_readline("$>", RL_GECHO, ft_getenv(ep, "TERM"))))
			continue ;
		if (!ft_strcmp("exit", line))
		{
			ft_memdel((void **)&line);
			break ;
		}
		if (!(lst = ft_lexer(line)))
		{
			ft_memdel((void **)&line);
			continue ;
		}
		ft_memdel((void **)&line);
		lx_print(lst);
		lx_del(&lst);
	}
	return (0);
	(void)ac;
	(void)av;
}
