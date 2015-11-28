/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 11:29:41 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/25 11:00:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_s(t_printf_mod mod, va_list ap)
{
	char	*cp;
	int		size;

	if (mod.flag & LONGINT)
	{
/*		if ((wcp = va_arg(ap, wchar_t *)))
		{
			cp = NULL;
			size = (mod.prec > 0 && (size_t)mod.prec > ft_wstrlen(wcp)) ? \
			ft_wstrlen(wcp) : (size_t)mod.prec;  //remove the >0 for modprec
		}
		else
		{
			cp = "(null)";
			size = (mod.prec && (size_t)mod.prec > ft_strlen(cp)) ? \
			ft_strlen(cp) : (size_t)mod.prec;
		}
*/cp = NULL; size=0;	}
	else
	{
		if (!(cp = va_arg(ap, char *)))
			cp = "(null)";
		size = (mod.prec && (size_t)mod.prec > ft_strlen(cp)) ? \
		ft_strlen(cp) : (size_t)mod.prec;
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
	char	buf[BUF_SIZE];
	int		size;

	ft_bzero((void *)buf, sizeof(char) * BUF_SIZE);
	if (mod.flag & LONGINT)
	{
/*		*wbuf = va_arg(ap, wint_t);
		size = 1;
*/size = 0;	}
	else
	{
		size = 1;
		*buf = va_arg(ap, int);
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
	char	buf[BUF_SIZE];
	int		size;

	ft_bzero((void *)buf, sizeof(char) * BUF_SIZE);
	if (mod.flag & LONGINT)
		size = 0;
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
