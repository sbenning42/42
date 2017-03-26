/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ardumpi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 13:09:19 by sbenning          #+#    #+#             */
/*   Updated: 2015/09/21 15:36:56 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dar.h"

void		ft_ardumpi(t_dar *ar, t_uint i)
{
	size_t	j;

	j = 0;
	ft_printf("adress: %p\t|", ar->address[i].data);
	while (j < ar->address[i].size)
	{
		ft_printf("%d|", *((t_uchar *)(ar->address[i].data + j)));
		j++;
	}
	ft_printf("\n");
}
