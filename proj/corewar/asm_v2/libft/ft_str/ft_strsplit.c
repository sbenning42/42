/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 20:30:42 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/25 11:21:33 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

static size_t		ft_nbr_wrd(char const *s, char c)
{
	size_t		len;
	t_uint		i;

	len = 0;
	i = MAX_UINT;
	if (s[0] != c)
		++len;
	while (s[++i])
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			++len;
	return (len);
}

static char			**ft_split(char const *s, char c, size_t len, char **dst)
{
	t_uint			i;
	t_uint			j;
	t_uint			start;
	t_uchar			flag;

	i = MAX_UINT;
	j = 0;
	flag = 0;
	while (j < len)
	{
		if (s[++i] != c && !flag)
		{
			start = i;
			++flag;
		}
		if (flag && (s[i] == c || s[i] == '\0'))
		{
			flag = 0;
			dst[j++] = ft_strsub(s, start, i - start);
		}
	}
	return (dst);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t		len;
	char		**dst;

	if (!s)
		return (NULL);
	len = ft_nbr_wrd(s, c);
	if (!(dst = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	if (!ft_strlen(s))
	{
		dst[0] = NULL;
		return (dst);
	}
	dst[len] = NULL;
	return (ft_split(s, c, len, dst));
}
