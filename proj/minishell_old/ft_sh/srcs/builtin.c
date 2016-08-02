/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:36:11 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/17 16:26:25 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static char			*g_builtin_id[FT_SH_BUILTIN_SIZE] = {\
	"cd",\
	"env",\
	"setenv",\
	"unsetenv",\
	"exit"};

static t_built_f	g_builtin_built[FT_SH_BUILTIN_SIZE] = {\
	builtin_cd,\
	builtin_env,\
	builtin_setenv,\
	builtin_unsetenv,\
	builtin_exit};

void				dic_builtin(\
					void)
{
	int				i;

	i = 0;
	while (i < FT_SH_BUILTIN_SIZE)
	{
		BUILTIN[i].id = g_builtin_id[i];
		BUILTIN[i].built = g_builtin_built[i];
		i++;
	}
	debug_builtin();
}
