/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 11:08:59 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/17 13:44:38 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void		exec_binary(\
			t_cmd cmd)
{
	int		stat_loc;
	pid_t	pid;

	if ((pid = fork()) < 0)
	{
		error(Fork, NULL, EXIT_SUCCESS);
		return ;
	}
	else if (!pid && execve(cmd.pathbin, cmd.arg_v, ENV))
		error(Execve, cmd.pathbin, EXIT_FAILURE);
	else if (!pid)
		exit_error();
	else
		wait(&stat_loc);
}
