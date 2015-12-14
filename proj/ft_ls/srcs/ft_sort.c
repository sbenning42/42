/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:09:07 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/14 17:58:40 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		s_lex(void *s1, void *s2)
{
	return ((ft_strcmp((char *)s1, (char *)s2)) < 0);
}

int		s_rlex(void *s1, void *s2)
{
	return (!s_lex(s1, s2));
}

int		s_time(void *s1, void *s2)
{
	//return (time((time_t *)s1) - time((time_t *)s2));
	return (0);
}

int		s_rtime(void *s1, void *s2)
{
	return (!s_time(s1, s2));
}
