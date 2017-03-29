/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_finaly.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:29:49 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/27 12:03:42 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_save_pad(int size, t_printf_pad_char padchar)
{
	char	pad[size < 1 ? 0 : size + 1];

	if (size < 1)
		return ;
	ft_memset((void *)pad, padchar ? ' ' : '0', size);
	save_buf(pad, size);
}

void		ft_printf_finaly_print(char *cp, int size, int realsize, \
			t_printf_mod mod)
{
	if (!(mod.flag & (LADJUST | ZEROPAD)))
		ft_printf_save_pad(mod.width - realsize, BlankChar);
	if (mod.sign)
		save_buf(&mod.sign, 1);
	if (mod.ox[1])
	{
		mod.ox[0] = '0';
		save_buf(mod.ox, 2);
	}
	if ((mod.flag & (LADJUST | ZEROPAD)) == ZEROPAD)
		ft_printf_save_pad(mod.width - realsize, ZeroChar);
	ft_printf_save_pad(mod.prec - size, ZeroChar);
	save_buf(cp, ((!mod.prec && (mod.spec == 'p') && (*cp == '0')) ? 0 : size));
	if (mod.flag & LADJUST)
		ft_printf_save_pad(mod.width - realsize, BlankChar);
}
