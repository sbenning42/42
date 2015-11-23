#ifndef IO_H
# define IO_H

# include "libft.h"
# include "libdic.h"
# include <termios.h>

# define IO_BS 4
# define IO_DSET io_defsettings()

typedef int		(*t_io_handle_f)(t_dlist **, t_dlist **, int *, char *);
int				ft_dlstlen(t_dlist *l);
t_dlist			**io_save_input(t_dlist *l);
t_dic_entry		*io_defsettings(void);
void			io_del_input(void *content, size_t size);
void			io_dlstprint(t_dlist *l);
void			io_dlstdprint(t_dlist *l);
void			io_dlstnprint(t_dlist *l);
void			io_clear_input(t_dlist *l, int size);

int				io_ctrlc_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key);
int				io_ctrld_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key);
int				io_ctrlz_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key);
int				io_tab_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key);
int				io_retarr_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key);
int				io_suppr_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key);
int				io_nl_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key);
int				io_up_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key);
int				io_right_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key);
int				io_down_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key);
int				io_left_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key);

int				io_smart_input(char *prompt, char **input, t_dic_entry *dic);

#endif
