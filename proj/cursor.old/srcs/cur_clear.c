/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 20:20:52 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/29 20:25:32 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

int					cur_clrall(void)
{
	char	*s;

	if (!(s = tgetstr("cl", NULL)))
		cur_exit(EXIT_FAILURE, "No \"cl\" capabilitie in term database");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	return (0);
}

int					cur_clrli(void)
{
	char	*s;

	cur_bli();
	if (!(s = tgetstr("cd", NULL)))
		cur_exit(EXIT_FAILURE, "No \"cd\" capabilitie in term database");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	return (0);
}

int					cur_clreli(void)
{
	char	*s;

	if (!(s = tgetstr("ce", NULL)))
		cur_exit(EXIT_FAILURE, "No \"ce\" capabilitie in term database");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	return (0);
}

int					cur_clrx(int offset)
{
	char	*s;

	if (!(s = tgetstr("ec", NULL)))
		cur_exit(EXIT_FAILURE, "No \"ec\" capabilitie in term database");
	if (!(s = tparm(s, offset)))
		cur_exit(EXIT_FAILURE, "tparm failure");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	return (0);
}

