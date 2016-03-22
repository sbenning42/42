/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:11:56 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/22 12:58:32 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H

# define RL_XMALLOC_OFFSET 1

# define RL_INPUTSIZE 6
# define RL_CODESIZE 13

# define RL_ECHO 0x1
# define RL_HISTORY 0x2

# define RL_BS_FLUSH 0x1

# define ISIN(X, Y) ((X & Y) == Y ? 1 : 0)

# include <fcntl.h>
# include "ft_cap.h"
# include "get_next_line.h"

typedef struct		s_dyn
{
	char			*str;
	size_t			offset;
	size_t			real;
	size_t			used;
	size_t			ante;
	size_t			post;
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
	int				code;
	t_rlfcode		function;
}					t_rlcode;

extern t_rlcode		g_rlcode[RL_CODESIZE];

int					dyn_strpush(t_dyn *dyn, char *str, size_t size);

void				rl_echo(t_rl *rl);

int					rl_code_home(t_rl *rl);
int					rl_code_nl(t_rl *rl);
int					rl_code_d(t_rl *rl);
int					rl_code_cl(t_rl *rl);
int					rl_code_retarr(t_rl *rl);
int					rl_code_insert(t_rl *rl);
int					rl_code_right(t_rl *rl);
int					rl_code_left(t_rl *rl);
int					rl_code_suppr(t_rl *rl);
int					rl_code_up(t_rl *rl);
int					rl_code_down(t_rl *rl);
int					rl_code_home(t_rl *rl);
int					rl_code_end(t_rl *rl);

int					rl_searchcode(t_rl *rl, int code);
int					rl_defcode(t_rl *rl, int code);
int					rl_maj(t_rl *rl, int code);
int					rl_read(void);
int					rl_loadhistory(void);
void				rl_destroyhistory(void);
int					rl_initterm(void);
int					rl_init(t_rl *rl, int settings, char *prompt);
int					rl_destroyterm(void);
int					rl_destroy(t_rl *rl);
char				*ft_readline(char *prompt, int settings);

#endif
