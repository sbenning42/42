/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:38:08 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/27 10:40:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_position				*single_position(void)
{
	static t_position	position;

	return (&position);
}

void					reset_posotion(void)
{
	single_position()->line = 1;
	single_position()->column = 1;
}

void					inc_li_position(int offset)
{
	single_position()->line += offset;
	single_position()->column = 0;
}

void					inc_co_position(int offset)
{
	single_position()->column += offset;
}
