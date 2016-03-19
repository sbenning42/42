/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:11:56 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/19 19:11:25 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H

# define RL_XMALLOC_OFFSET 1024
# define RL_INPUTSIZE 6

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
	t_dyn			dyn;
	t_dlist			*history;
}					t_rl;

typedef struct		s_rlterm
{
	struct termios	global;
	struct termios	local;
}					t_rlterm;

void				rl_echo(t_rl *rl);
int					rl_searchcode(t_rl *rl, int code);
int					rl_defcode(t_rl *rl, int code);
int					rl_maj(t_rl *rl, int code);
int					rl_read(void);
int					rl_loadhistory(void);
void				rl_destroyhistory(void);
int					rl_initterm(void);
int					rl_init(t_rl *rl, int settings, size_t promptsize);
int					rl_destroyterm(void);
int					rl_destroy(t_rl *rl);
char				*ft_readline(char *prompt, int settings);

#endif
