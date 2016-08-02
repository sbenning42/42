/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 18:16:58 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/17 17:46:54 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void	free_cmd(\
			t_cmd *cmd)
{
	char	**cp;

	cp = cmd->arg_v;
	while (*cp)
	{
		ft_memdel((void **)cp);
		cp++;
	}
	ft_memdel((void **)&cmd->arg_v);
}

static void	nofound(\
			char *cmd_name)
{
	char	*fmt;

	fmt = (IS(O_COLOR, OPT) ? FMT_CNOFOUND : FMT_NOFOUND);
	ft_fprintf(2, fmt, AV, MSG_NOFOUND, cmd_name);
}

int			handle_cmd(\
			char *cmd_buffer)
{
	t_cmd	cmd;
	int		ret;

	ret = 1;
	cmd = parse_cmd(cmd_buffer);
	debug_cmd(cmd);
	if (cmd.not_found)
		nofound(cmd.arg_v[0]);
	else if (cmd.builtin)
		ret = cmd.built(cmd.arg_v);
	else
		exec_binary(cmd);
	free_cmd(&cmd);
	return (ret);
}
