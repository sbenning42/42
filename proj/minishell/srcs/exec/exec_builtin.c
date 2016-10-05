/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 16:47:11 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/15 17:30:13 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static pid_t	handle_fd(t_tree *root, pid_t pid)
{
	if ((root->cmd.bitset & EX_OUTPIPE) == EX_OUTPIPE)
	{
		if ((pid = fork()) == 0)
		{
			dup2(root->cmd.fd[1][1], 1);
			close(root->cmd.fd[1][0]);
			close(root->cmd.fd[1][1]);
		}
	}
	else if ((root->cmd.bitset & EX_OUTREDIR) == EX_OUTREDIR)
	{
		if ((pid = fork()) == 0)
		{
			dup2(root->cmd.fd[1][1], 1);
			close(root->cmd.fd[1][1]);
		}
	}
	return (pid);
}

int				exec_builtin(t_sh *sh, t_tree *root)
{
	pid_t		pid;

	pid = 0;
	pid = handle_fd(root, pid);
	if (pid == 0)
	{
		if (!ft_strcmp(root->content->value.str, "exit"))
			return (built_exit(sh, root));
		else if (!ft_strcmp(root->content->value.str, "prompt"))
			return (built_prompt(sh, root));
		else if (!ft_strcmp(root->content->value.str, "cd"))
			return (built_cd(sh, root));
		else if (!ft_strcmp(root->content->value.str, "echo"))
			return (built_echo(sh, root));
		else if (!ft_strcmp(root->content->value.str, "env"))
			return (built_env(sh, root));
		else if (!ft_strcmp(root->content->value.str, "setenv"))
			return (built_setenv(sh, root));
		else if (!ft_strcmp(root->content->value.str, "unsetenv"))
			return (built_unsetenv(sh, root));
		return (1);
	}
	return (0);
}
