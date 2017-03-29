/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_match.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 19:13:05 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/26 19:50:01 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			match_t_registre(t_parser *self, char **scan, void *data)
{
	char	*tmp;

	if (**scan != 'r')
		return (0);
	*scan += 1;
	tmp = *scan;
	while (ft_isdigit(**scan))
		*scan += 1;
	if (tmp == *scan)
	{
		*scan -= 1;
		return (0);
	}
	return (1);
	(void)self;
	(void)data;
}

int		match_t_indirect(t_parser *self, char **scan, void *data)
{
	char	*tmp;
	int		neg;

	neg = 0;
	if (**scan == '-')
	{
		*scan += 1;
		neg = 1;
	}
	tmp = *scan;
	while (ft_isdigit(**scan))
		*scan += 1;
	if (*scan == tmp)
	{
		*scan -= (neg ? 1 : 0);
		return (0);
	}
	return (1);
	(void)self;
	(void)data;
}

int		match_t_identifier(t_parser *self, char **scan, void *data)
{
	if (!(**scan >= 'a' && **scan <= 'z'))
		return (0);
	while (**scan && ft_strchr(LABEL_CHARS, **scan))
		*scan += 1;
	return (1);
	(void)self;
	(void)data;
}

int			match_t_skip_litteral(t_parser *self, char **scan, void *data)
{
	char	*tmp;

	tmp = *scan;
	while (**scan && **scan != LITTERAL_CHAR)
		*scan += 1;
	if (**scan)
		*scan += 1;
	return ((tmp == *scan ? 0 : 1));
	(void)self;
	(void)data;
}

int				match_t_skip_all(t_parser *self, char **scan, void *data)
{
	while (**scan)
		*scan += 1;
	return (1);
	(void)self;
	(void)data;
}
