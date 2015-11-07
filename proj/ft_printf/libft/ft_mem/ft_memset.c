/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/25 17:52:54 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/15 12:14:32 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"




void		*ft_memset(void *b, int c, size_t len)
{
	b += (len - 1);
	while (len--)
	{
		*(t_uchar *)b = (t_uchar)c;
		if (len)
			b--;
	}
	return (b);
}