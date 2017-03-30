/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_match_argument.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:21:35 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/30 18:23:17 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token		*match_directlab(t_parser *self, char **scan, void *data)
{
	t_token	*token;

	if (**scan != DIRECT_CHAR || *((*scan) + 1) != LABEL_CHAR)
		return (NULL);
	if (!(token = new_token(self->id, *scan, 2, *single_position())))
		return (NULL);
	token->id = self->id;
	token->key = self->key;
	*scan += 2;
	inc_co_position(2);
	return (token);
	(void)data;
}

t_token		*match_registre(t_parser *self, char **scan, void *data)
{
	t_token	*token;
	size_t	i;

	if (**scan != 'r')
		return (NULL);
	i = 1;
	while (ft_isdigit((*scan)[i]))
		++i;
	if (!(token = new_token(self->id, *scan, i, *single_position())))
		return (NULL);
	token->id = self->id;
	token->key = self->key;
	*scan += i;
	inc_co_position(i);
	return (token);
	(void)data;
}

t_token		*match_skip_literal(t_parser *self, char **scan, void *data)
{
	t_token	*token;
	size_t	i;

	i = 0;
	while ((*scan)[i] && (*scan)[i] != '"')
		++i;
	if (!(*scan)[i])
		return (NULL);
	++i;
	if (!(token = new_token(self->id, *scan, i, *single_position())))
		return (NULL);
	token->id = self->id;
	token->key = self->key;
	*scan += i;
	inc_co_position(i);
	return (token);
	(void)data;
}

t_token		*match_skip_empty(t_parser *self, char **scan, void *data)
{
	t_token	*token;

	while (**scan)
		*scan += 1;
	if (!(token = new_token(self->id, *scan, 1, *single_position())))
		return (NULL);
	token->id = self->id;
	token->key = self->key;
	return (token);
	(void)data;
}

t_token		*match_empty(t_parser *self, char **scan, void *data)
{
	t_token	*token;

	if (!**scan)
	{
		if (!(token = new_token(self->id, *scan, 1, *single_position())))
		{
			ft_fprintf(2, "MALLOC ERROR\n");
			return (NULL);
		}
		token->id = self->id;
		token->key = self->key;
		return (token);
	}
	return (NULL);
	(void)data;
}
