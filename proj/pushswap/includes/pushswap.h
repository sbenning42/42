/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 11:18:59 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/19 11:06:58 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <limits.h>

# include "libft.h"

# define CSET_O "dcvfn"
# define SIZE_O 5

# define O_DEBUG 0x1
# define O_COLOR 0x2
# define O_VERB 0x4
# define O_FIN 0x8
# define O_STROKE 0x10
# define O_PRIVATE_ERROR 0x20

# define FMT_U1 "%s: %s -- %c\n"
# define FMT_U2 "%s: %s [-%s] [%s]\n"
# define FMT_CU1 "{green|gr}%s{eoc}: {gr}%s{eoc} -- {red}%c{eoc}\n"
# define FMT_CU2 "{pink}%s{eoc}: {gr}%s{eoc} [{pink}-%s{eoc}] [{pink}%s{eoc}]\n"

# define CHECKSORT 100

# define IS(X, Y) ((Y & X) == X ? 1 : 0)

typedef struct	s_stackenv
{
	int			min;
	int			max;
	int			piv;
}				t_stackenv;

/*
***				***	ERROR.C	***
*/

int				error\
					(int rtnvalue, int o);
int				usage\
					(char *av, char c, int rtnvalue, int o);

/*
***				***	DEBUG.C	***
*/

void			debug\
					(t_dlist *l, char *name, int o);
void			debug_split\
					(void);
void			debug_o\
					(int o);

/*
***				***	GETOPT.C	***
*/

int				get_opt\
					(const char *cset, int ac, char **av, char *err);
int				go_over_opt\
					(int ac, char **av);

/*
***				***	OPERATOR_SIMPLE.C	***
*/

void			op_sx\
					(t_dlist **astack, int *stroke);
void			op_rx\
					(t_dlist **astack, int *stroke);
void			op_rrx\
					(t_dlist **astack, int *stroke);

/*
***				***	OPERATOR_MULTIPLE.C	***
*/

void			op_ss\
					(t_dlist **astack_a, t_dlist **astack_b, int *stroke);
void			op_rs\
					(t_dlist **astack_a, t_dlist **astack_b, int *stroke);
void			op_rrs\
					(t_dlist **astack_a, t_dlist **astack_b, int *stroke);
void			op_px\
					(t_dlist **astack_pop, t_dlist **astack_push, int *stroke);

int				reverse\
					(t_dlist **astack, int o);
int				reverse_swap\
					(t_dlist **astack, int o);
/*
***				***	NOSORT.C	***
*/

int				nosort\
					(t_dlist *stack, int o, int finish);

/*
***				***	SORT.C	***
*/

void			sort\
					(t_dlist **astack_a, t_dlist **astack_b,\
					size_t size, int o);

/*
***				***	ROLL.C	***
*/

int				reverse_roll\
					(t_dlist **astack, int min, int o);
int				roll\
					(t_dlist **astack, int min, int o);

/*
***				***	PUSHSWAP.C	***
*/

int				pushswap\
					(int ac, char *av[], int o);

/*
***				***	MAIN.C	***
*/

t_stackenv		*stackenv\
					(void);

#endif
