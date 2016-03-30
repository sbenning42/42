/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_comotion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 17:31:55 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 09:42:27 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

int			cur_bco(void)
{
	cur_goto(0, *co());
	return (0);
}

int			cur_eco(void)
{
	cur_goto(cur_scrli(), *co());
	return (0);
}

int			cur_nco(void)
{
	char	*s;

	if (!(s = tgetstr("nd", NULL)))
		cur_exit(EXIT_FAILURE, "No \"nd\" capabilitie in term database");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	return (0);
}

int			cur_pco(void)
{
	char	*s;

	if (!(s = tgetstr("le", NULL)))
		cur_exit(EXIT_FAILURE, "No \"le\" capabilitie in term database");
	if (tputs(s, 1, mput))
		cur_exit(EXIT_FAILURE, "tputs failure");
	return (0);
}
