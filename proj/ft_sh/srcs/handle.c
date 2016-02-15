/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 18:16:58 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/15 00:46:00 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			handle_cmd\
				(char *cmd_buffer, int size)
{
	t_cmd	cmd;

	if (size > 1)
		cmd_buffer[size - 1] = 0;
	if ((cmd = parse_cmd(cmd_buffer)).not_found)
	{
		ft_fprintf(2, (IS(O_COLOR, OPT) ? FMT_CNOFOUND : FMT_NOFOUND)\
				, AV, cmd.arg_v[0], MSG_NOFOUND);
	}
	if (IS(O_DEBUG, OPT))
		put_cmd(cmd);
	return (1);
}
