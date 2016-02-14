/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 00:12:54 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/20 02:16:56 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_lexer.h"

#define TK_FATALERROR_TYPE 0
#define TK_ERROR_TYPE 1
#define TK_EOL_TYPE 2
#define TK_BLANK_TYPE 3
#define TK_NEWLINE_TYPE 4
#define TK_CONSTALPHA_TYPE 5
#define TK_CONSTNU_TYPE 6
#define TK_STARTBRA_TYPE 7
#define TK_ENDBRA_TYPE 8
#define TK_QUOTE_TYPE 9
#define TK_OPNU_TYPE 10
#define TK_LOGICALCO_TYPE 11
#define TK_PHYSICALCO_TYPE 12
#define TK_SHELLCHAR_TYPE 13

#define TK_FATALERROR_CSET ''
#define TK_ERROR_CSET ''
#define TK_EOL_CSET '\0'
#define TK_BLANK_CSET ' ', '\b', '\v', '\t', '\r'
#define TK_NEWLINE_CSET '\n'
#define TK_CONSTALPHA_CSET ''
#define TK_CONSTNU_CSET ''
#define TK_STARTBRA_CSET '(', '[', '{'
#define TK_ENDBRA_CSET ')', ']', '}'
#define TK_QUOTE_CSET '\'', '\"', '`'
#define TK_OPNU_CSET '+', '-', '*', '/', '%'
#define TK_LOGICALCO_CSET "||", "&&", '&', '='
#define TK_PHYSICALCO_CSET '|', '<', '>', ';'
#define TK_SHELLCHAR_CSET "..", '.', ':', '$', '!'

typedef struct		s_sh_tk
{
	int				type;
	char			*value;
	size_t			size;
}					t_sh_tk;

static t_list	*lx_error(t_list **alst, t_sh_tk tk)
{
	ft_fprintf(2, "%s: {red}%s{eoc}: %s\n");
}

t_list		*sh_lexer(char *line)
{
	t_list	*lst;
	t_list	*lexem;
	t_sh_tk	tk;

	lst = NULL;
	while (42)
	{
		ft_bzero((void *)&tk, sizeof(t_sh_tk));
		tk = lx_gettoken(&line);
		if (tk.type == TK_FATALERRORTYPE)
			return (lx_error(&lst, tk));
		lexem = ft_lstnew((void *)&tk, sizeof(t_sh_tk));
		if (!lexem)
			return (lx_error(&lst, tk));
		ft_lstadd_back(&lst, lexem);
		if (tk.type == TK_EOLTYPE)
			break ;
	}
	return (lst);
}
