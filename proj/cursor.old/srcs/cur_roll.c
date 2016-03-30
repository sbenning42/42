/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_roll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 00:46:19 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 00:54:42 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

int		cur_uroll(void)
{
	char	*s;

	cur_goto(cur_scrli(), 0);
	if (!(s = tgetstr("sf", NULL)))
		cur_exit(EXIT_FAILURE, "No \"sf\" capabilitie in term database");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	return (0);
}

int		cur_droll(void)
{
	char	*s;

	cur_goto(0, 0);
	if (!(s = tgetstr("sr", NULL)))
		cur_exit(EXIT_FAILURE, "No \"sr\" capabilitie in term database");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	return (0);
}
