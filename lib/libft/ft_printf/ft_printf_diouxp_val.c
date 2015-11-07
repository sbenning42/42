#include "ft_printf.h"

int		ft_printf_diuoxp_val(uintmax_t ujval, u_long ulval, int base, t_printf_modifier mod)
{
	int	size;
	int	realsize;
	char	buf[BUF_SIZE];
	char	*cp;

	ft_bzero(buf, sizeof(char) * BUF_SIZE);
	cp = buf + BUF_SIZE;
	if (mod.flag & INTMAX_SIZE)
	{
		if (ujval || mod.prec || (mod.flag & ALT && base == 8))
			cp = tool_ujtoa(ujval, base, mod, cp);

	}
	else
	{
		if (ulval || mod.prec || (mod.flag & ALT && base == 8))
			cp = tool_ultoa(ulval, base, mod, cp);

	}
	size = buf + BUF_SIZE - cp;
	realsize = size > mod.prec ? size : mod.prec;
	realsize += mod.sign ? 1 : 0;
	realsize += mod.ox[1] ? 2 : 0;
	ft_printf_finaly_print(cp, size, realsize, mod);
	return (mod.width > realsize ? mod.width : realsize);
}


int		ft_printf_p_val(uintmax_t ujval, t_printf_modifier mod)
{
	int	size;
	int	realsize;
	char	buf[BUF_SIZE];
	char	*cp;

	ft_bzero(buf, sizeof(char) * BUF_SIZE);
	cp = buf + BUF_SIZE;
	if (ujval)
	{
		cp = tool_ujtoa(ujval, 16, mod, cp);
		size = buf + BUF_SIZE - cp;
		realsize = size > mod.prec ? size : mod.prec;
		realsize += 2;
	}
	else
	{
		cp = "(nil)";
		size = 5;
		realsize = 5;
		mod.ox[1] = '\0';
		mod.prec = -1;
	}
	ft_printf_finaly_print(cp, size, realsize, mod);
	return (mod.width > realsize ? mod.width : realsize);
}

int		ft_printf_cs_val(char *cp, int size, t_printf_modifier mod)
{
	mod.prec = 0;
	mod.flag &= ~ZEROPAD;
	ft_printf_finaly_print(cp, size, size, mod);
	return (mod.width > size ? mod.width : size);
}








