/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/22 16:21:28 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/17 17:28:34 by sbenning         ###   ########.fr       */
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

# define NAMESIZE_LS 510
# define MSGSIZE_LS 510
# define PATHSIZE_LS 2096
# define CSET_O "alRrtvG"
# define SIZE_O 7

# define O_HIDE 0x1
# define O_LONG 0x2
# define O_RECU 0x4
# define O_REVE 0x8
# define O_TIME 0x10
# define O_VERBOSE 0x20
# define O_COLOR 0x40
# define O_PRIVATE_ERROR 0x80
# define O_PRIVATE_MAX 0x100
# define O_PRIVATE_MULTI 0x200

# define T_ERROR 0x1
# define T_FILE 0x2
# define T_DIR 0x4

# define FMT_U1 "{green|gr}%s{eoc}: {gr}%s{eoc} -- {red}%c{eoc}\n"
# define FMT_U2 "{pink}%s{eoc}: {gr}%s{eoc} [{pink}-%s{eoc}] [{pink}%s{eoc}]\n"
# define FMT_VERBOSE "{green|gr}%s{eoc}: {yellow}%s{eoc}: {gr}%s{eoc}: "

# define MSG_MEM "Memory allocation failed"

typedef struct		s_env
{
	char			path[PATHSIZE_LS + 1];
	char			*av;
	int				o;
	int				i;
}					t_env;

typedef struct		s_ls_entry
{
	int				type;
	char			name[NAMESIZE_LS + 1];
	char			*msg;
	struct stat		stat;
}					t_ls_entry;

/*
***			***			ls_avsort.c			***
*/

int					avs_lex(void *s1, void *s2);
int					avs_rlex(void *s1, void *s2);
int					avs_modt(void *s1, void *s2);
int					avs_rmodt(void *s1, void *s2);

/*
***			***			verbose.c			***
*/

void				verbose_get_opt(void);

/*
***			***			select.c			***
*/

int					(*ls_select_argvsort(int o))(void *, void *);

/*
***			***			argv.c			***
*/

t_node				*argv_tree(int ac, char **av);

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

t_env				*env(void);

#endif
