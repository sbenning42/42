#include "lexer.h"

void				handle_op(t_tok **tab, t_tok *tmp)
{
	int				i;

	i = 0;
	while (tab[i])
	{
		if (tab[i]->type == TOK_EXP)
		{
			if (tab[i + 1]->type == TOK_SIG)
				tab[i + 1]->type = TOK_OP;	
		}
		i++;
	}

}

void				handle_sign_after_exp(t_tok **tab, t_tok *tmp, t_dtab *dtab)
{
	int				i;

	i = 0;
	while (tab[i])
	{
		if (tab[i]->type == TOK_EXP && tab[i + 1]->type != TOK_EQ && tab[i + 3]->type != TOK_COEF)
		{
			if (!(tab[i + 1]->type == SIG && tab[i + 1]->val == -1))	
			{	
				tmp->str = NULL;
				tmp->type = TOK_SIG;
				tmp->size = 1;
				tmp->value = 1.0; // value toujours en float
				dtab_add_i(dtab, (void *)tmp, i + 2);
			}
			else 
			{
				tmp->str = NULL;
				tmp->type = TOK_SIG;
				tmp->size = 1;
				tmp->value = 1.0; // value toujours en float
				dtab_add_i(dtab, (void *)tmp, i + 1);	
			}
		}
		i++;
	}

}

void				handle_exp(t_tok **tab, t_tok *tmp)
{
	int				i;

	i = 0;
	while (tab[i])
	{
		if (tab[i]->type == TOK_X)
			tab[i + 2]->type = TOK_EXP;	
		i++;
	}

}

void				handle_before_coef(t_tok **tab, t_tok *tmp, t_dtab *dtab)
{
	int				i;

	i = 0;
	while (tab[i])
	{
		if (tab[i]->type == TOK_OP && tab[i]->value == 1.0 && tab[i - 1]->type != TOK_COEF)
		{	
			tmp->str = NULL;
			tmp->type = TOK_COEF;
			tmp->size = 1;
			tmp->value = 1.0; // value toujours en float
			dtab_add_i(dtab, (void *)tmp, i);
		}
		i++;
	}

}

void				handle_after_x(t_tok **tab, t_tok *tmp, t_dtab *dtab)
{
	int				i;

	i = 0;
	while (tab[i])
	{
		if (tab[i]->type == TOK_X && tab[i]->val = 1)
		{	
			tmp->str = NULL;
			tmp->type = TOK_SIG;
			tmp->size = 1;
			tmp->value = 1.0; // value toujours en float
			dtab_add_i(dtab, (void *)tmp, i + 1);
			tmp->str = NULL;
			tmp->type = TOK_EXP;
			tmp->size = 1;
			tmp->value = 1.0; // value toujours en float
			dtab_add_i(dtab, (void *)tmp, i + 2);
		}
		else if (tab[i]-> type == TOK_X && tab[i + 1]->type != TOK_SIG)
		{
			tmp->str = NULL;
			tmp->type = TOK_SIG;
			tmp->size = 1;
			tmp->value = 1.0; // value toujours en float
			dtab_add_i(dtab, (void *)tmp, i + 1);
		}
		i++;
	}
}

void				handle_before_x(t_tok **tab, t_tok *tmp, t_dtab *dtab)
{
	int				i;

	i = 0;
	while (tab[i])
	{
		if (tab[i]->type == TOK_X && tab[i - 1]->type != TOK_OP)
		{	
			tmp->str = NULL;
			tmp->type = TOK_OP;
			tmp->size = 1;
			tmp->value = 1.0; // value toujours en float
			dtab_add_i(dtab, (void *)tmp, i);
		}
		i++;
	}
}

void				handle_begin_sign(t_tok **tab, t_tok *tmp, t_dtab *dtab)
{
	if (tab[1]->type != TOK_SIG)
	{	
		tmp->str = NULL;
		tmp->type = TOK_SIG;
		tmp->size = 1;
		tmp->value = 1.0; // value toujours en float
		dtab_add_i(dtab, (void *)tmp, 0);
	}
}
				

int       			exp_polynome(t_dtab *dtab)
{
	t_tok			*tab;
	t_tok			tmp;
	int				i;

	i = 2;
	tab = (t_tok *)dtab->data;
	handle_begin_sign(&tab, &tmp, dtab);
	handle_before_x(&tab, &tmp, dtab);
	handle_before_coef(&tab, &tmp, dtab);
	handle_after_x(&tab, &tmp, dtab);
	handle_exp(&tab, &tmp);
	handle_sign_after_exp(&tab, &tmp, dtab);
	handle_op(&tab, &tmp);
	return (42);
}
