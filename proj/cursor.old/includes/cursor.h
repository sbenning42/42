/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:19:30 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 09:47:14 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_H
# define CURSOR_H

# define CAP_SPECIFYTERM "Specify a term type with `setenv TERM <yourtype>'."
# define CAP_UNDEFTERM "Terminal type '%s' is not defined."
# define CAP_NOACCESSTERM "Could not access the termcap data base."

# define M_OFF 0
# define M_HL_ON 1
# define M_RV_ON 2
# define M_DB_ON 2

# include "libft.h"
# include <term.h>
# include <signal.h>
# include <sys/ioctl.h>

typedef struct		s_term
{
	struct termios	local;
	struct termios	global;
}					t_term;

int					mput(int i);

void				cur_exit(int rval, char *msg);
int					cur_resetterm(void);
int					cur_initterm(void);

void				cur_resize(int sig);

int					cur_mode(int mode);

int					cur_setlico(void);
int					*li(void);
int					*co(void);

long int			cur_read(void);
void				cur_write(char *str, int size);

void				cur_setscr(int li, int co);
int					cur_scrli(void);
int					cur_scrco(void);

int					cur_li(void);
int					cur_co(void);
void				cur_lico(int *li, int *co);

int					cur_goto(int li, int co);
int					cur_home(void);
int					cur_lowhome(void);

int					cur_uroll(void);
int					cur_droll(void);

int					cur_xpli(int offset);
int					cur_xnli(int offset);

int					cur_pli(void);
int					cur_nli(void);
int					cur_bli(void);
int					cur_eli(void);

int					cur_xpco(int offset);
int					cur_xnco(int offset);

int					cur_pco(void);
int					cur_nco(void);
int					cur_bco(void);
int					cur_eco(void);

int					cur_clrall(void);
int					cur_clrli(void);
int					cur_clreli(void);
int					cur_clrx(int offset);

int					cur_init(char *term);

#endif
