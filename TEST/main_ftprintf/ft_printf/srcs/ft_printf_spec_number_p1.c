/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec_number_p1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:48:09 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/27 11:44:37 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_d(t_printf_mod mod, va_list ap)
{
	uintmax_t	ujval;
	t_ulong		ulval;

	if (mod.flag & INTMAX_SIZE)
	{
		ujval = (intmax_t)get_sjarg(ap, mod);
		ulval = 0;
		if ((intmax_t)ujval < 0 && (mod.sign = '-'))
			ujval = -ujval;
	}
	else
	{
		ulval = (long)get_sarg(ap, mod);
		ujval = 0;
		if ((long)ulval < 0 && (mod.sign = '-'))
			ulval = -ulval;
	}
	if (mod.prec >= 0)
		mod.flag &= ~ZEROPAD;
	return (ft_printf_diuox_val(ujval, ulval, 10, mod));
}

int				print_ld(t_printf_mod mod, va_list ap)
{
	mod.flag |= LONGINT;
	return (print_d(mod, ap));
}

int				print_u(t_printf_mod mod, va_list ap)
{
	uintmax_t	ujval;
	t_ulong		ulval;

	if (mod.flag & INTMAX_SIZE)
	{
		ujval = get_ujarg(ap, mod);
		ulval = 0;
	}
	else
	{
		ulval = get_uarg(ap, mod);
		ujval = 0;
	}
	mod.sign = '\0';
	if (mod.prec >= 0)
		mod.flag &= ~ZEROPAD;
	return (ft_printf_diuox_val(ujval, ulval, 10, mod));
}

int				print_lu(t_printf_mod mod, va_list ap)
{
	mod.flag |= LONGINT;
	return (print_u(mod, ap));
}
