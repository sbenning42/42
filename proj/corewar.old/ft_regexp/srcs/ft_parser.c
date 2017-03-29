/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 13:37:34 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/26 17:34:51 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void                skip_whitechar(char **s)
{
	while (**s == ' ' || **s == '\t')
		*s += 1;
}

int                 parse(t_parser *self, char **scan, void *data)
{
	char            *scan_start;
	char            *match_start;

	if (!self)
		return (TRUE);
	if (!self->match)
		return (FALSE);
	scan_start = *scan;
	if (self->skip_white)
		skip_whitechar(scan);
	match_start = *scan;
	if (self->match(self, scan, data) == FALSE)
	{
		if (self->unmatch_callback\
				&& self->unmatch_callback(self, scan, match_start, data))
			exit(1);
		*scan = scan_start;
		return (FALSE);
	}
	if (self->match_callback\
			&& self->match_callback(self, scan, match_start, data))
		exit(1);
	return (TRUE);
}

int                 match_c(t_parser *self, char **scan, void *data, char c)
{
	if (**scan == c)
	{
		if (**scan)
			*scan += 1;
		return (TRUE);
	}
	return (FALSE);
	(void)self;
	(void)data;
}

int                 match_and(t_parser *self, char **scan, void *data)
{
	if (parse(self->left, scan, data))
	{
		if (parse(self->right, scan, data))
			return (TRUE);
	}
	return (FALSE);
}

int                 match_or(t_parser *self, char **scan, void *data)
{
	if (parse(self->right, scan, data))
		return (TRUE);
	return (parse(self->left, scan, data));
}

int                 match_xor(t_parser *self, char **scan, void *data)
{
	int             left;
	int             right;

	left = parse(self->left, scan, data);
	right = parse(self->right, scan, data);
	return ((((left && right) || (!left && !right)) ? FALSE : TRUE));
}
