/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_motion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:27:36 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/29 19:01:13 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

int			cur_goto(int li, int co)
{
	char	*s;

	if (!(s = tgetstr("cm", NULL)))
		cur_exit(EXIT_FAILURE, "No \"cm\" capabilitie in term database");
	if (!(s = tgoto(s, co, li)))
		cur_exit(EXIT_FAILURE, "tgoto failure");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	return (0);
}

int			cur_home(void)
{
	char	*s;

	if (!(s = tgetstr("ho", NULL)))
		cur_exit(EXIT_FAILURE, "No \"ho\" capabilitie in term database");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	return (0);
}

int			cur_lowhome(void)
{
	char	*s;

	if (!(s = tgetstr("ll", NULL)))
		cur_exit(EXIT_FAILURE, "No \"ll\" capabilitie in term database");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	return (0);
}
