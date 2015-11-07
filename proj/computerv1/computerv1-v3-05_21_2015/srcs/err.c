#include "computerv1.h"

int		err_malloc(t_dtab *dtab)
{
	ft_putendl("Computerv1: Malloc error appear.");
	dtab_del(dtab);
	return (ERROR);
}

int		err_lexer(t_dtab *dtab)
{
	ft_putendl("Computerv1: Lexer error appear");
	dtab_del(dtab);
	return (ERROR);
}

int		err_parser(t_dtab *dtab)
{
	ft_putendl("Computerv1: Parser error appear");
	dtab_del(dtab);
	return (ERROR);
}
