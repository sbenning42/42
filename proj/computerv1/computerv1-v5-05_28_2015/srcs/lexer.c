/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 10:53:03 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/31 15:12:33 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void		lex_init(t_tok *token)
{
	int			i;

	i = -1;
	ini_init_x(token, &i);
	ini_init_blk(token, &i);
	ini_init_other(token, &i);
}

static int		lex_token(char *str, const t_tok *token, unsigned int n, t_tok *tok)
{
	unsigned int	i;

	i = 0;
	while (n--)
	{
		if (!ft_strncmp(str, token->str, token->size))
		{
			ft_memcpy((void *)tok, (void *)token, sizeof(t_tok));
			return (NO_ERR);
		}
		token++;
	}
	return (ERR);
}

static int		lex_const(char *str, t_tok *tok)
{
	int			i;

	i = 0;
	while (str[i] && ft_strchr(CHARSET, str[i]))
		i++;
	tok->type = i ? TOK_COEF : ERROR;
	tok->str = str;
	tok->size = i;
	return (tok->type == ERROR ? ERR_LEX : NO_ERR);
}

int				lex_lexer(t_dtab *dtab, char *av)
{
	t_tok		token[NB_TOK];
	t_tok		tok;

	lex_init(token);
	ft_bzero((void *)&tok, sizeof(t_tok));
	if (!dtab_push(dtab, &tok))
		return (ERR_ML);
	while (tok.type != TOK_EOF)
	{
		ft_bzero((void *)&tok, sizeof(t_tok));
		if (lex_token(av, token, NB_TOK, &tok) == NO_ERR)
			;
		else if ((lex_const(av, &tok) == ERR_LEX))
			return (ERR_LEX);
		if (tok.type != TOK_BLK && !dtab_push(dtab, (void *)&tok))
			return (ERR_ML);
		else if (tok.type == TOK_OP && tok.val == 0.0)
			return (ERR_LEX);
		av += tok.size;
	}
	return (NO_ERR);
}
