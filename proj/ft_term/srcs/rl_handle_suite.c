/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_handle_suite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 15:17:35 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 15:22:38 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

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
