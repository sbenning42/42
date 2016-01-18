/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/25 17:52:54 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/05 06:10:53 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void		*ft_memset(void *b, int c, size_t len)
{
	t_uchar	*cp;

	cp = (t_uchar *)b;
	while (len--)
		*cp++ = (t_uchar)c;
	return (b);
}
