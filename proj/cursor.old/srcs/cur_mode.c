/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 00:11:05 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 00:33:04 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

static int	cur_rvon(void)
{
	char	*s;

	if (!(s = tgetstr("mr", NULL)))
		cur_exit(EXIT_FAILURE, "No \"mr\" capabilitie in term database");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	return (0);
}

static int	cur_hlon(void)
{
	char	*s;

	if (!(s = tgetstr("so", NULL)))
		cur_exit(EXIT_FAILURE, "No \"so\" capabilitie in term database");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	return (0);
}

static int	cur_modeoff(void)
{
	char	*s;

	if (!(s = tgetstr("me", NULL)))
		cur_exit(EXIT_FAILURE, "No \"se\" capabilitie in term database");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	return (0);
}

int			cur_mode(int mode)
{
	if (mode == M_HL_ON)
		return (cur_hlon());
	else if (mode == M_RV_ON)
		return (cur_rvon());
	return (cur_modeoff());
}
