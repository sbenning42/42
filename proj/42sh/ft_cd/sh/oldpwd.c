/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oldpwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 11:28:22 by sbenning          #+#    #+#             */
/*   Updated: 2016/06/30 11:43:07 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"

char		*cd_oldpwd(void)
{
	char	*path;

	if (!(path = ft_getenv("OLDPWD")))
	{
		ft_error("OLDPWD missing");
		return (NULL);
	}
	return (ft_strdup(path));
}
