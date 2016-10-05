/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:12:59 by sbenning          #+#    #+#             */
/*   Updated: 2016/10/05 11:00:21 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static int		readline_loop(t_rl *rl)
{
	long int	input;

	while (42)
	{
		if (ISIN(rl->bitset, RL_BS_FLUSH) || ISIN(rl->bitset, RL_BS_QFLUSH))
			break ;
		if (!(input = rl_read()))
			continue ;
		if (rl_maj(rl, input) < 0)
		{
			rl_destroy(rl);
			return (-1);
		}
	}
	return (0);
}

char			*ft_readline(char *prompt, t_hist *hist, int settings)
{
	t_rl		rl;
	char		*line;

	if (rl_init(&rl, hist, settings, prompt) < 0)
		return (NULL);
	cur_cwrite(rl.prompt, rl.promptsize, ft_strlen(rl.prompt));
	if (readline_loop(&rl) < 0)
		return (NULL);
	line = NULL;
	if (ISIN(rl.bitset, RL_BS_FLUSH) && rl.dyn.used)
	{
		line = ft_strjoin(rl.dyn.str, rl.dyn.strend - rl.dyn.post);
		if (ISIN(settings, RL_HISTORY))
		{
			if (!(hist->cursor = ft_dlstnew(line, rl.dyn.used + 1)))
				ft_memdel((void **)&line);
			else
				ft_dlstaddn(&hist->list, hist->cursor);
		}
	}
	rl_destroy(&rl);
	write(1, "\n", 1);
	return (line);
}
