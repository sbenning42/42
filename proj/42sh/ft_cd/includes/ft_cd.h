#ifndef FT_CD_H
# define FT_CD_H

# define CD_O_L 0x1
# define CD_O_P 0x2
# define CD_ISO(X, Y) (X & Y) == Y

# include "libft.h"
# include <sys/stat.h>

int			ft_getopt(int ac, char **av, char *charset);
int			ft_countarg(int ac, char **av);
char		*cd_currentrep(void);
char		*cd_cleanpath(char *path);
char		*cd_oldpwd(void);

t_dlist		*makelst(char *path);
t_dlist		*cleanlst(t_dlist *e);
t_dlist		*cleanlstparent(t_dlist *lst);
char		*convertlst(t_dlist **alst);

void  	    cd_exit(char *msg);

#endif
