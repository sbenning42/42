/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_currentrep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 09:53:29 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/15 15:02:30 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"

char		*cd_currentrep(void)
{
	char	*rep;

	if (!(rep = ft_getenv("HOME")))
		cd_exit("HOME needed in the environ");
	return (rep);
}
