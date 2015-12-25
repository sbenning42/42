/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:00:09 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/12 05:34:11 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

void		ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	t_uint		i;

	if (!s || !f)
		return ;
	i = MAX_UINT;
	while (s[++i])
		f(i, &(s[i]));
}
