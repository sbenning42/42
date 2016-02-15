/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 18:16:58 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/15 11:19:29 by sbenning         ###   ########.fr       */
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

int			handle_cmd(\
			char *cmd_buffer, int size)
{
	t_cmd	cmd;

	(void)size;
	if ((cmd = parse_cmd(cmd_buffer)).not_found)
	{
		ft_fprintf(2, (IS(O_COLOR, OPT) ? FMT_CNOFOUND : FMT_NOFOUND)\
				, AV, cmd.arg_v[0], MSG_NOFOUND);
	}
	else if (!cmd.arg_v[0])
	{
		free_cmd(&cmd);
		return (1);
	}
	if (IS(O_DEBUG, OPT))
		put_cmd(cmd);
	exec(cmd);
	free_cmd(&cmd);
	return (1);
}
