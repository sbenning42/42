/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_xlicomotion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 19:32:45 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 09:44:38 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

int			cur_xnco(int offset)
{
	char	*s;

	if (!(s = tgetstr("RI", NULL)))
		cur_exit(EXIT_FAILURE, "No \"LE\" capabilitie in term database");
	if (!(s = tparm(s, offset)))
		cur_exit(EXIT_FAILURE, "tparm failure");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	*co() += offset;
	return (0);
}

int			cur_xpco(int offset)
{
	char	*s;

	if (!(s = tgetstr("LE", NULL)))
		cur_exit(EXIT_FAILURE, "No \"LE\" capabilitie in term database");
	if (!(s = tparm(s, offset)))
		cur_exit(EXIT_FAILURE, "tparm failure");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	*co() -= offset;
	return (0);
}

int			cur_xnli(int offset)
{
	char	*s;

	if (!(s = tgetstr("DO", NULL)))
		cur_exit(EXIT_FAILURE, "No \"DO\" capabilitie in term database");
	if (!(s = tparm(s, offset)))
		cur_exit(EXIT_FAILURE, "tparm failure");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	*li() +=  offset;
	return (0);
}

int			cur_xpli(int offset)
{
	char	*s;

	if (!(s = tgetstr("UP", NULL)))
		cur_exit(EXIT_FAILURE, "No \"UP\" capabilitie in term database");
	if (!(s = tparm(s, offset)))
		cur_exit(EXIT_FAILURE, "tparm failure");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	*li() -= offset;
	return (0);
}
