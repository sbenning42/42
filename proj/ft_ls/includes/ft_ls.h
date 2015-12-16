/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/22 16:21:28 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/16 15:47:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <time.h>
# include <errno.h>
# include "libft.h"
# include "ft_tree.h"

# define KEYSIZE_LS 510
# define PATHSIZE_LS 2096
# define CSET_O "alRrtvG"
# define SIZE_O 7

# define O_PRIVATE_ERROR 0x1
# define O_PRIVATE_MULTI 0x100
# define O_PRIVATE_MAX 0x200

# define O_HIDE 0x2
# define O_LONG 0x4
# define O_RECU 0x8
# define O_REVE 0x10
# define O_TIME 0x20
# define O_VERBOSE 0x40
# define O_COLOR 0x80

# define T_ERROR 0x1
# define T_NODIR 0x2
# define T_DIR 0x4

# define FMT_U1 "{green|gr}%s{eoc}: {gr}%s{eoc} -- {red}%c{eoc}\n"
# define FMT_U2 "{pink}%s{eoc}: {gr}%s{eoc} [{pink}-%s{eoc}] [{pink}%s{eoc}]\n"
# define FMT_VERBOSE "{green|gr}%s{eoc}: {yellow}%s{eoc}: {gr}%s{eoc}: "
# define FMT_S "{green|gr}%s{eoc}: {yellow}%s{eoc}: {gr}%s{eoc}: "

typedef struct		s_ls_entry
{
	int				type;
	char			path[PATHSIZE_LS + 1];
	char			key[KEYSIZE_LS + 1];
	//struct stat		info;
	struct stat		stat;
}					t_ls_entry;

typedef struct		s_ls_func
{
	int				(*av_s)(t_node *, t_node *);
	int				(*s)(t_node *, t_node *);
	void			(*av_p)(t_node *);
	void			(*p)(t_node *);
}					t_ls_func;

typedef struct	s_ls_env
{
	int			i;
	int			o;
	char		*av;
}				t_ls_env;


t_ls_env			*ls_env(void);

/*
***			***			ls_avsort.c			***
*/

int					avs_lex(void *s1, void *s2);
int					avs_rlex(void *s1, void *s2);
int					avs_modt(void *s1, void *s2);
int					avs_rmodt(void *s1, void *s2);

/*
***			***			ls_sort.c			***
*/

int					s_lex(void *s1, void *s2);
int					s_rlex(void *s1, void *s2);
int					s_modt(void *s1, void *s2);
int					s_rmodt(void *s1, void *s2);

/*
***			***			ls_avsort.c			***
*/

void				p_standard(void *p, size_t size);
void				p_cstandard(void *p, size_t size);
void				p_long(void *p, size_t size);
void				p_clong(void *p, size_t size);

/*
***			***			ls_print.c			***
*/

void				ls_print(void *p, size_t size);
void				ls_cprint(void *p, size_t size);
void				ls_long_print(void *p, size_t size);
void				ls_long_cprint(void *p, size_t size);

/*
***			***			ls_msg.c			***
*/

int					ls_err(char *av, char *id, int err, char *msg);
int					ft_put_usage(char *av, char e);


/*
***			***			verbose.c			***
*/

void				verbose_get_opt(int o, char *av);
void				verbose_print_tree(char *av, t_node *root);
void				verbose_get_avsort(int (*s)(t_node *, t_node *), char *av);
void				verbose_get_avprint(void (*p)(t_node *), char *av);

/*
***			***			name.c			***
*/

char				*ft_name(char *path);

/*
***			***			select.c			***
*/

int					(*ls_select_argvsort(int o))(void *, void *);
int					(*ls_select_sort(int o))(void *, void *);
void				(*ls_select_print(int o))(void *, size_t);

/*
***			***			ls_wopt.c			***
*/

void				ft_ls_wopt\
					(int ac, char **av, int o, int (*s)(t_node *, t_node *));

/*
***			***			get_opt.c			***
*/

int					get_opt(const char *cset, int ac, char **av, char *e);

/*
***			***			argv.c			***
*/

t_node				*argv_tree(int ac, char **av, int *o);


void			ls_dir(void *p, size_t size);

#endif
