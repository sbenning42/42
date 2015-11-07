#include "ft_printf.h"

char		*tool_ujtoa(uintmax_t val, int base, t_printf_modifier mod, char *cp)
{
	int	maybevalisequaltozero;

	maybevalisequaltozero = 1;
	while (val || maybevalisequaltozero)
	{
		maybevalisequaltozero = 0;
		if (base == 10)
		{
			*--cp = (val % 10) + '0';
			val /= 10;
		}
		else
		{
			*--cp = base == 16 ? (t_uchar)mod.xdigit[val & 15] : (val & 7) + '0';
			val >>= base == 16 ? 4 : 3;
		}
	}
	if (base == 8 && (mod.flag & ALT) && *cp != '0')
		*--cp = '0';
	return (cp);
}

char		*tool_ultoa(u_long val, int base, t_printf_modifier mod, char *cp)
{
	int	maybevalisequaltozero;

	maybevalisequaltozero = 1;
	while (val || maybevalisequaltozero)
	{
		maybevalisequaltozero = 0;
		if (base == 10)
		{
			*--cp = (val % 10) + '0';
			val /= 10;
		}
		else
		{
			*--cp = base == 16 ? (t_uchar)mod.xdigit[val & 15] : (val & 7) + '0';
			val >>= base == 16 ? 4 : 3;
		}
	}
	if (base == 8 && (mod.flag & ALT) && *cp != '0')
		*--cp = '0';
	return (cp);
}
