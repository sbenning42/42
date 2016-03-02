/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 12:51:14 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/02 14:33:33 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_read(void)
{
	char	buff[RL_INPUT_SIZE + 1];
	int		ret;

	ft_bzero((void *)buff, sizeof(char) * (RL_INPUT_SIZE + 1));
	if ((ret = read(0, buff, RL_INPUT_SIZE)) < 0)
		return (0);
	buff[ret] = 0;
	return (*(int *)buff);
}

char		*rl_readline(t_rl *rl)
{
	int		code;

	if (ISATTR(rl->gflag, RL_GECHO))
		rl_echo_init(rl);
	while (42)
	{
		if ((code = rl_read()) == 0)
			continue ;
		if (rl_maj(rl, code) < 0)
			return (NULL);
		if (ISATTR(rl->lflag, RL_LFLUSH))
			return (rl_flush(rl));
		if (ISATTR(rl->gflag, RL_GECHO))
			rl_echo(rl);
	}
	return (NULL);
}
