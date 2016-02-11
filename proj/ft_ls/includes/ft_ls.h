/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/22 16:21:28 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/11 18:36:36 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <dirent.h>
# include <time.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>

# include "libft.h"
# include "ft_tree.h"

# define CSET_O "alRrt"
# define SIZE_O 5

# define O_HIDE 0x1
# define O_LONG 0x2
# define O_RECU 0x4
# define O_REVE 0x8
# define O_TIME 0x10
# define O_COLOR 0x40
# define O_PRIVATE_ERROR 0x80
# define O_PRIVATE_MAX 0x100
# define O_PRIVATE_MULTI 0x200

# define T_ERROR 0x1
# define T_FILE 0x2
# define T_DIR 0x4

# define NAMESIZE_LS 510
# define MSGSIZE_LS 510
# define PATHSIZE_LS 2096
# define ATTRSIZE_LS 512
# define LINKSIZE_LS 512

# define SIXMONTH ((365 / 2) * 86400)

# define FMT_U1 "{green|gr}%s{eoc}: {gr}%s{eoc} -- {red}%c{eoc}\n"
# define FMT_U2 "{pink}%s{eoc}: {gr}%s{eoc} [{pink}-%s{eoc}] [{pink}%s{eoc}]\n"

# define MSG_MEM "Memory allocation failed"

# define SET(X, Y) (Y |= X)
# define IS(X, Y) ((Y & X) == X ? 1 : 0)

typedef struct stat	t_stat;

typedef struct		s_env
{
	char			path[PATHSIZE_LS + 1];
	char			*av;
	int				o;
	int				i;
	size_t			nlinkpad;
	size_t			sizepad;
	size_t			ownerlen;
	size_t			grplen;
}					t_env;

typedef struct		s_ls_entry
{
	int				handle;
	int				type;
	char			*msg;
	char			name[NAMESIZE_LS + 1];
	t_stat			stat;
}					t_ls_entry;

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

void				p_standard(void *p, size_t size);
void				p_cstandard(void *p, size_t size);
void				p_long(void *p, size_t size);
void				p_clong(void *p, size_t size);

/*
***			***			format_mode.c			***
*/

char				fmt_filemode(t_ls_entry *e);
char				*fmt_owner_perm(t_ls_entry *e, char *buf);
char				*fmt_group_perm(t_ls_entry *e, char *buf);
char				*fmt_other_perm(t_ls_entry *e, char *buf);
char				fmt_attr(t_ls_entry *e);

/*
***			***			format_name.c			***
*/

int					fmt_nblink(t_ls_entry *e);
char				*fmt_owner(t_ls_entry *e);
char				*fmt_group(t_ls_entry *e);
int					fmt_size(t_ls_entry *e);
char				*fmt_link(t_ls_entry *e, char *buf);

/*
***			***			format_time.c			***
*/

char				*fmt_month(t_ls_entry *e, char *buf);
char				*fmt_day(t_ls_entry *e, char *buf);
char				*fmt_yhm(t_ls_entry *e, char *buf);

/*
***			***			select.c			***
*/

int					(*g_ls_select_argvsort(int o))(void *, void *);
int					(*g_ls_select_sort(int o))(void *, void *);
void				(*g_ls_select_print(int o))(void *, size_t);

/*
***			***			argv.c			***
*/

t_ls_entry			ls_newentry(char *name, char *absname);
void				ls_dir(void *p, size_t size);
t_node				*argv_tree(int ac, char **av);
void				maj_env(t_ls_entry e);

/*
***			***			get_opt.c			***
*/

int					get_opt(const char *cset, int ac, char **av, char *e);

/*
***			***			name.c			***
*/

char				*ft_name(char *path);

/*
***			***			env.c			***
*/

int					ft_err(char *key, char *msg);
t_env				*env(void);

/*
***			***			ft_intlen.c			***
*/

size_t				ft_intlen(int n);

#endif
