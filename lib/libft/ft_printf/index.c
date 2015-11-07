#include "ft_printf.h"

int		get_mod_index(char *cset, char c)
{
	char	*f;

	f = ft_strchr(cset, c);
	if (f)
		return (f - cset);
	else if (ft_isdigit(c))
		return (NB_MOD_FUNCTION - 1);
	else
		return (-1);
}

int		get_spec_index(char *cset, char c)
{
	char	*f;

	return ((f = ft_strchr(cset, c)) ? f - cset : NB_SPEC_FUNCTION - 1);
}
