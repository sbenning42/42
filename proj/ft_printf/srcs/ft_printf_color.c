/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:41:03 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/26 16:23:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	color_attrib_copy(char *buf, int color)
{
	int		i;

	i = -1;
	while (color && ++i < NB_COLOR_ATTRIB)
	{
		if (COLOR__(i)->val & color)
		{
			ft_memcpy(buf, COLOR__(i)->attrib, ft_strlen(COLOR__(i)->attrib));
			buf += ft_strlen(COLOR__(i)->attrib);
			color &= ~COLOR__(i)->val;
			if (color)
				ft_memcpy(buf++, ";", 1);
		}
	}
	ft_memcpy(buf, "m\0", 2);
}

void		ft_printf_write_color(int color)
{
	char	buf[BUF_COLOR_SIZE];
	char	*cp;

	ft_bzero((void *)buf, BUF_COLOR_SIZE);
	cp = buf;
	ft_memcpy(cp, "\033[", 2);
	cp += 2;
	if (!color)
		color |= COL_DEF;
	color_attrib_copy(cp, color);
	save_buf(buf, ft_strlen(buf));
}

int			color_flag(const char *fmt)
{
	int		flag;
	int		i;

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

void		ft_printf_apply_color(const char *format)
{
	int		color;

	color = 0;
	set_color(&color, format);
	ft_printf_write_color(color);
}
