/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 11:29:41 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/25 15:52:06 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_s(t_printf_mod mod, va_list ap)
{
	char	*cp;
	wchar_t	*wcp;
	int		size;

	wcp = NULL;
	if (mod.flag & LONGINT)
	{
		if (!(wcp = va_arg(ap, wchar_t *)))
			wcp = L"(null)";
		cp = (char *)ft_memalloc((sizeof(char) * (ft_wclen(wcp) * 4 + 1)));
		if (!cp)
			return (0);
		ft_wctoa(wcp, cp);
		size = (mod.prec > -1 && (size_t)mod.prec < ft_strlen(cp)) ? \
		(size_t)mod.prec : ft_strlen(cp);
	}
	else
	{
		if (!(cp = va_arg(ap, char *)))
			cp = "(null)";
		size = (mod.prec > -1 && (size_t)mod.prec < ft_strlen(cp)) ? \
		(size_t)mod.prec : ft_strlen(cp);
	}
	mod.sign = '\0';
	return (ft_printf_cs_val(cp, size, mod));
}

int			print_ls(t_printf_mod mod, va_list ap)
{
	mod.flag |= LONGINT;
	return (print_s(mod, ap));
}

int			print_c(t_printf_mod mod, va_list ap)
{
	char	buf[BUF_SIZE * 4];
	wchar_t	wbuf[BUF_SIZE];
	int		size;

	ft_bzero((void *)buf, sizeof(char) * BUF_SIZE * 4);
	if (mod.flag & LONGINT)
	{
		*wbuf = va_arg(ap, wint_t);
		*(wbuf + 1) = L'\0';
		ft_wctoa(wbuf, buf);
		size = *buf ? ft_strlen(buf) : 1;
	}
	else
	{
		*buf = va_arg(ap, int);
		size = 1;
	}
	mod.sign = '\0';
	return (ft_printf_cs_val(buf, size, mod));
}

int			print_lc(t_printf_mod mod, va_list ap)
{
	mod.flag |= LONGINT;
	return (print_c(mod, ap));
}

int			print_def(t_printf_mod mod, va_list ap)
{
	char	buf[BUF_SIZE * 4];
	wchar_t	wbuf[BUF_SIZE];
	int		size;

	ft_bzero((void *)buf, sizeof(char) * BUF_SIZE);
	if (mod.flag & LONGINT)
	{
		*wbuf = mod.spec;
		*(wbuf + 1) = L'\0';
		ft_wctoa(wbuf, buf);
		size = *buf ? ft_strlen(buf) : 1;
	}
	else
	{
		size = 1;
		*buf = mod.spec;
	}
	mod.sign = '\0';
	return (ft_printf_cs_val(buf, size, mod));
	if (ap)
		return (0);
	else
		return (0);
}
