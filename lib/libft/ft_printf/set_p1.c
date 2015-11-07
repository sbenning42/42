#include "ft_printf.h"

int	set_space(t_printf_modifier *mod)
{
	if (!mod->sign)
		mod->sign = ' ';
	return (1);
}

int	set_plus(t_printf_modifier *mod)
{
	mod->sign = '+';
	return (1);
}

int	set_alt(t_printf_modifier *mod)
{
	mod->flag |= ALT;
	return (1);
}

int	set_minus(t_printf_modifier *mod)
{
	mod->flag |= LADJUST;
	return (1);
}

int	set_zero(t_printf_modifier *mod)
{
	mod->flag |= ZEROPAD;
	return (1);
}
