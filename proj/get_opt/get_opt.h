#ifndef GET_OPT_H
# define GET_OPT_H

# include "libft.h"

# define GO_NAME "ft_ls"
# define GO_ERR_MSG "toto"

int	get_opt(char *cs, int *opt, int ac, char **av);
void	print_opt(char *cs, int *opt);

#endif
