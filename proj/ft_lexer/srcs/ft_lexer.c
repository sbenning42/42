/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:08:50 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 20:09:21 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_lex			*ft_lexer(char *id, char *line)
{
	t_lex		*lst;
	t_lex		*token;

	lst = NULL;
	while (*line)
	{
		if (!(token = lx_lexer(id, line)))
		{
			lx_del(&lst);
			break ;
		}
		lx_tokenlist(&lst, token);
		line += token->len;
	}
	return (lst);
}
