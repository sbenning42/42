/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 00:24:07 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/30 09:47:53 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#define NB_MYTOKEN 0//careful

int		main(int ac, char **av)
{
	t_lex_rule		rule;
	t_lex_tk		pattern[NB_MYTOKEN];
	t_list			*lst;
	t_list			*cp;
	int				i = 0;

	if (ac != 2)
	{
		ft_fprintf(2, "main: {red}No arg.{eoc}\n");
		return (0);
	}
	
//******************************************************************************
//						SET DES RULES DU LEXER
//******************************************************************************

	rule.rec = False;
	rule.esc = False;
	rule.save_blk = False;
	rule.error = False;

//******************************************************************************
//								FIN
//******************************************************************************

//******************************************************************************
//						INVOCATION DU LEXER
//******************************************************************************

	lst = ft_lexer(rule, pattern, NB_MYTOKEN, av[1]);
	
//******************************************************************************
//								FIN
//******************************************************************************

//******************************************************************************
//							AFFICHAGE - DEBUG
//******************************************************************************

	cp = lst;
	while (cp)
	{
		ft_printf("%2d:\t%-15s% -10.*s\t", \
			i++, totype(((t_lex_tk *)cp->content)->type), \
			((t_lex_tk *)cp->content)->size, ((t_lex_tk *)cp->content)->value);
		if (((t_lex_tk *)cp->content)->save == True)
			ft_printf("save: {green}True{eoc},\t");
		else if (((t_lex_tk *)cp->content)->save == False)
			ft_printf("save: {red}False{eoc},\t");
		if (((t_lex_tk *)cp->content)->esc == True)
			ft_printf("esc: {green}True{eoc},\t");
		else if (((t_lex_tk *)cp->content)->esc == False)
			ft_printf("esc: {red}False{eoc},\t");
		if (((t_lex_tk *)cp->content)->rec == True)
			ft_printf("rec: {green}True{eoc}\n");
		else if (((t_lex_tk *)cp->content)->rec == False)
			ft_printf("rec: {red}False{eoc}\n");
		cp = cp->next;
	}

//******************************************************************************
//								FIN
//******************************************************************************

	ft_lstdel(&lst, NULL);
	return (0);
}
