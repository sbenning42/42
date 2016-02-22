/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 23:27:13 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/19 11:15:41 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int		isbuiltin(\
				t_cmd *cmd)
{
	int		i;

	i = 0;
	while (i < FT_SH_BUILTIN_SIZE)
	{
		if (!strcmp(cmd->arg_v[0], BUILTIN[i].id))
		{
			cmd->built = BUILTIN[i].built;
			return (1);
		}
		i++;
	}
	return (0);
}

static int		handle_home_spec(\
				char **arg_v)
{
	char		*cp;
	char		*value;

	if (!(value = intern_getenv("HOME")))
	{
		ft_fprintf(2, "No Home msg\n");
		return (0);
	}
	cp = *arg_v;
	if (!(*arg_v = ft_strjoin(value, *arg_v + 1)))
		error(Malloc, NULL, EXIT_FAILURE);
	free(cp);
	return (1);
}

static void		handle_spec(\
				char **arg_v)
{
	int			i;

	i = -1;
	while (arg_v[++i])
	{
		if (!ft_strncmp("~", arg_v[i], 1) && !handle_home_spec(arg_v + i))
			return ;
	}
}

t_cmd			parse_cmd(\
				char *cmd_buffer)
{
	t_cmd		cmd;
	char		*pathbin;

	ft_bzero((void *)cmd.pathbin, sizeof(char) * (FT_SH_BINARY_PATH_SIZE + 1));
	cmd.not_found = 0;
	cmd.builtin = 0;
	cmd.built = NULL;
	if (!(cmd.arg_v = ft_strsplit(cmd_buffer, ' ')))
		error(Malloc, NULL, EXIT_FAILURE);
	handle_spec(cmd.arg_v);
	if (!(cmd.builtin = isbuiltin(&cmd)))
	{
		if (!(pathbin = (char *)ft_dicentry(BINARY, cmd.arg_v[0])))
			cmd.not_found = 1;
		else
			ft_strcpy(cmd.pathbin, pathbin);
	}
	return (cmd);
}
