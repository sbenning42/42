/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:48:55 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/15 14:32:15 by sbenning         ###   ########.fr       */
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

# define LX_PLVNOPROTEC 0x0
# define LX_PLVESCAPE 0x1
# define LX_PLVDQUOTE 0x2
# define LX_PLVQUOTE 0x4

# define LX_WSFSTATE_SIZE 1
# define LX_WSPLV_SIZE 5
# define LX_WSPLVBIT_SIZE 3
# define LX_RESERVED_SIZE 22

# define ISBIT(X, Y) ((X & Y) == Y ? 1 : 0)

typedef enum		e_lxtype
{
	TY_Word,
	TY_Neg,
	TY_Case,
	TY_Coproc,
	TY_Do,
	TY_Done,
	TY_Elif,
	TY_Else,
	TY_Esac,
	TY_Fi,
	TY_For,
	TY_Function,
	TY_If,
	TY_In,
	TY_Select,
	TY_Then,
	TY_Until,
	TY_While,
	TY_Bracket_open,
	TY_Bracket_close,
	TY_Time,
	TY_Hook_open,
	TY_Hook_close
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

typedef t_lxstate	(*t_lxfstate)(t_lxem *, char, t_lxplv plv);

extern int			g_plvskip;
extern int			g_lxplvbit[];
extern t_lxplv		g_lxplv[];
extern t_lxfstate	g_lxwsfstate[];
extern t_lxem_low	g_lxreserved[];

void				lx_del(t_lxem **alst);
t_lxem				*lx_newtoken(t_lxtype type);
void				lx_addtoken(t_lxem **alst, t_lxem *token);
void				lx_print(t_lxem *lst);

int					lx_majplv(char c, t_lxplv *plv);
t_lxstate			lx_wsfstate_word(t_lxem *token, char c, t_lxplv plv);

t_lxem				*lx_wslexem(char *line);
t_lxem				*lx_wslexer(char *line);
int					lx_tilddev(t_lxem *list);
int					lx_reserveddev(t_lxem *list);
t_lxem				*ft_lexer(char *line);

char				*ft_getenv(char **ep, const char *key);

#endif
