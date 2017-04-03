/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 09:08:05 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/29 11:42:29 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		del_token(t_token **lst)
{
	t_token	*drive;

	drive = *lst;
	while (drive)
	{
		*lst = drive->next;
		free(drive->value);
		free(drive);
		drive = *lst;
	}
}

void		pop_token(t_token **lst)
{
	t_token	*tmp;

	if (!*lst)
		return ;
	tmp = (*lst)->next;
	free((*lst)->value);
	free(*lst);
	*lst = tmp;
}

t_token		*new_token(int id, char *value, size_t size, t_position position)
{
	t_token	*token;

	if (!(token = (t_token *)ft_memalloc(sizeof(t_token))))
		return (NULL);
	if (!(token->value = ft_strsub(value, 0, (size ? size : 1))))
	{
		free(token);
		return (NULL);
	}
	token->id = id;
	token->size = size;
	token->position = position;
	return (token);
}

void		add_token(t_token **lst, t_token *token)
{
	t_token	*drive;

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

t_token		*match_and(t_parser *self, char **scan, void *data)
{
	size_t		i;
	t_token		*lst;
	t_token		*trunk;
	t_parser	*next_parser;

	lst = NULL;
	i = 0;
	while (i < self->size)
	{
		next_parser = (self - self->id) + self->child[i];
		if (!(trunk = ft_parse(next_parser, scan, data)))
		{
			del_token(&lst);
			return (NULL);
		}
		add_token(&lst, trunk);
		++i;
	}
	return (lst);
}

t_token		*match_or(t_parser *self, char **scan, void *data)
{
	size_t	i;
	t_token		*lst;
	t_parser	*next_parser;

	i = 0;
	while (i < self->size)
	{
		next_parser = (self - self->id) + self->child[i];
		if ((lst = ft_parse(next_parser, scan, data)))
			return (lst);
		++i;
	}
	return (NULL);
}

t_token		*match_id(t_parser *self, char **scan, void *data)
{
	t_token	*token;
	size_t	i;

	if (!ft_isalpha(**scan))
		return (NULL);
	i = 1;
	while ((*scan)[i] == '_' || ft_isalpha((*scan)[i]) || ft_isdigit((*scan)[i]))
		++i;
	if (!(token = new_token(self->id, *scan, i, *single_position())))
		return (NULL);
	token->key = self->key;
	*scan += i;
	inc_co_position(i);
	return (token);
	(void)data;
}

t_token		*match_num(t_parser *self, char **scan, void *data)
{
	t_token	*token;
	size_t	i;
	int		neg;

	neg = 0;
	i = 0;
	if (**scan == '-')
		neg = 1;
	while (ft_isdigit((*scan)[i + neg]))
		++i;
	if (!i)
		return (NULL);
	if (!(token = new_token(self->id, *scan, i + neg, *single_position())))
		return (NULL);
	token->key = self->key;
	*scan += (i + neg);
	inc_co_position(i + neg);
	return (token);
	(void)data;
}

t_token		*match_char(t_parser *self, char **scan, void *data, char c)
{
	t_token	*token;

	if (**scan == c)
	{
		if (!(token = new_token(self->id, *scan, 1, *single_position())))
		{
			ft_fprintf(2, "MALLOC ERROR\n");
			return (NULL);
		}
		token->key = self->key;
		*scan += 1;
		inc_co_position(1);
		return (token);
	}
	return (NULL);
	(void)data;
}

void		skip_whitespace(char **scan)
{
	while (**scan == ' ' || **scan == '\t')
	{
		*scan += 1;
		inc_co_position(1);
	}
}

t_token		*ft_parse(t_parser *self, char **scan, void *data)
{
	t_token	*lst;
	char	*start_scan;

	if (!self)
		return (NULL);
	if (!self->match)
		return (NULL);
	start_scan = *scan;
	if (self->whitespace)
		skip_whitespace(scan);
	if ((lst = self->match(self, scan, data)))
	{
		if (self->callback && self->callback(self, &lst))
			exit(1);
		return (lst);
	}
	single_position()->column -= (*scan - start_scan);
	*scan = start_scan;
	return (NULL);
}
