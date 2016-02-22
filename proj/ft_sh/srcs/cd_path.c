/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 11:19:12 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/19 11:21:03 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void		gothrowabs(\
			char *dest, char *go)
{
	int		i;

	i = 0;
	while (go[i])
	{
		if (go[i] == '.' && go[i + 1] != '.')
			supprpoint(go, &i);
		else if (go[i] == '.' && go[i + 1] == '.')
			supprtwopoint(go, &i);
		i++;
	}
	ft_strcpy(dest, go);
}

void		gothrowrel(\
			char *dest, char *go, char *pwd)
{
	ft_strcpy(dest, pwd);
	ft_strcat(dest, "/");
	ft_strcat(dest, go);
	gothrowabs(dest, dest);
}

char		*constructpwd(\
			char *nrel, char *old)
{
	char	cp[FT_SH_CWD_PATH_SIZE + 1];

	ft_strcpy(cp, nrel);
	cleanslash(cp);
	ft_bzero((void *)nrel, sizeof(char) * (FT_SH_CWD_PATH_SIZE + 1));
	if (*cp == '/')
		gothrowabs(nrel, cp);
	else
		gothrowrel(nrel, cp, old);
	return (nrel);
}
