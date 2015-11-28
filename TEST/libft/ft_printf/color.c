/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 11:08:19 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/05 12:04:57 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf_color				*color_attrib(int i)
{
	static t_printf_color	color[NB_COLOR_ATTRIB];
	static int				first_call;

	if (!first_call)
	{
		ini_color(color);
		first_call = 1;
	}
	return (color + i);
}

int							color_flag(const char *fmt)
{
	int						flag;
	int						i;

	flag = 0;
	while (*fmt && *fmt != '}')
	{
		i = -1;
		if (*fmt == '|')
			fmt++;
		else
		{
			while (++i < NB_COLOR_ATTRIB)
			{
				if (!ft_strncmp(fmt, COLOR__(i)->id, COLOR__(i)->len))
				{
					flag |= COLOR__(i)->val;
					fmt += COLOR__(i)->len;
					break ;
				}
			}
		}
		if (i == NB_COLOR_ATTRIB)
			break ;
	}
	return (flag);
}

void	ft_printf_apply_color(const char *format)
{
	int	color;

	color = 0;
	set_color(&color, format);
	ft_printf_write_color(color);
}






