/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_currentrep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 09:53:29 by sbenning          #+#    #+#             */
/*   Updated: 2016/06/30 11:46:18 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"

char		*cd_currentrep(void)
{
	char	*rep;

	if (!(rep = ft_getenv("HOME")))
	{
		ft_error("HOME missing");
		return (NULL);
	}
	return (rep);
}
