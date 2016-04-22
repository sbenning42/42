/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:12:59 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/22 11:54:24 by sbenning         ###   ########.fr       */
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

char			*ft_readline(char *prompt, t_hist *hist, int settings)
{
	t_rl		rl;
	char		*line;
	long int	code;

	if (rl_init(&rl, hist, settings, prompt) < 0)
		return (NULL);
	cur_write(prompt, rl.promptsize);
	while (!ISIN(rl.bitset, RL_BS_FLUSH) && !ISIN(rl.bitset, RL_BS_QFLUSH))
	{
		if (!(code = rl_read()))
			continue ;
		if (rl_maj(&rl, code) < 0)
		{
			rl_destroy(&rl);
			return (NULL);
		}
	}
	if (ISIN(rl.bitset, RL_BS_FLUSH))
	{
		line = ft_strjoin(rl.dyn.str, rl.dyn.strend - rl.dyn.post);
		if (ft_strlen(line))
		{
			if (!(hist->cursor = ft_dlstnew(line, ft_strlen(line) + 1)))
				ft_memdel((void **)&line);
			else
				ft_dlstaddn(&hist->list, hist->cursor);
		}
	}
	else
		line = ft_strnew(0);
	rl_destroy(&rl);
	return (line);
}
