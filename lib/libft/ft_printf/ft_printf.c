#include "ft_printf.h"

static int			print_no_fmt(const char *FMT)
{
	const char		*cp;

	cp = FMT;
	while (*FMT && *FMT != '%')
		FMT++;
	save_buf((void *)cp, FMT - cp);
	return (FMT - cp);
}

int				ft_vlprintf(const char *FMT, va_list ap)
{
	t_printf_spec_function	print_fmt[NB_SPEC_FUNCTION];
	t_printf_set_function	set_mod[NB_MOD_FUNCTION];
	t_printf_modifier	mod;
	int			len;
	long long int		tlen;

	ini_print(print_fmt);
	ini_set(set_mod);
	tlen = 0;
	while (*FMT)
	{
		len = print_no_fmt(FMT);
		tlen += len;
		if (!*(FMT += len))
			break ;
		ft_bzero((void *)&mod, sizeof(t_printf_modifier));
		mod.prec = -1;
		if (*(FMT += set_fmt_mod(FMT, &mod, set_mod)))
			FMT++;
		tlen += print_fmt[SPEC__(mod.spec)](mod, ap);
	}
	return (tlen);
}
