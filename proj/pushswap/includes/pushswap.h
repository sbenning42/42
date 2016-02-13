/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 11:18:59 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/13 13:46:46 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <limits.h>

# include "libft.h"

# define CSET_O "dcvf"
# define SIZE_O 4

# define O_DEBUG 0x1
# define O_COLOR 0x2
# define O_VERB 0x4
# define O_FIN 0x8
# define O_PRIVATE_ERROR 0x10

# define FMT_U1 "%s: %s -- %c\n"
# define FMT_U2 "%s: %s [-%s] [%s]\n"
# define FMT_CU1 "{green|gr}%s{eoc}: {gr}%s{eoc} -- {red}%c{eoc}\n"
# define FMT_CU2 "{pink}%s{eoc}: {gr}%s{eoc} [{pink}-%s{eoc}] [{pink}%s{eoc}]\n"

# define IS(X, Y) ((Y & X) == X ? 1 : 0)

/*
***			***	ERROR.C	***
*/

int			error\
				(int rtnvalue, int o);
int			usage\
				(char *av, char c, int rtnvalue, int o);

/*
***			***	DEBUG.C	***
*/

void		debug\
				(t_dlist *l, char *name);
void		debug_split\
				(void);
void		debug_o\
				(int o);

/*
***			***	GETOPT.C	***
*/

int			get_opt\
				(const char *cset, int ac, char **av, char *err);
int			go_over_opt\
				(int ac, char **av);

/*
***			***	OPERATOR_SIMPLE.C	***
*/

void		op_sx\
				(t_dlist **astack, int *stroke);
void		op_rx\
				(t_dlist **astack, int *stroke);
void		op_rrx\
				(t_dlist **astack, int *stroke);

/*
***			***	OPERATOR_MULTIPLE.C	***
*/

void		op_ss\
				(t_dlist **astack_a, t_dlist **astack_b, int *stroke);
void		op_rs\
				(t_dlist **astack_a, t_dlist **astack_b, int *stroke);
void		op_rrs\
				(t_dlist **astack_a, t_dlist **astack_b, int *stroke);
void		op_px\
				(t_dlist **astack_pop, t_dlist **astack_push, int *stroke);

/*
***			***	RESOLVE.C	***
*/

void		ps_resolve\
				(t_dlist **astack_a, t_dlist **astack_b, size_t size, int o);

/*
***			***	PUSHSWAP.C	***
*/

int			pushswap\
				(int ac, char *av[], int o);

#endif
