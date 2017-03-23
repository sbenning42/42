/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 08:53:39 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/23 11:51:10 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				token_reset(t_lexem *lexem)
{
	lexem->token.value = NULL;
	lexem->token.size = 0;
	lexem->token.type = 0;
}

void				token_delete(t_lexem *lexem)
{
	if (lexem->token.value)
		free(lexem->token.value);
	token_reset(lexem);
}

int					token_push(t_lexem *lexem, char c)
{
	char			*tmp;

	tmp = lexem->token.value;
	if (!(lexem->token.value = ft_strnew(lexem->token.size + 1)))
		return (-1);
	if (lexem->token.size)
		ft_memcpy(lexem->token.value, tmp, lexem->token.size);
	lexem->token.value[lexem->token.size] = c;
	lexem->token.size += 1;
	if (tmp)
		free(tmp);
	return (0);
}

int					token_save(t_lexem *lexem)
{
	t_list			*elem;

	if (!(elem = ft_lstnew(&lexem->token, sizeof(t_token))))
		return (-1);
	ft_lstadd_back(&lexem->lst, elem);
	token_reset(lexem);
	return (0);
}
