/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 10:53:03 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/27 14:19:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.h"

static void		lex_init_l(t_tok *tab)
{
	int			i;

	i = 0;
	tab[i].type = TOK_X;
	tab[i].str = "X^";
	tab[i].size = 2;
	tab[++i].type = TOK_X;
	tab[i].str = "x^";
	tab[i].size = 2;
	tab[++i].type = TOK_X;
	tab[i].str = "X";
	tab[i].size = 1;
	tab[++i].type = TOK_X;
	tab[i].str = "x";
	tab[i].size = 1;
}

static void		lex_init(t_tok *tab)
{
	int			i;

	lex_init_l(tab);
	i = 4;
	tab[i].type = TOK_BLK;
	tab[i].str = " ";
	tab[i].size = 1;
	tab[++i].type = TOK_BLK;
	tab[i].str = "\t";
	tab[i].size = 1;
	tab[++i].type = TOK_EOF;
	tab[i].str = "\0";
	tab[i].size = 1;
	tab[++i].type = TOK_EQ;
	tab[i].str = "=";
	tab[i].size = 1;
	tab[++i].type = TOK_OP;
	tab[i].str = "*";
	tab[i].size = 1;
	tab[++i].type = TOK_SIG;
	tab[i].str = "+";
	tab[i].size = 1;
	tab[++i].type = TOK_SIG;
	tab[i].str = "-";
	tab[i].size = 1;
}

static int		lex_known(char *str, const t_tok *tab, t_tok *tok)
{
	int			i;
	int			ret;

	i = 0;
	while (i < NB_TOK)
	{
		ret = ft_strncmp(str, tab[i].str, tab[i].size);
		if (!ret)
		{
			ft_memcpy((void *)tok, (void *)&tab[i], sizeof(t_tok));
			if (tab[i].type == TOK_SIG && !ft_strncmp(str, "-", 1))
				tok->val = 1.0;
			return (!ret);
		}
		i++;
	}
	return (0);
}

static int		lex_not_known(char *str, t_tok *tok)
{
	int			i;
	char		val[64];

	i = 0;
	while (str[i] && ft_strchr(CHARSET, str[i]))
		i++;
	tok->str = str;
	tok->size = i;
	ft_strncpy(val, str, i);
	val[i] = '\0';
	tok->val = ft_atof(val);
	return (i ? NO_ERR : ERR_LEX);
}

int				lex_lexer(t_dtab *dtab, char *av)
{
	t_tok		tab[NB_TOK];
	t_tok		tok;
	int			flag;

	flag = 0;
	lex_init(tab);
	while (*av != '\0')
	{
		ft_bzero((void *)&tok, sizeof(t_tok));
		if (!lex_known(av, tab, &tok))
		{
			if (!lex_not_known(av, &tok))
				return (ERR_LEX);
			tok.type = flag ? TOK_EXP : TOK_COEF;
		}
		flag = (tok.type == TOK_X) ? 1 : 0;
		if (tok.type != TOK_BLK && tok.type != TOK_OP)
		{
			if (!(dtab_push(dtab, (void *)&tok)))
				return (ERR_ML);
		}
		av += tok.size;
	}
	return (NO_ERR);
}
