/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:19:30 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/29 20:23:12 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_H
# define CURSOR_H

# define CAP_SPECIFYTERM "Specify a term type with `setenv TERM <yourtype>'."
# define CAP_UNDEFTERM "Terminal type '%s' is not defined."
# define CAP_NOACCESSTERM "Could not access the termcap data base."

# define M_OFF 0
# define M_HIGTHLIGHT 1

# include "libft.h"
# include <term.h>
# include <signal.h>
# include <sys/ioctl.h>

typedef struct		s_term
{
	struct termios	local;
	struct termios	global;
}					t_term;

typedef struct		s_coo
{
	int				li;
	int				co;
}					t_coo;

extern char			PC;
extern char			*BC;
extern char			*UP;

int					cur_put(int i);

int					cur_initterm(void);
int					cur_resetterm(void);
void				cur_exit(int rval, char *msg);

int					cur_init_scr(void);
int					cur_init_coo(void);
int					cur_init(void);

void				cur_resize(int sig);

int					cur_mode(int mode);

void				cur_write(char *str, int size);
void				cur_cwrite(char *str, int size, int rsize);
void				cur_static_write(char *str, int size);

int					cur_ask_lico(int *li, int *co);

int					cur_get_scrli(void);
int					cur_get_scrco(void);
int					cur_get_li(void);
int					cur_get_co(void);

int					cur_set_scrli(int scrli);
int					cur_set_scrco(int scrco);
int					cur_set_li(int li);
int					cur_set_co(int co);

int					cur_maj_li(int x);
int					cur_maj_co(int x);

void				cur_tputs(char *capability);
void				cur_tparm(char *capability, int param);

int					cur_goto(int li, int co);
int					cur_home(void);
int					cur_go_forward(int x);
int					cur_go_backward(int x);

int					cur_up_scroll(void);
int					cur_do_scroll(void);

int					cur_xup(int x);
int					cur_xdo(int x);
int					cur_xle(int x);
int					cur_xri(int x);

int					cur_fup(void);
int					cur_fdo(void);
int					cur_fle(void);
int					cur_fri(void);

int					cur_up(void);
int					cur_do(void);
int					cur_le(void);
int					cur_ri(void);

int					cur_all_clr(void);
int					cur_from_clr(void);
int					cur_line_clr(void);
int					cur_restline_clr(void);
int					cur_x_clr(int x);

#endif
