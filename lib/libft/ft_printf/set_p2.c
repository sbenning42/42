#include "ft_printf.h"

int	set_h(t_printf_modifier *mod)
{
	if (mod->flag & SHORTINT)
	{
		mod->flag &= ~SHORTINT;
		mod->flag |= CHARINT;
	}
	else
		mod->flag |= SHORTINT;
	return (1);
}

int	set_l(t_printf_modifier *mod)
{
	if (mod->flag & LONGINT)
	{
		mod->flag &= ~LONGINT;
		mod->flag |= LLONGINT;
	}
	else
		mod->flag |= LONGINT;
	return (1);
}

int	set_j(t_printf_modifier *mod)
{
	mod->flag |= INTMAXT;
	return (1);
}

int	set_z(t_printf_modifier *mod)
{
	mod->flag |= SIZET;
	return (1);
}
