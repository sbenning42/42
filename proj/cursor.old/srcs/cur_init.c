/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:13:00 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 09:35:03 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

int			cur_init(char *term)
{
	char	msg[2048];
	int		success;

	if (!term)
		cur_exit(EXIT_FAILURE, CAP_SPECIFYTERM);
	signal(SIGWINCH, cur_resize);
	cur_setlico();
	if ((success = tgetent(NULL, term)) < 0)
		cur_exit(EXIT_FAILURE, CAP_NOACCESSTERM);
	else if (success)
		return (0);
	ft_sprintf(msg, CAP_UNDEFTERM, term);
	cur_exit(EXIT_FAILURE, msg);
	return (-1);
}
