/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:41:43 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/02 13:52:55 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_maj_nl(t_rl *rl)
{
	rl->lflag |= RL_LFLUSH;
	return (0);
}

int		rl_maj_retarr(t_rl *rl)
{
	if (rl->ante_cursor > rl->prompt)
		rl_ante_pop(rl);
	return (0);
}
