/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:15:42 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/21 16:18:35 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int ft_err(char *key, char *msg)
{
	int		cp;

	if (!errno)
		return (errno);
	cp = errno;
	errno = 0;
	if ((env()->o & O_COLOR) == O_COLOR)
		ft_fprintf(2, "{green}%s{eoc}: {red}%s{eoc}: %s\n", key, msg, strerror(cp));
	else
		ft_fprintf(2, "%s: %s: %s\n", key, msg, strerror(cp));
	return (cp);
}
