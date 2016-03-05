/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:58:01 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 17:34:55 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

char		*ft_readline(const char *prompt, int gflag, char *term)
{
	char	*line;
	t_rl	rl;

	if (tm_init(term) < 0)
		ft_atexit(EXIT_FAILURE, "Readline", "tm_init: Fail");
	if (rl_init(&rl, gflag, prompt) < 0)
		ft_atexit(EXIT_FAILURE, "Readline", "rl_init: Fail");
	line = rl_readline(&rl);
	if (rl_quit(&rl) < 0)
		ft_atexit(EXIT_FAILURE, "Readline", "rl_quit: Fail");
	if (tm_quit() < 0)
		ft_atexit(EXIT_FAILURE, "Readline", "tm_quit: Fail");
	return (line);
}
