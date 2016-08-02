/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 19:49:51 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/15 10:55:35 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char		*get_shenv(\
			char *id)
{
	char	**ep;
	char	*f;

	ep = ENV;
	while (*ep)
	{
		f = ft_strchr(*ep, '=');
		if (f && !ft_strncmp(id, *ep, f - *ep))
			return (f + 1);
		ep++;
	}
	return (NULL);
}
