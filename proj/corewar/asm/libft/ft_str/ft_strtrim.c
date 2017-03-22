/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:54:46 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/15 13:57:16 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strtrim(char const *s)
{
	size_t			len;
	t_uint			i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = MAX_UINT;
	while (s[++i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		;
	if (!s[i])
		return (ft_strsub(s, i, 1));
	while (s[--len] && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		;
	return (ft_strsub(s, i, len - i + 1));
}
