/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 00:11:05 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 12:00:56 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

static int	cur_higthlight(void)
{
	cur_tputs("so");
	return (0);
}

static int	cur_off(void)
{
	cur_tputs("me");
	return (0);
}

int			cur_mode(int mode)
{
	if (mode == M_HIGTHLIGHT)
		return (cur_higthlight());
	else if (mode == M_OFF)
		return (cur_off());
	return (0);
}
