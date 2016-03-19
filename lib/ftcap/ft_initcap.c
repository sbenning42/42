/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initcap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 14:23:21 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/19 16:53:34 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cap.h"

void		ft_initcap(void)
{
	char	msg[2048];
	char	*termtype;
	int		success;

	if (!(termtype = ft_getenv("TERM")))
		ft_exit(EXIT_FAILURE, CAP_SPECIFYTERM);
	if (!(success = tgetent(NULL, termtype)))
	{
		ft_sprintf(msg, CAP_UNDEFTERM, termtype);
		ft_exit(EXIT_FAILURE, msg);
	}
	if (success < 0)
		ft_exit(EXIT_FAILURE, CAP_NOACCESSTERM);
}
