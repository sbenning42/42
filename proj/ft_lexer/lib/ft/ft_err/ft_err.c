/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 04:06:10 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/18 10:10:40 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_err.h"

int			ft_err(char *name, char *msg)
{
	char	*errno_msg;
	int		errno_cp;

	if (!(errno_cp = errno))
		return (errno_cp);
	errno = 0;
	errno_msg = strerror(errno);
	ft_fprintf(2, "{green}%s{eoc}: {red}%s{eoc}: %s\n", name, msg, errno_msg);
	return (errno_cp);
}
