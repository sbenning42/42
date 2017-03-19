/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 09:34:05 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/19 10:04:58 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int					parse_tag(char *line, int *state)
{
	int				i;

	if (*(line + 1) != LEM_COMMENT_CHAR)
		return (LEM_NOERR);
	if (*state != LEM_DEFAULT_STATE)
		return (LEM_NOPOP_ERR);
	i = -1;
	while (g_cmd[++i].cmd)
	{
		if (!ft_strcmp(line + 2, g_cmd[i].cmd))
			*state = g_cmd[i].state;
	}
	return (LEM_NOERR);
}
