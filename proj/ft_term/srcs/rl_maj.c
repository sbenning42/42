/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_maj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:20:03 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/04 13:34:44 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_maj(t_rl *rl, int code)
{
	int	i;

	if (code > 0x1f && code < 0x7f)
	{
		rl->begin = rl->ante_cursor;
		rl->diff = 1;
		return (rl_ante_push(rl, code));
	}
	else
	{
		i = -1;
		while (++i < RL_GKEY_SIZE)
		{
			if (code == g_key[i].kcode)
				return (g_key[i].khandle(rl));
		}
	}
	ft_fprintf(2, "code=[%#x]\n", code);
	return (/*-1*/0);
}
