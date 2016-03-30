/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:12:59 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 15:06:58 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void dumpdyn(t_dyn d)
{
	size_t	i = 0;
	ft_fprintf(2, "\t[%zu][%zu][%zu][%zu]\n", d.real, d.used, d.ante, d.post);
	while (i <= d.real)
	{
		ft_fprintf(2, "[%d]", (int)d.str[i]);
		i++;
	}
	ft_fprintf(2, "\n");
}

char			*ft_readline(char *prompt, int settings)
{
	t_rl		rl;
	char		*line;
	long int	code;

	if (rl_init(&rl, settings, prompt) < 0)
		return (NULL);
	cur_write(prompt, rl.promptsize);
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
	line = ft_strjoin(rl.dyn.str, rl.dyn.strend - rl.dyn.post);
	rl_destroy(&rl);
	return (line);
}
