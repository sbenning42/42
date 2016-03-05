/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:28:13 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 17:31:58 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

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
	if (tm_init(ft_getenv(ep, "TERM")) < 0)	
		ft_atexit(EXIT_FAILURE, "term", "tm_init: fail");
	tm_cap("cl");
	if (tm_quit() < 0)	
		ft_atexit(EXIT_FAILURE, "term", "tm_quit: fail");
	ft_atexit(EXIT_SUCCESS, "term", "main: Success");
	return (0);
	(void)ac;
	(void)av;
}
