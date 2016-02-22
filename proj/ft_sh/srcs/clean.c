/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 11:15:57 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/19 11:18:41 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void		cleanslash(\
			char *cp)
{
	int		i;

	i = 0;
	while (cp[i])
	{
		if (cp[i] == '/' && cp[i + 1] == '/')
		{
			cp[i] = 0;
			ft_strcat(cp, cp + i-- + 1);
		}
		if (cp[i] == '/' && !cp[i + 1] && i)
			cp[i--] = 0;
		i++;
	}
}

void		supprtwopoint(\
			char *s, int *j)
{
	int		i;
	char	*f;

	i = *j;
	if (s[i - 1] != '/' || (s[i + 2] && s[i + 2] != '/'))
		return ;
	else if (!s[i + 2] && i != 1)
	{
		s[i - 1] = 0;
		f = ft_strrchr(s, '/');
		f = 0;
	}
	else if (!s[i + 2])
		s[i] = 0;
	else
	{
		s[i - 1] = 0;
		f = ft_strrchr(s, '/');
		*f = 0;
		ft_strcat(s, s + i + 2);
	}
	*j = -1;
}

void		supprpoint(\
			char *s, int *j)
{
	int		i;

	i = *j;
	if (s[i - 1] != '/' || (s[i + 1] && s[i + 1] != '/'))
		return ;
	else if (!s[i + 1])
	{
		s[i] = 0;
		s[i - 1] = (i == 1 ? s[i - 1] : 0);
		return ;
	}
	if (i == 1)
		ft_strcpy(s, s + 2);
	else if (!s[i + 2])
	{
		s[i - 1] = 0;
		s[i] = 0;
		s[i + 1] = 0;
	}
	else
	{
		s[i - 1] = 0;
		ft_strcat(s, s + i + 1);
	}
	*j = -1;
}
