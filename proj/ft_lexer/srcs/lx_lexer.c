/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:26:31 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/04 19:22:47 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_lex			g_token[] = {{NULL, Tok_and, "&&", 2, 10}, {NULL, Tok_or, "||", 2, 10}, {NULL, None, "", 0, 0}};


static size_t	lx_deftok(char *line, t_lex **alst)
{
	t_lex		*token;

	if (!(token = (t_lex *)ft_memalloc(sizeof(t_lex))))
	{
		lx_del(alst);
		return (ft_strlen(line));
	}
	token->type = Blank;
	while (line[token->len] && (line[token->len] == ' '))
		token->len += 1;
	if (token->len)
	{
		if (!(token->value = ft_strsub(line, 0, token->len)))
		{
			lx_del(alst);
			return (ft_strlen(line));
		}
		lx_tokenlist(alst, token);
		return (token->len);
	}
	token->type = Word;
	while (line[token->len] && line[token->len] != ' ' && ft_isprint(line[token->len]))
		token->len += 1;
	if (token->len)
	{
		if (!(token->value = ft_strsub(line, 0, token->len)))
		{
			lx_del(alst);
			return (ft_strlen(line));
		}
		lx_tokenlist(alst, token);
		return (token->len);
	}
	lx_del(alst);
	return (ft_strlen(line));
}

t_lex			*lx_grammar(char *line, t_lex **alst)
{
	t_lex		*token;
	int			i;

	i = -1;
	while (++i < LX_TOKEN_SIZE)
	{
		if (ft_strlen(line) < g_token[i].len)
			continue ;
		if (!ft_strncmp(line, g_token[i].value, g_token[i].len))
		{
			if (!(token = lx_token(g_token[i])))
				return (NULL);
			lx_tokenlist(alst, token);
			return (token);
		}
	}
	if (!(token = ft_memalloc(sizeof(t_lex))))
		return (NULL);
	token->type = None;
	return (token);
}

size_t			lx_lexer(char *line, t_lex **alst)
{
	t_lex		*token;

	if (!(token = lx_grammar(line, alst)))
	{
		lx_del(alst);
		return (ft_strlen(line));
	}
	if (token->type != None)
		return (token->len);
	return (lx_deftok(line, alst));
}
