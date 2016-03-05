/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:53:43 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 17:34:55 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H

# include "ft_term.h"
# include "get_next_line.h"
# include <fcntl.h>

# define RL_XMALLOC_SIZE 4096
# define RL_CLEAR_SIZE 4096
# define RL_INPUT_SIZE 6
# define RL_GKEY_SIZE 13

# define RL_LOAD_FILE "./.readline.history"
# define RL_SAVE_FILE "./.readline.history"

# define RL_GECHO 0x1
# define RL_GHISTORY 0x2
# define RL_GLOAD 0x4
# define RL_GSAVE 0x8

# define RL_LFLUSH 0x1
# define RL_LHISTORY 0x2
# define RL_LINSERT 0x4

# define RL_TAPPEND 0x1
# define RL_TERASE 0x2
# define RL_TCURSORONLY 0x4

# define ISATTR(X, Y) ((X & Y) == Y ? 1 : 0)
# define ABS(X) (X < 0 ? -X : X)

typedef struct	s_rldiff
{
	int			type;
	int			begin;
	size_t		offset;
}				t_rldiff;

typedef struct	s_rl
{
	int			gflag;
	int			lflag;
	char		*buffer;
	size_t		offset;
	size_t		real;
	size_t		used;
	size_t		prompt;
	size_t		ante_cursor;
	size_t		post_cursor;
	t_rldiff	diff;
	t_dlist		*history;
	t_dlist		*history_cursor;
}				t_rl;

typedef struct	s_key
{
	int			kcode;
	int			(*khandle)(t_rl *);
}				t_key;

extern t_key	g_key[];

int				rl_init(t_rl *rl, int gflag, const char *prompt);
int				rl_quit(t_rl *rl);

char			*ft_readline(const char *prompt, int gflag, char *term);

char			*rl_readline(t_rl *rl);

int				rl_maj(t_rl *rl, int code);
int				rl_maj_nl(t_rl *rl);
int				rl_maj_cl(t_rl *rl);
int				rl_maj_retarr(t_rl *rl);
int				rl_maj_suppr(t_rl *rl);
int				rl_maj_right(t_rl *rl);
int				rl_maj_left(t_rl *rl);
int				rl_maj_down(t_rl *rl);
int				rl_maj_up(t_rl *rl);
int				rl_maj_d(t_rl *rl);
int				rl_maj_end(t_rl *rl);
int				rl_maj_home(t_rl *rl);
int				rl_maj_insert(t_rl *rl);

int				rl_expand(t_rl *rl);

int				rl_ante_push(t_rl *rl, int code);
int				rl_post_push(t_rl *rl, int code);

int				rl_ante_pop(t_rl *rl);
int				rl_post_pop(t_rl *rl);

char			*rl_flush(t_rl *rl);
void			rl_goto(char *buff, size_t from, size_t to);
void			rl_echo_init(t_rl *rl);
void			rl_echo(t_rl *rl);


t_dlist			**rl_historytrace(void);
int				rl_history_load(t_rl *tl);
void			rl_history_save(char *line);
int				rl_getrl(t_rl *rl);

#endif
