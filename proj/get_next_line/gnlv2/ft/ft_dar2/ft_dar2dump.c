/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dar2dump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:17:27 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/25 11:18:07 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dar2.h"

void		ft_dar2dump(t_dar2 *dar, void (*f)(void *))
{
	t_uint	i;

	i = 0;
	while (i < dar->size)
	{
		if (f)
			f(dar->ar[i]);
		i++;
	}
}
