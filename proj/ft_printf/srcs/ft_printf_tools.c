/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 11:23:30 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/24 19:01:15 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_wstrlen(wchar_t *s)
{
	int		i;

	i = 0;
	while (*s != L'\0')
		i++;
	return (i);
}

void			mask1(wchar_t wc, char *s)
{
	char		mask;

	mask = 49280;
	*s = (mask1 >> 8) | (((v >> 6) << 27) >> 27);
	*(s + 1) = ((mask1 << 24) >> 24) | ((v << 26) >> 26);
}

void			mask2(wchar_t wc, char *s)
{
	char		mask;

	mask = 14712960;
}

void			mask3(wchar_t wc, char *s)
{
	char		mask;

	mask = 4034953344;
}

int				wchartochar(wchar_t ws, char *s)
{
	if (ws <= 0X7F)
	{
		*s = ws;
		return (1);
	}
	else if (ws <= 0X7FF)
	{
		mask1(ws, s);
		return (2);
	}
	else if (ws <= 0XFFFF)
	{
		mask2(ws, s);
		return (3);
	}
	else if (ws <= 0X1FFFFF)
	{
		mask3(ws, s);
		return (4);
	}
	else
		return (0);
}

void			ft_wchartochar(wchar_t *ws, char *s);
{
	while (*ws != L'\0')
	{
		s += wchartochar(*ws, s);
		ws++;
	}
}

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
