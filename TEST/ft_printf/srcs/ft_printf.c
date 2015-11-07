/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 10:38:18 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/05 12:09:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int					print_no_fmt(const char *format)
{
	const char				*cp;

	cp = format;
	while (*format && *format != '%')
		format++;
	save_buf((void *)cp, format - cp);
	return (format - cp);
}

int							ft_vlprintf(const char *format, va_list ap)
{
	t_printf_spec_function	print_fmt[NB_SPEC_FUNCTION];
	t_printf_set_function	set_mod[NB_MOD_FUNCTION];
	t_printf_mod			mod;
	int						len;
	long int				tlen;

	ini_print(print_fmt);
	ini_set(set_mod);
	tlen = 0;
	while (*format)
	{
		len = print_no_fmt(format);
		tlen += len;
		if (!*(format += len))
			break ;
		ft_bzero((void *)&mod, sizeof(t_printf_mod));
		mod.prec = -1;
		if (*(format += set_fmt_mod(format, &mod, set_mod)))
			format++;
		tlen += print_fmt[SPEC__(mod.spec)](mod, ap);
	}
	return (tlen);
}
