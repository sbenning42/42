/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/22 16:21:28 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/09 16:17:01 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <errno.h>
# include "libft.h"

# define O_CSET "alRrtv"
# define O_SIZE 6

# define NAME(X, Y) ((Y = ft_strrchr(X, '/')) ? Y + 1 : X)

# define U1FMT "{green}%s{eoc}: {gr}%s{eoc} -- {red}%c{eoc}\n"
# define U2FMT "{pink}%s{eoc}: {gr}%s{eoc} [{pink}-%s{eoc}] [{pink}%s{eoc}]\n"
# define MASFMT "{green}%s{eoc}: {yellow}%s{eoc}: {gr}%s{eoc}: {cyan}%s{eoc}"
# define OFMT "{green}%s{eoc}: {yellow}%s{eoc}: {gr}%s{eoc}: "
# define UMSG "file ..."
# define VERBOSEID "verbose"
# define MAS "All work's fine :) !!\n"
# define ARGMAS NAME(av[0], id), VERBOSEID, "Master", MAS

# define PRIV_ERROR_O 0x1
# define HIDE_O 0x2
# define LONG_O 0x4
# define RECU_O 0x8
# define REVE_O 0x10
# define TIME_O 0x20
# define VERBOSE_O 0x40
# define MAX_O 0x80

/*
void	ft_ls_del_avl(void *content, size_t size);
void	ft_ls_straigt_sort(t_list *lst);
void	ft_ls_time_sort(t_list *lst, int *opt);
void	ft_ls_reverse_sort(t_list *lst);
t_list	*ft_ls_sort_av(int *opt, int ac, char **av);
void	ft_ls_put_error_entry(char *name, int err);
*/

int		s_lex(void *s1, void *s2);
int		s_rlex(void *s1, void *s2);
int		s_time(void *t1, void *t2);
int		s_rtime(void *t1, void *t2);

void	ft_ls_wopt(int ac, char **av, int o, int (*s)(void *, void *));
int		get_opt(const char *cset, int ac, char **av, char *e);

#endif
