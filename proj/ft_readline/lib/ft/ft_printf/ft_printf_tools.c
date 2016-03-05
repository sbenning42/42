/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 11:23:30 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/26 12:38:34 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*tool_ujtoa(uintmax_t val, int base, \
			t_printf_mod mod, char *cp)
{
	int		maybevalisequaltozero;

	maybevalisequaltozero = 1;
	while (val || maybevalisequaltozero)
	{
		maybevalisequaltozero = 0;
		if (base == 10)
		{
			*--cp = (val % 10) + '0';
			val /= 10;
		}
		else
		{
			*--cp = base == 16 ? \
			(t_uchar)mod.xdigit[val & 15] : (val & 7) + '0';
			val >>= base == 16 ? 4 : 3;
		}
	}
	if (base == 8 && (mod.flag & ALT) && *cp != '0')
		*--cp = '0';
	return (cp);
}

char		*tool_ultoa(t_ulong val, int base, \
			t_printf_mod mod, char *cp)
{
	int		maybevalisequaltozero;

	maybevalisequaltozero = 1;
	while (val || maybevalisequaltozero)
	{
		maybevalisequaltozero = 0;
		if (base == 10)
		{
			*--cp = (val % 10) + '0';
			val /= 10;
		}
		else
		{
			*--cp = base == 16 ? \
			(t_uchar)mod.xdigit[val & 15] : (val & 7) + '0';
			val >>= base == 16 ? 4 : 3;
		}
	}
	if (base == 8 && (mod.flag & ALT) && *cp != '0')
		*--cp = '0';
	return (cp);
}
