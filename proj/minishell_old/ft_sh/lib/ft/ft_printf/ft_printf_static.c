/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_static.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:17:27 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/26 15:22:12 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list						**buflist(void)
{
	static t_list			*bufs;

	return (&bufs);
}

t_printf_color				*color_attrib(int i)
{
	static t_printf_color	color[NB_COLOR_ATTRIB];
	static int				call;

	if (!call)
	{
		ini_color(color);
		call = 1;
	}
	return (color + i);
}
