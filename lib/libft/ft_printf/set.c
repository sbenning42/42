#include "ft_printf.h"

int		set_fmt_mod\
		(const char *fmt, t_printf_modifier *mod, t_printf_set_function *set_mod)
{
	char	*cp;
	int	index;

	cp = (char *)++fmt;
	while (*fmt)
	{
		index = MOD__(*fmt);
		if (index == -1)
			break ;
		fmt += set_mod[index](mod, fmt);
	}
	mod->spec = *fmt;
	return (fmt - (cp - 1));
}
