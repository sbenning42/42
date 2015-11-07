#include "ft_printf.h"

int	print_d(t_printf_modifier mod, va_list ap)
{
	uintmax_t	ujval;
	u_long		ulval;

	if (mod.flag & INTMAX_SIZE)
	{
		ujval = (intmax_t)get_sjarg(ap, mod);
		if ((intmax_t)ujval < 0)
		{
			ujval = -ujval;
			mod.sign = '-';
		}
	}
	else
	{
		ulval = (long)get_sarg(ap, mod);
		if((long)ulval < 0)
		{
			ulval = -ulval;
			mod.sign = '-';
		}

	}
	if (mod.prec >= 0 )
		mod.flag &= ~ZEROPAD;
	return (ft_printf_diuoxp_val(ujval, ulval, 10, mod));
}

int	print_ld(t_printf_modifier mod, va_list ap)
{
	mod.flag |= LONGINT;
	return (print_d(mod, ap));
}

int	print_u(t_printf_modifier mod, va_list ap)
{
	uintmax_t	ujval;
	u_long		ulval;

	if (mod.flag & INTMAX_SIZE)
		ujval = get_ujarg(ap, mod);
	else
		ulval = get_uarg(ap, mod);
	mod.sign = '\0';
	if (mod.prec >= 0 )
		mod.flag &= ~ZEROPAD;
	return (ft_printf_diuoxp_val(ujval, ulval, 10, mod));
}

int	print_lu(t_printf_modifier mod, va_list ap)
{
	mod.flag |= LONGINT;
	return (print_u(mod, ap));
}
