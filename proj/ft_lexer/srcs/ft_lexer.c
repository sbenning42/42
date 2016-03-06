/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:08:50 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/06 13:30:43 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_lex			*ft_lexer(char *line)
{
	t_lex		*lst;
	t_lex		*token;
	int			protect;

	lst = NULL;
	protect = 0;
	while (*line)
	{
		if (!(token = lx_newtoken(TY_None, protect, 0, 0)))
			lx_del(&lst);
		else if (lx_lexer(line, &token, &protect) == CO_Fail)
			lx_del(&lst);
		else
		{
			lx_tokenlist(&lst, token);
			line += token->len;
			continue ;
		}
		break ;
	}
	return (lst);
}
