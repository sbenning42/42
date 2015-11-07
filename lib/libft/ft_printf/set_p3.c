#include "ft_printf.h"

int		set_color(t_printf_modifier *mod, const char *fmt)
{
	int	n;

	n = 0;
	while (*(fmt + ++n))
	{
		if (*(fmt + n) == ']')
			break ;
	}
	if (!*(fmt + n))
		return (1);
	mod->color |= color_flag(++fmt);
	return (++n);
}

int		set_prec(t_printf_modifier *mod, const char *fmt)
{
	int	n;

	n = 1;
	mod->prec = ft_atoi(++fmt);
	while (ft_isdigit(*fmt++))
		n++;
	return (n);
}

int		set_width(t_printf_modifier *mod, const char *fmt)
{
	int	n;

	n = 0;
	mod->width = ft_atoi(fmt);
	while (ft_isdigit(*fmt++))
		n++;
	return (n);
}
