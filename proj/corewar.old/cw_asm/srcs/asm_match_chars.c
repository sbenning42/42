/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_match_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 19:14:04 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/26 19:17:44 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		match_t_comment(t_parser *self, char **scan, void *data)
{
	return (match_c(self, scan, data, COMMENT_CHAR));
}

int		match_t_command(t_parser *self, char **scan, void *data)
{
	return (match_c(self, scan, data, COMMAND_CHAR));
}

int		match_t_litteral(t_parser *self, char **scan, void *data)
{
	return (match_c(self, scan, data, LITTERAL_CHAR));
}

int		match_t_separator(t_parser *self, char **scan, void *data)
{
	return (match_c(self, scan, data, SEPARATOR_CHAR));
}

int		match_t_direct(t_parser *self, char **scan, void *data)
{
	return (match_c(self, scan, data, DIRECT_CHAR));
}

int		match_t_label(t_parser *self, char **scan, void *data)
{
	return (match_c(self, scan, data, LABEL_CHAR));
}

int		match_t_end_line(t_parser *self, char **scan, void *data)
{
	return (match_c(self, scan, data, '\0'));
}
