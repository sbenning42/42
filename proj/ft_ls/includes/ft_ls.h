/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/22 16:21:28 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/14 17:28:45 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <errno.h>
# include "libft.h"

# define CSET_O "alRrtv"
# define SIZE_O 6
# define O_PRIVATE_ERROR 0x1
# define O_MAX 0x80

# define O_HIDE 0x2
# define O_LONG 0x4
# define O_RECU 0x8
# define O_REVE 0x10
# define O_TIME 0x20
# define O_VERBOSE 0x40

# define FMT_U1 "{green}%s{eoc}: {gr}%s{eoc} -- {red}%c{eoc}\n"
# define FMT_U2 "{pink}%s{eoc}: {gr}%s{eoc} [{pink}-%s{eoc}] [{pink}%s{eoc}]\n"
# define FMT_VERBOSE "{green}%s{eoc}: {yellow}%s{eoc}: {gr}%s{eoc}: "
# define FMT_S "{green}%s{eoc}: {yellow}%s{eoc}: {gr}%s{eoc}: "

/*
***			***			sort.c			***
*/

int					s_lex(void *s1, void *s2);
int					s_rlex(void *s1, void *s2);
int					s_time(void *t1, void *t2);
int					s_rtime(void *t1, void *t2);

/*
***			***			verbose.c			***
*/

void				verbose_get_opt(int o, char *av);
void				verbose_get_sort(int (*s)(void *, void *), char *av);

/*
***			***			name.c			***
*/

char				*ft_name(char *path);

/*
***			***			ls_wopt.c			***
*/

void				ft_ls_wopt\
					(int ac, char **av, int o, int (*s)(void *, void *));

/*
***			***			get_opt.c			***
*/

int					get_opt(const char *cset, int ac, char **av, char *e);

#endif
