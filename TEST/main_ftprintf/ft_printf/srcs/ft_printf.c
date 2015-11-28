/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 10:38:18 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/27 14:14:04 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int					ft_printf_skip_color(const char *format)
{
	int						n;

	n = 0;
	while (*format && *format != '}')
	{
		n++;
		format++;
	}
	if (!*format)
		return (0);
	return (n);
}

static int					print_no_fmt(const char *format)
{
	const char				*cp;
	const char				*tmp;

	cp = format;
	tmp = cp;
	while (*format && *format != '%')
	{
		if (*format == '{')
		{
			if (format != tmp)
				save_buf((void *)tmp, format - tmp);
			ft_printf_apply_color(format);
			format += ft_printf_skip_color(format);
			tmp = format + 1;
			if (!tmp)
				return (format - cp);
		}
		format++;
	}
	save_buf((void *)tmp, format - tmp);
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
		if (*(format += set_fmt_mod(format, &mod, set_mod, ap)))
			format++;
		tlen += print_fmt[get_spec_index(SPEC_CSET, mod.spec)](mod, ap);
	}
	return (tlen);
}
