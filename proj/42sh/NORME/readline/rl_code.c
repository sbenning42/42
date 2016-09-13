/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_code.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 19:08:18 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/28 12:14:59 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_searchcode(t_rl *rl, long int code)
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

int			rl_skipnext(t_rl *rl)
{
	rl->bitset &= ~RL_BS_SKIPNEXT;
	return (0);
}

int			rl_defcode(t_rl *rl, long int code)
{
	if (ISIN(rl->bitset, RL_BS_SKIPNEXT))
		return (rl_skipnext(rl));
	if (!ft_isprint(code))
		return (0);
	if (dyn_strpushante(&rl->dyn, (char *)&code, 1) < 0)
		cur_exit(EXIT_FAILURE, "Memory allocation failed");
	if (!ISIN(rl->bitset, RL_BS_INSERT))
		dyn_strpoppost(&rl->dyn, NULL, 1);
	if (ISIN(rl->settings, RL_ECHO))
	{
		cur_write((char *)&code, 1);
		rl_reset_post_display(rl);
	}
	return (0);
}
