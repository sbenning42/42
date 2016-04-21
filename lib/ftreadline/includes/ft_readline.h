/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:11:56 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/21 11:34:51 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H

# define LINUX

# define RL_XMALLOC_OFFSET 1

# define RL_INPUTSIZE 6
# define RL_CODESIZE 31

# define RL_ECHO 0x1
# define RL_HISTORY 0x2

# define RL_BS_FLUSH 0x1
# define RL_BS_QFLUSH 0x2
# define RL_BS_INSERT 0x4
# define RL_BS_SELECT 0x8
# define RL_BS_SKIPNEXT 0x10

# ifdef MACOSX
#  define RL_CODE_CTRL_A
#  define RL_CODE_CTRL_C
#  define RL_CODE_CTRL_D
#  define RL_CODE_CTRL_L
#  define RL_CODE_RETARR
#  define RL_CODE_SUPPR
#  define RL_CODE_INSERT
#  define RL_CODE_ESC
#  define RL_CODE_NL
#  define RL_CODE_RIGHT
#  define RL_CODE_LEFT
#  define RL_CODE_UP
#  define RL_CODE_DOWN
#  define RL_CODE_PAGEUP
#  define RL_CODE_PAGEDOWN
#  define RL_CODE_HOME
#  define RL_CODE_END
#  define RL_CODE_WRIGHT
#  define RL_CODE_WLEFT
#  define RL_CODE_COPY
#  define RL_CODE_CUT
#  define RL_CODE_PASTE
#  define RL_CODE_DELETE
#  define RL_CODE_SELECT_RIGHT
#  define RL_CODE_SELECT_LEFT
#  define RL_CODE_SELECT_PAGEUP
#  define RL_CODE_SELECT_PAGEDOWN
#  define RL_CODE_SELECT_HOME
#  define RL_CODE_SELECT_END
#  define RL_CODE_SELECT_WRIGHT
#  define RL_CODE_SELECT_WLEFT
# endif

# ifdef LINUX
#  define RL_CODE_CTRL_A 0x1
#  define RL_CODE_CTRL_C 0x3
#  define RL_CODE_CTRL_D 0x4
#  define RL_CODE_CTRL_L 0xc
#  define RL_CODE_RETARR 0x7f
#  define RL_CODE_SUPPR 0x7e335b1b
#  define RL_CODE_INSERT 0x7e325b1b
#  define RL_CODE_ESC 0x1b
#  define RL_CODE_NL 0xa
#  define RL_CODE_RIGHT 0x435b1b
#  define RL_CODE_LEFT 0x445b1b
#  define RL_CODE_UP 0x415b1b
#  define RL_CODE_DOWN 0x425b1b
#  define RL_CODE_PAGEUP 0x7e355b1b
#  define RL_CODE_PAGEDOWN 0x7e365b1b
#  define RL_CODE_HOME 0x485b1b
#  define RL_CODE_END 0x465b1b
#  define RL_CODE_WRIGHT 0x43353b315b1b
#  define RL_CODE_WLEFT 0x44353b315b1b
#  define RL_CODE_COPY 0x631b
#  define RL_CODE_CUT 0x781b
#  define RL_CODE_PASTE 0x761b
#  define RL_CODE_DELETE 0x641b
#  define RL_CODE_SELECT_RIGHT 0x43333b315b1b
#  define RL_CODE_SELECT_LEFT 0x44333b315b1b
#  define RL_CODE_SELECT_PAGEUP 0x7e333b355b1b
#  define RL_CODE_SELECT_PAGEDOWN 0x7e333b365b1b
#  define RL_CODE_SELECT_HOME 0x48333b315b1b
#  define RL_CODE_SELECT_END 0x46333b315b1b
#  define RL_CODE_SELECT_WRIGHT 0x43343b315b1b
#  define RL_CODE_SELECT_WLEFT 0x44343b315b1b
# endif

# define ISIN(X, Y) ((X & Y) == Y ? 1 : 0)

# include <fcntl.h>
# include "cursor.h"

typedef struct		s_dyn
{
	char			*str;
	char			*strend;
	char			*slct;
	size_t			offset;
	size_t			real;
	size_t			used;
	size_t			ante;
	size_t			post;
	size_t			slct_ante;
	size_t			slct_post;
}					t_dyn;

typedef struct		s_rl
{
	int				settings;
	int				bitset;
	size_t			promptsize;
	char			*prompt;
	t_dyn			dyn;
	t_dlist			*history;
}					t_rl;

typedef struct		s_rlterm
{
	struct termios	global;
	struct termios	local;
}					t_rlterm;

typedef int			(*t_rlfcode)(t_rl *rl);

typedef struct		s_rlcode
{
	long int		code;
	t_rlfcode		function;
}					t_rlcode;

extern t_rlcode		g_rlcode[RL_CODESIZE];

int					dyn_strpushante(t_dyn *dyn, char *str, size_t size);
int					dyn_strpushpost(t_dyn *dyn, char *str, size_t size);
int					dyn_strpopante(t_dyn *dyn, char *str, size_t size);
int					dyn_strpoppost(t_dyn *dyn, char *str, size_t size);

int					rl_code_esc(t_rl *rl);
int					rl_code_home(t_rl *rl);
int					rl_code_nl(t_rl *rl);
int					rl_code_c(t_rl *rl);
int					rl_code_d(t_rl *rl);
int					rl_code_cl(t_rl *rl);
int					rl_code_retarr(t_rl *rl);
int					rl_code_insert(t_rl *rl);
int					rl_code_right(t_rl *rl);
int					rl_code_left(t_rl *rl);
int					rl_code_suppr(t_rl *rl);
int					rl_code_up(t_rl *rl);
int					rl_code_down(t_rl *rl);
int					rl_code_pageup(t_rl *rl);
int					rl_code_pagedown(t_rl *rl);
int					rl_code_home(t_rl *rl);
int					rl_code_end(t_rl *rl);
int					rl_code_wright(t_rl *rl);
int					rl_code_wleft(t_rl *rl);
int					rl_code_cpy(t_rl *rl);
int					rl_code_cut(t_rl *rl);
int					rl_code_cle(t_rl *rl);
int					rl_code_del(t_rl *rl);
int					rl_code_slct_right(t_rl *rl);
int					rl_code_slct_left(t_rl *rl);
int					rl_code_slct_pageup(t_rl *rl);
int					rl_code_slct_pagedown(t_rl *rl);
int					rl_code_slct_home(t_rl *rl);
int					rl_code_slct_end(t_rl *rl);
int					rl_code_slct_wright(t_rl *rl);
int					rl_code_slct_wleft(t_rl *rl);

int					rl_searchcode(t_rl *rl, long int code);
int					rl_defcode(t_rl *rl, long int code);
int					rl_maj(t_rl *rl, long int code);
long int			rl_read(void);
int					rl_loadhistory(void);
void				rl_destroyhistory(void);
int					rl_init(t_rl *rl, int settings, char *prompt);
int					rl_destroy(t_rl *rl);
char				*ft_readline(char *prompt, int settings);

#endif
