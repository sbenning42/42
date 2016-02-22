/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 12:17:36 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/22 12:23:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sb42sh.h"

int		hook_input_read(char *buffer)
{
	int	offset;

	if ((offset = read(0, buffer, HOOK_INPUT_SIZE + 1)) < 0)
		return (-1);
	buffer[offset] = 0;
	return ((offset ? 1 : 0));
}
