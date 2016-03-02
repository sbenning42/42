/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_maj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:20:03 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/02 14:55:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_maj(t_rl *rl, int code)
{
	int	i;

	if (code > 0x1f && code < 0x7f)
	{
		rl->lflag |= RL_LBMODIF;
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
	return (-1);
}
