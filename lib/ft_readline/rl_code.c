/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_code.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 19:08:18 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/29 12:58:12 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_searchcode(t_rl *rl, int code)
{
	int		i;

	i = -1;
	while (++i < RL_CODESIZE)
	{
		if (code == g_rlcode[i].code)
			return ((!g_rlcode[i].function(rl) ? 1 : -1));
	}
	return (0);
}

int			rl_defcode(t_rl *rl, int code)
{
	char	msg[64];

	if (!ft_isprint(code))
	{
		ft_sprintf(msg, "Input unhandled: [%#x]\n", code);
		rl_destroyterm();
		ft_exit(EXIT_FAILURE, msg);
	}
	if (dyn_strpushante(&rl->dyn, (char *)&code, 1) < 0)
	{
		rl_destroyterm();
		ft_exit(EXIT_FAILURE, "Memory allocation failed");
	}
	if (ISIN(rl->settings, RL_ECHO))
	{
		write(1, (char *)&code, 1);
		if (!((rl->dyn.ante + rl->promptsize) % tgetnum("co")))
			ft_cap("do", CAP_NOARG);
	}
	return (0);
}
