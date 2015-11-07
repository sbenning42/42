/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 10:53:03 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/01 10:48:16 by sbenning         ###   ########.fr       */
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

static void		lex_const(char *str, t_tok *tok)
{
	int			i;
	int			occ;

	i = 0;
	occ = 0;
	while (str[i] && ft_strchr(CHARSET, str[i]))
	{
		if (str[i] == '.')
			occ++;
		if (occ > 1 || (!i && occ))
			break ;
		i++;
	}
	tok->type = (i && occ < 2) ? TOK_COEF : ERROR;
	tok->str = str;
	tok->size = i ? i : 1;
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
		if (lex_token(av, token, NB_TOK, &tok) == ERR)
			lex_const(av, &tok);
		if (tok.type != TOK_BLK && !dtab_push(dtab, (void *)&tok))
			return (ERR_ML);
		else if (tok.type == ERROR)
			return (ERR_LEX);
		av += tok.size;
	}
	return (NO_ERR);
}
