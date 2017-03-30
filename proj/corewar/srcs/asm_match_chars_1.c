/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_match_chars_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:13:50 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/30 18:17:05 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token	*match_comment(t_parser *self, char **scan, void *data)
{
	return (match_char(self, scan, data, COMMENT_CHAR));
}

t_token	*match_command(t_parser *self, char **scan, void *data)
{
	return (match_char(self, scan, data, COMMAND_CHAR));
}

t_token	*match_literal(t_parser *self, char **scan, void *data)
{
	return (match_char(self, scan, data, LITERAL_CHAR));
}
