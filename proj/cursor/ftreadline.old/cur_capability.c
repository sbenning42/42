/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_capability.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:02:12 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 12:06:29 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

void		cur_tputs(char *capability)
{
	char	*str;
	char	msg[1024];

	if (!(str = tgetstr(capability, NULL)))
	{
		ft_sprintf(msg, "No \"%s\" capability", capability);
		cur_exit(EXIT_FAILURE, msg);
	}
	if (tputs(str, 1, cur_put))
		cur_exit(EXIT_FAILURE, "tputs failure");
}

void		cur_tparm(char *capability, int param)
{
	char	*str;
	char	msg[1024];

	if (!(str = tgetstr(capability, NULL)))
	{
		ft_sprintf(msg, "No \"%s\" capability", capability);
		cur_exit(EXIT_FAILURE, msg);
	}
	if (!(str = tparm(str, param)))
		cur_exit(EXIT_FAILURE, "tputs failure");
	if (tputs(str, 1, cur_put))
		cur_exit(EXIT_FAILURE, "tputs failure");
}
