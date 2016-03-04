/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:40:08 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/04 20:59:10 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_lex		*lx_token(t_lex token)
{
	t_lex	*cp;

	if (!(cp = (t_lex *)ft_memalloc(sizeof(t_lex))))
		return (NULL);
	*cp = token;
	if (!(cp->value = ft_strdup(token.value)))
	{
		free(cp);
		return (NULL);
	}
	return (cp);
}

void		lx_tokenlist(t_lex **alst, t_lex *token)
{
	t_lex	*cp;

	if (!*alst)
	{
		*alst = token;
		return ;
	}
	cp = *alst;
	while (cp->next)
		cp = cp->next;
	cp->next = token;
	token->previous = cp;
}
