/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_maj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:55:51 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/19 19:11:25 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_maj(t_rl *rl, int code)
{
	if (!rl_searchcode(rl, code))
		rl_defcode(rl, code);
	if (ISIN(rl->settings, RL_ECHO))
		rl_echo(rl);
	return (0);
}
