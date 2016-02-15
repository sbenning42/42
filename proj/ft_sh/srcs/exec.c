/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 11:08:59 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/15 11:20:26 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void		fork_error(void)
{
	ft_fprintf(2, "Fork failure...\n");
}

void		exec(\
			t_cmd cmd)
{
	int		stat_loc;
	pid_t	pid;

	if ((pid = fork()) < 0)
	{
		fork_error();
		return ;
	}
	else if (!pid && execve(cmd.pathbin, cmd.arg_v, cmd.env_p))
		exit(EXIT_FAILURE);
	else
		waitpid(pid, &stat_loc, 0);
}
