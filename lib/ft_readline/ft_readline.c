/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:12:59 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/19 19:06:27 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

char		*ft_readline(char *prompt, int settings)
{
	t_rl	rl;
	char	*line;
	int		code;

	if (rl_init(&rl, settings, ft_strlen(prompt)) < 0)
		return (NULL);
	write(1, prompt, rl.promptsize);
	while (!ISIN(rl.bitset, RL_BS_FLUSH))
	{
		if (!(code = rl_read()))
			continue ;
		if (rl_maj(&rl, code) < 0)
		{
			rl_destroy(&rl);
			return (NULL);
		}
	}
	line = ft_strjoin(rl.dyn.str, rl.dyn.str + rl.dyn.post);
	rl_destroy(&rl);
	return (line);
}
