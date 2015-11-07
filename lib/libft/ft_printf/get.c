#include "ft_printf.h"

intmax_t	get_sjarg(va_list ap, t_printf_modifier mod)
{
	if (mod.flag & INTMAXT)
		return (va_arg(ap, intmax_t));
	else if (mod.flag & SIZET)
		return ((intmax_t)va_arg(ap, ssize_t));
	else
		return ((intmax_t)va_arg(ap, long long));
}

long		get_sarg(va_list ap, t_printf_modifier mod)
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

uintmax_t	get_ujarg(va_list ap, t_printf_modifier mod)
{
	if (mod.flag & INTMAXT)
		return (va_arg(ap, uintmax_t));
	else if (mod.flag & SIZET)
		return ((uintmax_t)va_arg(ap, size_t));
	else
		return ((uintmax_t)va_arg(ap, unsigned long long));
}

u_long		get_uarg(va_list ap, t_printf_modifier mod)
{
	if (mod.flag & LONGINT)
		return (va_arg(ap, u_long));
	else if (mod.flag & SHORTINT)
		return ((u_long)(u_short)va_arg(ap, int));
	else if (mod.flag & CHARINT)
		return ((u_long)(u_char)va_arg(ap, int));
	else
		return ((u_long)va_arg(ap, u_int));
}
