/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 11:18:59 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/12 16:48:59 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <limits.h>

# include "libft.h"

# define CSET_O "cd"
# define SIZE_O 2

# define O_COLOR 0x1
# define O_DEBUG 0x2
# define O_PRIVATE_ERROR 0x4

# define FMT_U1 "%s: %s -- %c\n"
# define FMT_U2 "%s: %s [_%s] [%s]\n"
# define FMT_CU1 "{green|gr}%s{eoc}: {gr}%s{eoc} -- {red}%c{eoc}\n"
# define FMT_CU2 "{pink}%s{eoc}: {gr}%s{eoc} [{pink}_%s{eoc}] [{pink}%s{eoc}]\n"

# define IS(X, Y) ((Y & X) == X ? 1 : 0)

/*
***			***	ERROR.C	***
*/

int			ps_error(int rtnvalue);
int			ps_usage(char *av, char c, int rtnvalue);

/*
***			***	OPTION.C	***
*/

int			*opt(void);

/*
***			***	DEBUG.C	***
*/

void		debug_dl(t_dlist *l, size_t size, char *name);

/*
***			***	GETOPT.C	***
*/

int			get_opt(const char *cset, int ac, char **av, char *err);
int			go_over_opt(int ac, char **av);

/*
***			***	OPERATOR_SIMPLE.C	***
*/

void		op_sx(t_dlist **ah_dl);
void		op_rx(t_dlist **ah_dl);
void		op_rrx(t_dlist **ah_dl);

/*
***			***	OPERATOR_MULTIPLE.C	***
*/

void		op_ss(t_dlist **ah_dla, t_dlist **ah_dlb);
void		op_rs(t_dlist **ah_dla, t_dlist **ah_dlb);
void		op_rrs(t_dlist **ah_dla, t_dlist **ah_dlb);
void		op_px(t_dlist **ah_dl_pop, t_dlist **ah_dl_push);

/*
***			***	RESOLVE.C	***
*/

void		ps_resolve(t_dlist **ah_dla, t_dlist **ah_dlb, size_t size);

/*
***			***	PUSHSWAP.C	***
*/

int			pushswap(int ac, char *av[]);

#endif
