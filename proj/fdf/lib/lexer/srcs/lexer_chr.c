/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 10:42:20 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/30 10:57:18 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void		lexer_constchr(char *s, t_lex_tk *token)
{
	size_t	i;

	if (!ft_isalnum(*s))
		return ;
	i = 0;
	if (ft_isdigit(*s))
	{
		token->type = Const_nu;
		while (s[i] && ft_strchr(LEX_TOKEN_NU, s[i]))
			i++;
		token->size = i;
		token->save = True;
		token->esc = False;
		token->rec = False;
		return ;
	}
	token->type = Const_alpha;
	while (ft_isalnum(s[i]))
		i++;
	token->size = i;
	token->save = True;
	token->esc = False;
	token->rec = False;
	return ;
}

void		lexer_tokenchr(char *s, t_lex_tk *pattern, size_t size, \
			t_lex_tk *token)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (!ft_strncmp(s, pattern[i].value, pattern[i].size))
		{
			*token = pattern[i];
			token->value = s;
			return ;
		}
		i++;
	}
}
