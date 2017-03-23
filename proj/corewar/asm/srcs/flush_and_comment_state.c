/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush_and_comment_state.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:05:30 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/23 12:08:09 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	actual_flush_state(t_lexem *lexem, char c, int state)
{
	lexem->token.type = state;
	if (c == NL_CHAR)
	{
		token_reset(lexem);
		return (default_state(lexem, c));
	}
	return (0);
}

int			flush_state(t_lexem *lexem, char c)
{
	return (actual_flush_state(lexem, c, ST_FLUSH));
}

int			comment_state(t_lexem *lexem, char c)
{
	return (actual_flush_state(lexem, c, ST_COMMENT));
}
