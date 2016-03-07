/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:48:55 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/07 13:25:07 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_H
# define FT_LEXER_H

# include "libft.h"

# define LX_WORDSPLIT_NOPROTEC_CSET "|&;()<>!$` \t"
# define LX_WORDSPLIT_ESCAPE_CSET ""
# define LX_WORDSPLIT_QUOTE_CSET ""
# define LX_WORDSPLIT_DQUOTE_CSET "!$`*"

# define LX_PROTEC_NOPRPTEC_CSET "\\\"'"
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

# define ISBIT(X, Y) ((X & Y) == Y ? 1 : 0)

typedef enum		e_lxproteclv
{
	PLV_Noprotec,
	PLV_Escape,
	PLV_Quote,
	PLV_Dquote
}					t_lxproteclv;

typedef enum		e_lxtype
{
	TY_Word
}					t_lxtype;

typedef enum		e_lxstate
{
	ST_Word,
	ST_Success,
	ST_Skip,
	ST_Mfail,
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
	int				plv;
	t_lxtype		type;
	t_dynstr		value;
	size_t			len;
}					t_lxem;

extern t_lxstate	(*g_wsfstate[LX_WSFSTATE_SIZE])(char, t_lxplv plv, t_lxem **token);
extern t_lxplv		g_wsplv[LX_WSPLV_SIZE];
extern int			g_wsplvbit[LX_WSPLVBIT_SIZE];
extern int			g_skip;

void				lx_del(t_lxem **alst);
t_lxem				*lx_newtoken(t_lxtype type, int plv);
void				lx_addtoken(t_lxem **alst, t_lxem *token);
void				lx_print(t_lxem *lst);

t_lxstate			lx_wsstword(char c, t_lxplv plv, t_lxem **token);

size_t				lx_plvmaj(char c, t_lxplv *plv);
t_lxem				*lx_wordsplit_dev(char *line);
t_lxem				*ft_lexer(char *line);

#endif
