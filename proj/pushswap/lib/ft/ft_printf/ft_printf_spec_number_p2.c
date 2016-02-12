/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec_number_p2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:17:32 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/27 11:44:37 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_x(t_printf_mod mod, va_list ap)
{
	uintmax_t	ujval;
	t_ulong		ulval;

	if (!mod.xdigit)
		mod.xdigit = LOW_HEX_CSET;
	if (mod.prec >= 0)
		mod.flag &= ~ZEROPAD;
	mod.sign = '\0';
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
	if ((mod.flag & ALT) && ((mod.flag & INTMAX_SIZE) ? ujval : ulval))
		mod.ox[1] = !ft_strcmp(mod.xdigit, UP_HEX_CSET) ? 'X' : 'x';
	return (ft_printf_diuox_val(ujval, ulval, 16, mod));
}

int				print_lx(t_printf_mod mod, va_list ap)
{
	mod.xdigit = UP_HEX_CSET;
	return (print_x(mod, ap));
}

int				print_o(t_printf_mod mod, va_list ap)
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
	return (ft_printf_diuox_val(ujval, ulval, 8, mod));
}

int				print_lo(t_printf_mod mod, va_list ap)
{
	mod.flag |= LONGINT;
	return (print_o(mod, ap));
}

int				print_p(t_printf_mod mod, va_list ap)
{
	uintmax_t	ujval;

	ujval = (uintmax_t)(uintptr_t)va_arg(ap, void *);
	mod.flag |= INTMAXT;
	mod.xdigit = LOW_HEX_CSET;
	mod.ox[1] = 'x';
	mod.sign = '\0';
	return (ft_printf_p_val(ujval, mod));
}
