#include "ft_printf.h"

int	print_s(t_printf_modifier mod, va_list ap)
{
	char	*cp;
	int	size;

	if (mod.flag & LONGINT)
	{
		;
	}
	else
	{
		if (!(cp = va_arg(ap, char *)))
			cp = "(null)";
		size = (mod.prec && (size_t)mod.prec > ft_strlen(cp)) ? ft_strlen(cp) : (size_t)mod.prec;
	}
	mod.sign = '\0';
	return (ft_printf_cs_val(cp, size, mod));
}

int	print_ls(t_printf_modifier mod, va_list ap)
{
	mod.flag |= LONGINT;
	return (print_s(mod, ap));
}

int	print_c(t_printf_modifier mod, va_list ap)
{
	char	buf[BUF_SIZE];
	int	size;

	ft_bzero((void *)buf, sizeof(char) * BUF_SIZE);
	if (mod.flag & LONGINT)
	{
		;
	}
	else
	{
		size = 1;
		*buf = va_arg(ap, int);
	}
	mod.sign = '\0'; 
	return (ft_printf_cs_val(buf, size, mod));
}

int	print_lc(t_printf_modifier mod, va_list ap)
{
	mod.flag |= LONGINT;
	return (print_c(mod, ap));
}

int	print_def(t_printf_modifier mod, va_list ap)
{
	char	buf[BUF_SIZE];
	int	size;

	ft_bzero((void *)buf, sizeof(char) * BUF_SIZE);
	if (mod.flag & LONGINT)
		;
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
