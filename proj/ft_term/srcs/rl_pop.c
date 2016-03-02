/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:50:53 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/02 13:58:53 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_ante_pop(t_rl *rl)
{
	int	code;

	rl->lflag |= RL_LBMODIF;
	rl->ante_cursor -= 1;
	code = rl->buffer[rl->ante_cursor];
	rl->buffer[rl->ante_cursor] = 0;
	rl->used -= 1;
	return (code);
}

int		rl_post_pop(t_rl *rl)
{
	int	code;

	rl->lflag |= RL_LBMODIF;
	code = rl->buffer[rl->post_cursor];
	rl->ante_cursor += 1;
	rl->buffer[rl->post_cursor] = 0;
	rl->used -= 1;
	return (code);
}
