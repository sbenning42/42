/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_limotion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 17:31:55 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/29 19:01:05 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

int			cur_bli(void)
{
	char	*s;

	if (!(s = tgetstr("cr", NULL)))
		cur_exit(EXIT_FAILURE, "No \"cr\" capabilitie in term database");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	return (0);
}

int			cur_eli(void)
{
	char	*s;

	if (!(s = tgetstr("cr", NULL)))
		cur_exit(EXIT_FAILURE, "No \"cr\" capabilitie in term database");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	if (!(s = tgetstr("RI", NULL)))
		cur_exit(EXIT_FAILURE, "No \"RI\" capabilitie in term database");
	if (!(s = tparm(s, cur_scrco())))
		cur_exit(EXIT_FAILURE, "tparm failure");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	return (0);
}

int			cur_nli(void)
{
	char	*s;

	if (!(s = tgetstr("do", NULL)))
		cur_exit(EXIT_FAILURE, "No \"do\" capabilitie in term database");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	return (0);
}

int			cur_pli(void)
{
	char	*s;

	if (!(s = tgetstr("up", NULL)))
		cur_exit(EXIT_FAILURE, "No \"up\" capabilitie in term database");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	return (0);
}
