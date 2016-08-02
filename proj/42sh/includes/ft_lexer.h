/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:48:55 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/28 08:18:42 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_H
# define FT_LEXER_H

# include "libft.h"

# define LX_WORDSPLIT_NOPROTEC_CSET "|&;()<>!$` \t"
# define LX_WORDSPLIT_ESCAPE_CSET ""
# define LX_WORDSPLIT_QUOTE_CSET ""
# define LX_WORDSPLIT_DQUOTE_CSET "!$`*"

# define LX_PROTEC_NOPROTEC_CSET "\\\"'"
# define LX_PROTEC_ESCAPE_CSET ""
# define LX_PROTEC_QUOTE_CSET "\033\033'"
# define LX_PROTEC_DQUOTE_CSET "\\\""

# define LX_GROUP_BG "&"
# define LX_GROUP_PIPE "|"
# define LX_GROUP_TO ">"
# define LX_GROUP_FROM "<"
# define LX_GROUP_SEP ";"

# define LX_PLVNOPROTEC 0x0
# define LX_PLVESCAPE 0x1
# define LX_PLVDQUOTE 0x2
# define LX_PLVQUOTE 0x4

# define LX_WSFSTATE_SIZE 1
# define LX_WSPLV_SIZE 5
# define LX_WSPLVBIT_SIZE 3
# define LX_RESERVED_SIZE 22
# define LX_GROUP_SIZE 5

# define ISBIT(X, Y) ((X & Y) == Y ? 1 : 0)

typedef enum		e_lxtype
{
	TY_Word,
	TY_Strict_sep,
	TY_And_sep,
	TY_Or_sep,
	TY_Pipe,
	TY_Bg,
	TY_Stdin_redir,
	TY_Stdout_redir,
	TY_Stdin_append_redir,
	TY_Stdout_append_redir,
	TY_Stderr_redir,
	TY_Stderr_append_redir
}					t_lxtype;

typedef enum		e_lxstate
{
	ST_Word,
	ST_Success,
	ST_Synfail,
	ST_Fail
}					t_lxstate;

typedef struct		s_lxplv
{
	int				bitset;
	char			*ws_cset;
	char			*protec_cset;
}					t_lxplv;

typedef struct		s_lxem
{
	struct s_lxem	*previous;
	struct s_lxem	*next;
	t_lxtype		type;
	t_dynstr		value;
	size_t			len;
	int				plv;
}					t_lxem;

typedef struct		s_lxem_low
{
	t_lxtype		type;
	char			*str;
}					t_lxem_low;

typedef struct		s_lxgrp
{
	t_lxem_low		lxem;
	int				(*f)(t_lxem *);
}					t_lxgrp;

typedef t_lxstate	(*t_lxfstate)(t_lxem *, char, t_lxplv plv);

extern int			g_plvskip;
extern int			g_lxplvbit[];
extern t_lxplv		g_lxplv[];
extern t_lxfstate	g_lxwsfstate[];
extern t_lxem_low	g_lxreserved[];
extern t_lxgrp		g_lxgrp[];

void				lx_del(t_lxem **alst);
t_lxem				*lx_newtoken(t_lxtype type);
void				lx_addtoken(t_lxem **alst, t_lxem *token);
void				lx_print(t_lxem *lst);
char				*lx_typetostr(t_lxtype type, int plv);

int					lx_majplv(char c, t_lxplv *plv);
t_lxstate			lx_wsfstate_word(t_lxem *token, char c, t_lxplv plv);

t_lxem				*lx_wslexem(char *line);
t_lxem				*lx_wslexer(char *line);
int					lx_tilddev(t_lxem *list);

int					lx_grpdev(t_lxem *list);

int					lx_grp_bg(t_lxem *list);
int					lx_grp_pipe(t_lxem *list);
int					lx_grp_to(t_lxem *list);
int					lx_grp_from(t_lxem *list);
int					lx_grp_sep(t_lxem *list);

t_lxem				*ft_lexer(char *line);

#endif
