/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_singleton.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 08:44:37 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/24 08:44:43 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_position				*s_cursor_position(void)
{
	static t_position	position;

	return (&position);
}

void					cursor_position_reset(void)
{
	s_cursor_position()->li = 1;
	s_cursor_position()->co = 1;
}

void					cursor_position_inc_li(int offset)
{
	s_cursor_position()->li += offset;
}

void					cursor_position_inc_co(int offset)
{
	s_cursor_position()->co += offset;
}
