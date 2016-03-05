/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_handle_suite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 15:17:35 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 16:20:22 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_maj_insert(t_rl *rl)
{
	if (ISATTR(rl->lflag, RL_LINSERT))
		rl->lflag &= ~RL_LINSERT;
	else
		rl->lflag |= RL_LINSERT;
	return (0);
}

int			rl_maj_d(t_rl *rl)
{
	(void)rl;
	write(1, "\n", 1);
	return (-1);
}

int			rl_maj_cl(t_rl *rl)
{
	tm_cap("cl");
	rl_echo_init(rl);
	rl->diff.type = RL_TAPPEND;
	rl->diff.begin = rl->prompt;
	rl->diff.offset = rl->ante_cursor - rl->prompt;
	return (0);
}

int			rl_maj_home(t_rl *rl)
{
	while (rl->ante_cursor > rl->prompt)
		rl_maj_left(rl);
	return (0);
}

int		rl_maj_end(t_rl *rl)
{
	while (rl->post_cursor < rl->real)
		rl_maj_right(rl);
	return (0);
}
