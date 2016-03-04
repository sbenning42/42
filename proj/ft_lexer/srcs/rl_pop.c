/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:50:53 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/04 13:31:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_ante_pop(t_rl *rl)
{
	int	code;

	rl->ante_cursor -= 1;
	code = rl->buffer[rl->ante_cursor];
	rl->buffer[rl->ante_cursor] = 0;
	rl->used -= 1;
	return (code);
}

int		rl_post_pop(t_rl *rl)
{
	int	code;

	code = rl->buffer[rl->post_cursor];
	rl->buffer[rl->post_cursor] = 0;
	rl->post_cursor += 1;
	rl->used -= 1;
	return (code);
}
