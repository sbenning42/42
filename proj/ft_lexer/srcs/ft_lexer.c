/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:08:50 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 17:48:09 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_lex			*ft_lexer(char *line)
{
	t_lex		*lst;
	t_lex		*token;
	t_lexcode	code;
	t_lexstate	curr_state;

	lst = NULL;
	curr_state = ST_Entry;
	while (*line)
	{
		code = g_fstate[curr_state](*line, &token, &curr_state);
		if (code == CO_Fail)
		{
			if (token)
				ft_fprintf(2, "lexer: error near token \"%s\"\n", token->value);
			lx_del(&lst);
			break ;
		}
		if (curr_state == ST_Entry)
			lx_tokenlist(&lst, token);
		line++;
	}
	return (lst);
}
