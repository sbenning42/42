/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 14:53:02 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/26 16:06:40 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regexp.h"

t_regex_lexem		*reg_new_lexem(char *parser_key, int id, char *value, size_t size)
{
	t_regex_lexem	*token;

	token = (t_regex_lexem *)ft_memalloc(sizeof(t_regex_lexem));
	if (!token)
		return (NULL);
	token->parser_key = parser_key;
	token->value = ft_strsub(value, 0, size);
	token->start = value;
	token->id = id;
	if (!token->value)
	{
		free(token);
		return (NULL);
	}
	return (token);
}

void				reg_add_lexem(t_regex_lexem **lst, t_regex_lexem *token)
{
	t_regex_lexem	*drive;

	if (!*lst)
	{
		*lst = token;
		return ;
	}
	drive = *lst;
	while (drive->next)
		drive = drive->next;
	drive->next = token;
}

int			reg_lexer(t_parser *self, char **scan, char *start_match, void *data)
{
	t_regex_lexem	**lst;
	t_regex_lexem	*token;

	lst = (t_regex_lexem **)data;
	if (!(token = reg_new_lexem(self->key, self->id, start_match, *scan - start_match)))
		return (-1);
	reg_add_lexem(lst, token);
	return (0);
}

int			reg_pop(t_parser *self, char **scan, char *start_match, void *data)
{
	t_regex_lexem	*drive;
	t_regex_lexem	*previous;

	previous = NULL;
	drive = *(t_regex_lexem **)data;
	while (drive)
	{
		if (drive->start >= start_match)
		{
			if (previous)
				previous->next = NULL;	//TODO Possible huge leaks here!!! (list is cut not destroy)!
			else
				*(t_regex_lexem **)data = NULL;
			break ;
		}
		previous = drive;
		drive = drive->next;
	}
	return (0);
	(void)self;
	(void)scan;
}
