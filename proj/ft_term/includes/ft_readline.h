/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:53:43 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/02 14:57:01 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H

# include "ft_term.h"
# include "libft.h"

# define RL_XMALLOC_SIZE 4096
# define RL_CLEAR_SIZE 4096
# define RL_INPUT_SIZE 6
# define RL_GKEY_SIZE 2

# define RL_CL_INIT {[0 ... RL_CLEAR_SIZE - 1] = ' '}

# define RL_GECHO 0x1
# define RL_GHISTORY 0x2

# define RL_LFLUSH 0x1
# define RL_LBMODIF 0x2

# define ISATTR(X, Y) ((X & Y) == Y ? 1 : 0)

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
}				t_rl;

typedef struct	s_key
{
	int			kcode;
	int			(*khandle)(t_rl *);
}				t_key;

extern t_key	g_key[];

int				rl_init(t_rl *rl, int gflag, const char *prompt, char *term);
int				rl_quit(t_rl *rl);

char			*ft_readline(const char *prompt, int gflag, char *term);

char			*rl_readline(t_rl *rl);

int				rl_maj(t_rl *rl, int code);
int				rl_maj_nl(t_rl *rl);
int				rl_maj_retarr(t_rl *rl);

int				rl_expand(t_rl *rl);

int				rl_ante_push(t_rl *rl, int code);
int				rl_post_push(t_rl *rl, int code);

int				rl_ante_pop(t_rl *rl);
int				rl_post_pop(t_rl *rl);

char			*rl_flush(t_rl *rl);
void			rl_echo_init(t_rl *rl);
void			rl_echo(t_rl *rl);

#endif
