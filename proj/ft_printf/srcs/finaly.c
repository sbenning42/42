/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finaly.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 11:26:02 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/24 18:21:09 by sbenning         ###   ########.fr       */
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

void	ft_printf_write_color(int color)
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

static void	ft_printf_write_pad(int size, t_printf_pad_char padchar)
{
	char	pad[size < 1 ? 0 : size + 1];

	if (size < 1)
		return ;
	ft_memset((void *)pad, padchar ? ' ' : '0', size);
	save_buf(pad, size);
}

static void	ft_printf_write(char *s, int size)
{
	if (size < 1)
		return ;
	save_buf(s, size);
}

void		ft_printf_finaly_print(char *cp, int size, int realsize, \
			t_printf_mod mod)
{
	//ft_printf_write_color(mod.color);
	if (!(mod.flag & (LADJUST | ZEROPAD)))
		ft_printf_write_pad(mod.width - realsize, BlankChar);
	if (mod.sign)
		ft_printf_write(&mod.sign, 1);
	if (mod.ox[1])
	{
		mod.ox[0] = '0';
		ft_printf_write(mod.ox, 2);
	}
	if ((mod.flag & (LADJUST | ZEROPAD)) == ZEROPAD)
		ft_printf_write_pad(mod.width - realsize, ZeroChar);
	ft_printf_write_pad(mod.prec - size, ZeroChar);
	save_buf(cp, (((!mod.prec) && (mod.spec == 'p') && (*cp == '0')) ? 0 : size));
	if (mod.flag & LADJUST)
		ft_printf_write_pad(mod.width - realsize, BlankChar);
	//ft_printf_write_color(COL_DEF);
}

void		ft_printf_finaly_wprint(wchar_t *wcp, int size, int realsize, \
			t_printf_mod mod)
{
	//ft_printf_write_color(mod.color);
	if (!(mod.flag & (LADJUST | ZEROPAD)))
		ft_printf_write_pad(mod.width - realsize, BlankChar);
	if (mod.sign)
		ft_printf_write(&mod.sign, 1);
	if ((mod.flag & (LADJUST | ZEROPAD)) == ZEROPAD)
		ft_printf_write_pad(mod.width - realsize, ZeroChar);
	ft_printf_write_pad(mod.prec - size, ZeroChar);
	save_wbuf(wcp, size);
	if (mod.flag & LADJUST)
		ft_printf_write_pad(mod.width - realsize, BlankChar);
	//ft_printf_write_color(COL_DEF);
}
