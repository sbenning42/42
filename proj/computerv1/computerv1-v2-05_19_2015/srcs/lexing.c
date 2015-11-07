#include "computerv1.h"

static void		par_debug_puttype(t_ttyp type)
{
	if (type == TOK_BLK)
		ft_putstr("TOK_BLK");
	else if (type == TOK_COEF)
		ft_putstr("TOK_COEF");
	else if (type == TOK_EOF)
		ft_putstr("TOK_EOF");
	else if (type == TOK_EQ)
		ft_putstr("TOK_EQ");
	else if (type == TOK_EXP)
		ft_putstr("TOK_EXP");
	else if (type == TOK_OP)
		ft_putstr("TOK_OP");
	else if (type == TOK_SIG)
		ft_putstr("TOK_SIG");
	else if (type == TOK_X)
		ft_putstr("TOK_X");
}

void		par_debug_put(t_tok *tab, unsigned int size)
{
	unsigned int	i;
	
	i = 0;
	while (i < size)
	{
		ft_putstr("\nTOK:\n\tType:\t");
		par_debug_puttype(tab[i].type);
		ft_putstr("\n\tStr:\t");
		ft_putstr(tab[i].str);
		ft_putstr("\n\tVal:\t");
		ft_putnbr(tab[i].val);
		ft_putstr("\n");
		i++;
	}
	ft_putstr("\n");
}

void       par_init(t_tok *tab)
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

int             par_not_known(char *str, t_tok *tok)
{
  int          i;
  char			val[64];
  
  i = 0;
  while (str[i] && ft_strchr(CHARSET, str[i]))
    i++;
  tok->str = str;
  tok->size = i;
  ft_strncpy(val, str, i);
  tok->val = ft_atof(val);
  return (i ? NO_ERR : ERR_LEX);
}

int             	cmp_parse(t_dtab *dtab, char *av)
{
	t_tok           tok;
	t_tok           tab[NB_TOK];
	int				flag;

	flag = 0;
	par_init(tab);
	while (*av != '\0')
	{
		ft_bzero((void *)&tok, sizeof(t_tok));
		if (!par_known(av, tab, &tok))
		{
			if(!par_not_known(av, &tok))
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
