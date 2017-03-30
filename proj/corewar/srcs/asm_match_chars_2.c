/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_match_chars_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:17:12 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/30 18:18:13 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token	*match_label(t_parser *self, char **scan, void *data)
{
	return (match_char(self, scan, data, LABEL_CHAR));
}

t_token	*match_separator(t_parser *self, char **scan, void *data)
{
	return (match_char(self, scan, data, SEPARATOR_CHAR));
}

t_token	*match_direct(t_parser *self, char **scan, void *data)
{
	return (match_char(self, scan, data, DIRECT_CHAR));
}
