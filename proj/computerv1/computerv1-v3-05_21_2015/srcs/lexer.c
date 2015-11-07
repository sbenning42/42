#include "computerv1.h"

void			par_init(t_tok *tab)
{
	tab[0].type = TOK_X;
	tab[0].str = "X^";
	tab[0].size = 2;
	tab[1].type = TOK_BLK;
	tab[1].str = " ";
	tab[1].size = 1;
	tab[2].type = TOK_BLK;
	tab[2].str = "\t";
	tab[2].size = 1;
	tab[3].type = TOK_EOF;
	tab[3].str = "\0";
	tab[3].size = 1;
	tab[4].type = TOK_EQ;
	tab[4].str = "=";
	tab[4].size = 1;
	tab[5].type = TOK_OP;
	tab[5].str = "*";
	tab[5].size = 1;
	tab[6].type = TOK_SIG;
	tab[6].str = "+";
	tab[6].size = 1;
	tab[7].type = TOK_SIG;
	tab[7].str = "-";
	tab[7].size = 1;
}

int				par_known(char *str, const t_tok *tab, t_tok *tok)
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
			return (!ret);
		}
		i++;
	}
	return (0);
}

int				par_not_known(char *str, t_tok *tok)
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
	par_init(tab);
	while (*av != '\0')
	{
		ft_bzero((void *)&tok, sizeof(t_tok));
		if (!par_known(av, tab, &tok))
		{
			if (!par_not_known(av, &tok))
				return (ERR_LEX);
			tok.type = flag ? TOK_EXP : TOK_COEF;
			flag = flag ? 0 : 1;
		}
		if (tok.type != TOK_BLK && tok.type != TOK_X && tok.type != TOK_OP)
		{
			if (!(dtab_push(dtab, (void *)&tok)))
				return (ERR_ML);
		}
		av += tok.size;
	}
	return (NO_ERR);
}
