/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:48:55 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 22:32:57 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_H
# define FT_LEXER_H

# include "ft_readline.h"

# define LX_FSTATE_SIZE 17
# define LX_STATE_SIZE 18

# define LX_CSET_SEARCH "<012\"`'([|&\\ ~#*!?"

typedef enum		e_lextype
{
	TY_None,
	TY_Blank,		// 	' ', '\t';													//prior	=	0	Blank
	TY_Word,		// 	!other_token && (isalnum + '_' || (maybe) isprint)			//prior	=	0	Word
	TY_And,		// 	"&&"														//prior	=	10	And
	TY_Or,			// 	"||"														//prior	=	10	Or
	TY_Chev_xtl,	//	"<<<X" Xisdigit												//prior	=	5	Chevxl
	TY_Chev_xdl,	//	"<<X" Xisdigit												//prior	=	5	Chevxl
	TY_Chev_xl,	//	"<X" Xisdigit												//prior	=	5	Chevxl
	TY_Chev_xdr,	//	"X>>" Xisdigit												//prior	=	5	Chevxr
	TY_Chev_xr,	//	"X>" Xisdigit												//prior	=	5	Chevxr
	TY_Pipe,		//	'|'															//prior	=	10	Or
	TY_Bground,	//	'&'															//prior	=	10	And
	TY_Quote,	//	''' cpt0													//prior	=	5	Quote
	TY_Quote_dl,	//	'"' cpt0													//prior	=	5	Quoted
	TY_Quote_il,	//	'`' cpt0													//prior	=	5	Quotei
	TY_Quote_l,	//	''' cpt0													//prior	=	5	Quote
	TY_Quote_dr,	//	'"' cpt!0													//prior	=	5	Quoted
	TY_Quote_ir,	//	'`' cpt!0													//prior	=	5	Quotei
	TY_Quote_r,	//	''' cpt!0													//prior	=	5	Quote
	TY_Parent_dl,	//	"(("														//prior	=	10	Parentd
	TY_Parent_l,	//	'('															//prior	=	10	Parent
	TY_Parent_dr,	//	"))"														//prior	=	10	Parentd
	TY_Parent_r,	//	')'															//prior	=	10	Parent
	TY_Hook_dl,	//	"[["														//prior	=	10	Hookd
	TY_Hook_l,		//	'['															//prior	=	10	Hook
	TY_Hook_dr,	//	"]]"														//prior	=	10	Hookd
	TY_Hook_r,		//	']'															//prior	=	10	Hook
	TY_Escape,		//	'\' NEXT NO ACTION (all cpts, space, ALL, AAAAALLLLL)		//prior	=	100	Explicit
	TY_Tild,		//	'~'															//prior	=	50	Explicit
	TY_Match,		//	'*'															//prior	=	50	Explicit
	TY_Comm,		//	'#'															//prior	=	50	Explicit
	TY_Neg,		//	'!'															//prior	=	5	Explicit
	TY_Sub		//	'?'															//prior	=	5	Explicit
}					t_lextype;

typedef enum		e_lexstate
{
	ST_Blank,
	ST_Word,
	ST_Chevxl,
	ST_Chevxr,
	ST_Quoted,
	ST_Quotei,
	ST_Quote,
	ST_Parent,
	ST_Hook,
	ST_Or,
	ST_And,
	ST_Escape,
	ST_Tild,
	ST_Comm,
	ST_Autocmp,
	ST_Neg,
	ST_Sub,
	ST_Error
}					t_lexstate;

typedef enum		e_lexcode
{
	CO_Success,
	CO_Repeat,
	CO_Fail
}					t_lexcode;

typedef struct		s_lex
{
	struct s_lex	*next;
	struct s_lex	*previous;
	t_lextype		type;
	char			*value;
	size_t			len;
	int				pound;
}					t_lex;

typedef t_lexcode	(*t_lexfstate)(char, t_lex *, t_lexstate *state);

extern t_lexstate	g_state[LX_STATE_SIZE];
extern t_lexfstate	g_fstate[LX_STATE_SIZE];

t_lex				*ft_lexer(char *id, char *line);
t_lex				*lx_lexer(char *id, char *line);
t_lexstate			lx_entry(char c);
void				lx_tokenlist(t_lex **alst, t_lex *token);
void				lx_print(t_lex *lst);
void				lx_del(t_lex **alst);

t_lexcode			lx_stblank(char c, t_lex *token, t_lexstate *state);
t_lexcode			lx_stword(char c, t_lex *token, t_lexstate *state);
t_lexcode			lx_stchevxl(char c, t_lex *token, t_lexstate *state);
t_lexcode			lx_stchevxr(char c, t_lex *token, t_lexstate *state);
t_lexcode			lx_stquoted(char c, t_lex *token, t_lexstate *state);
t_lexcode		 	lx_stquotei(char c, t_lex *token, t_lexstate *state);
t_lexcode			lx_stquote(char c, t_lex *token, t_lexstate *state);
t_lexcode			lx_stparent(char c, t_lex *token, t_lexstate *state);
t_lexcode			lx_sthook(char c, t_lex *token, t_lexstate *state);
t_lexcode			lx_stor(char c, t_lex *token, t_lexstate *state);
t_lexcode			lx_stand(char c, t_lex *token, t_lexstate *state);
t_lexcode			lx_stescape(char c, t_lex *token, t_lexstate *state);
t_lexcode			lx_sttild(char c, t_lex *token, t_lexstate *state);
t_lexcode			lx_stcomm(char c, t_lex *token, t_lexstate *state);
t_lexcode			lx_stautocomp(char c, t_lex *token, t_lexstate *state);
t_lexcode			lx_stneg(char c, t_lex *token, t_lexstate *state);
t_lexcode			lx_stsub(char c, t_lex *token, t_lexstate *state);

#endif
/*
ST_Entry,	CO_Success,		{ST_Blank, ST_Word, ST_Chevxl, ST_Chevxr, ST_Quoted, ST_Quotei, ST_Quote, ST_Parent, ST_Hook, ST_Or, ST_And, ST_Escape}
ST_Entry,	CO_Fail,		ST_And
ST_Blank,	CO_Success,		ST_Entry
ST_Blank,	CO_Repeat,		ST_Blank
ST_Blank,	CO_Fail,		ST_End
ST_Word,	CO_Success,		ST_Entry
ST_Word,	CO_Repeat,		ST_Word
ST_Word,	Co_Fail,		ST_End
ST_Chevxl,	Co_Success,		ST_Entry
ST_Chevxl,	Co_Repeat,		ST_Chevxl
ST_Chevxl,	Co_Fail,		ST_End
ST_Chevxr,	Co_Success,		ST_Entry
ST_Chevxr,	Co_Repeat,		ST_Chevxr
ST_Chevxr,	Co_Fail,		ST_End
ST_Quoted,	Co_Success,		ST_Entry
ST_Quoted,	Co_Repeat,		ST_Quoted
ST_Quoted,	Co_Fail,		ST_End
ST_Quotei,	Co_Success,		ST_Entry
ST_Quotei,	Co_Repeat,		ST_Quotei
ST_Quotei,	Co_Fail,		ST_End
ST_Quote,	Co_Success,		ST_Entry
ST_Quote,	Co_Repeat,		ST_Quote
ST_Quote,	Co_Fail,		ST_End
ST_Parent,	Co_Success,		ST_Entry
ST_Parent,	Co_Repeat,		ST_Parent
ST_parent,	Co_Fail,		ST_End
ST_Hook,	Co_Success,		ST_Entry
ST_Hook,	Co_Repeat,		ST_Hook
ST_Hook,	Co_Fail,		ST_End
ST_Or,		Co_Success,		ST_Entry
ST_Or,		Co_Repeat,		ST_Or
ST_Or,		Co_Fail,		ST_End
ST_And,		Co_Success,		ST_Entry
ST_And,		Co_Repeat,		ST_
ST_And,		Co_Fail,		ST_End
ST_Escape,	Co_Success,		ST_Entry
ST_Escape,	Co_Repeat,		ST_Escape
ST_Escape,	Co_Fail,		ST_End
*/
