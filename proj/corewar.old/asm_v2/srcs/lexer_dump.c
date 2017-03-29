/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_dump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 08:46:49 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/24 10:03:24 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*g_token_type = {\
	"",\
	"",\
	"",\
	"",\
	"",\
	"",\
	"",\
	"",\
	"",\
	"",\
	"",\
	"",\
	"",\
	"",\
	"",\
	"",\
	"",\
	"",\
};

static void	token_dump(t_token token)
{
	ft_printf(ASM_TOKEN_DUMP_FMT,\
			token.id,\
			token.line,\
			token.column,\
			g_token_type[token.type],\
			token.value,\
			token.size);
}

void		lexer_dump(t_lexem lexer)
{
	t_list	*tmp;
	t_token	*tmp_token;

	tmp = lexer.lst;
	while (tmp)
	{
		tmp_token = (t_token *)tmp->content;
		token_dump(*tmp_token);
		tmp = tmp->next;
	}
}
