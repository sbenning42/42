/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:11:56 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 13:23:17 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H

# define MACOSX

# define RL_XMALLOC_OFFSET 1

# define RL_INPUTSIZE 6
# define RL_CODESIZE 31

# define RL_ECHO 0x1
# define RL_HISTORY 0x2
# define RL_SH_STYLE 0x4
# define RL_BASH_STYLE 0x8
# define RL_OMZSH_STYLE 0x10
# define RL_42_STYLE 0x20
# define RL_42_NODATE 0x40
# define RL_42_NOPWD 0x80
# define RL_42_NOSTAT 0x100
# define RL_COLOR 0x200

# define RL_BS_FLUSH 0x1
# define RL_BS_QFLUSH 0x2
# define RL_BS_INSERT 0x4
# define RL_BS_SELECT 0x8
# define RL_BS_SKIPNEXT 0x10

# define RL_SH_STYLE_CPROMPT_FORMAT "{green}%s{eoc}{grey|gr}$>{eoc} "
# define RL_SH_STYLE_PROMPT_FORMAT "%s$> "

# ifdef MACOSX
#  define RL_CODE_CTRL_A 0x1
#  define RL_CODE_CTRL_C 0x3
#  define RL_CODE_CTRL_D 0x4
#  define RL_CODE_CTRL_L 0xc
#  define RL_CODE_RETARR 0x7f
#  define RL_CODE_SUPPR 0x7e335b1b
#  define RL_CODE_INSERT 0x53323b315b1b
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
#  define RL_CODE_WRIGHT 0x43323b315b1b
#  define RL_CODE_WLEFT 0x44323b315b1b
#  define RL_CODE_COPY 0xa7c3
#  define RL_CODE_CUT 0x8889e2
#  define RL_CODE_PASTE 0x9a88e2
#  define RL_CODE_DELETE 0x8288e2
#  define RL_CODE_SELECT_RIGHT 0x435b1b1b
#  define RL_CODE_SELECT_LEFT 0x445b1b1b
#  define RL_CODE_SELECT_PAGEUP 0x7e355b1b1b
#  define RL_CODE_SELECT_PAGEDOWN 0x7e365b1b1b
#  define RL_CODE_SELECT_HOME 0x48393b315b1b
#  define RL_CODE_SELECT_END 0x46393b315b1b
#  define RL_CODE_SELECT_WRIGHT 0x4330313b315b1b
#  define RL_CODE_SELECT_WLEFT 0x4430313b315b1b
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
# include <time.h>
# include "cursor.h"
#include "ft_history.h"

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
	t_hist			hist_cp;
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

int					*gg_status(void);
	
void				rl_dumpdyn(t_dyn d);

int					dyn_strpushante(t_dyn *dyn, char *str, size_t size);
int					dyn_strpushpost(t_dyn *dyn, char *str, size_t size);
int					dyn_strpopante(t_dyn *dyn, char *str, size_t size);
int					dyn_strpoppost(t_dyn *dyn, char *str, size_t size);

void				rl_post_display(t_rl *rl);
void				rl_ante_display(t_rl *rl);
void				rl_reset_post_display(t_rl *rl);
void				rl_reset_ante_display(t_rl *rl);
void				rl_reset_display(t_rl *rl);

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

void 				rl_sh_prompt(t_rl *rl, char *base, int settings);
void 				rl_bash_prompt(t_rl *rl, char *base, int settings);
void 				rl_omzsh_prompt(t_rl *rl, char *base, int settings);

void 				rl_42_prompt(\
						t_rl *rl,\
						char *base,\
						int settings,\
						size_t len);
void				rl_42_prompt_date_constr(\
						char *prompt,\
						char *date,\
						int settings);
void				rl_42_prompt_pwd_constr(\
						char *prompt,\
						char *pwd,\
						int settings);
void				rl_42_prompt_col_constr(\
						char *prompt,\
						char *status,\
						int settings);
void				rl_42_prompt_base_constr(\
						char *prompt,\
						char *base,\
						int settings,\
						size_t *len);

int					rl_init(t_rl *rl, t_hist *hist, int settings, char *prompt);
int					rl_destroy(t_rl *rl);

char				*ft_readline(char *prompt, t_hist *hist, int settings);

#endif
