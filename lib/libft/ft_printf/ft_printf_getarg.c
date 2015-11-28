/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getarg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:26:20 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/27 14:13:27 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_sjarg(va_list ap, t_printf_mod mod)
{
	if (mod.flag & INTMAXT)
		return (va_arg(ap, intmax_t));
	else if (mod.flag & SIZET)
		return ((intmax_t)va_arg(ap, ssize_t));
	else
		return ((intmax_t)va_arg(ap, long long));
}

long		get_sarg(va_list ap, t_printf_mod mod)
{
	if (mod.flag & LONGINT)
		return (va_arg(ap, long));
	else if (mod.flag & SHORTINT)
		return ((long)(short)va_arg(ap, int));
	else if (mod.flag & CHARINT)
		return ((long)(char)va_arg(ap, int));
	else
		return ((long)va_arg(ap, int));
}

uintmax_t	get_ujarg(va_list ap, t_printf_mod mod)
{
	if (mod.flag & INTMAXT)
		return (va_arg(ap, uintmax_t));
	else if (mod.flag & SIZET)
		return ((uintmax_t)va_arg(ap, size_t));
	else
		return ((uintmax_t)va_arg(ap, unsigned long long));
}

t_ulong		get_uarg(va_list ap, t_printf_mod mod)
{
	if (mod.flag & LONGINT)
		return (va_arg(ap, t_ulong));
	else if (mod.flag & SHORTINT)
		return ((t_ulong)(t_ushort)va_arg(ap, int));
	else if (mod.flag & CHARINT)
		return ((t_ulong)(t_uchar)va_arg(ap, int));
	else
		return ((t_ulong)va_arg(ap, t_uint));
}
