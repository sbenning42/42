/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regexp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 12:15:37 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/26 14:48:14 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regexp.h"

int				match_tild(t_parser *self, char **scan, void *data)
{
	return (match_c(self, scan, data, '~'));
}

int				match_inter(t_parser *self, char **scan, void *data)
{
	return (match_c(self, scan, data, '?'));
}

int				match_star(t_parser *self, char **scan, void *data)
{
	return (match_c(self, scan, data, '*'));
}

int				match_plus(t_parser *self, char **scan, void *data)
{
	return (match_c(self, scan, data, '+'));
}

int				match_minus(t_parser *self, char **scan, void *data)
{
	return (match_c(self, scan, data, '-'));
}

int				match_open_bracket(t_parser *self, char **scan, void *data)
{
	return (match_c(self, scan, data, '['));
}

int				match_close_bracket(t_parser *self, char **scan, void *data)
{
	return (match_c(self, scan, data, ']'));
}

int				match_letter(t_parser *self, char **scan, void *data)
{
	if (!**scan)
		return (0);
	if (ft_strchr(REGEXP_FORBBIDEN_CHARS, **scan))
		return (0);
	*scan += 1;
	return (1);
	(void)self;
	(void)data;
}

int				match_litteral(t_parser *self, char **scan, void *data)
{
	char		*tmp;

	tmp = *scan;
	while (**scan && !ft_strchr(REGEXP_FORBBIDEN_CHARS, **scan))
		*scan += 1;
	return ((tmp == *scan ? 0 : 1));
	(void)self;
	(void)data;
}
