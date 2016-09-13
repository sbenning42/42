/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 13:51:50 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 14:08:58 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			exec_new_cmd(t_sh *sh, t_tree *root)
{
	char	*path;
	char	*key;

	ft_bzero((void *)root->cmd.bin, 2048);
	key = root->content->value.str;
	if ((path = (char *)ft_dicget(sh->bin, key)))
	{
		ft_strcpy(root->cmd.bin, path);
		ft_strcat(root->cmd.bin, "/");
		ft_strcat(root->cmd.bin, key);
		return (0);
	}
	if (!ft_strncmp(key, "./", 2))
	{
		ft_strcat(root->cmd.bin, key);
		return (0);
	}
	ft_fprintf(2, "%s: command not found\n", root->content->value.str);
	return (-1);
}

void		exec_fork(t_tree *root)
{
	if ((root->cmd.bitset & EX_INPIPE) == EX_INPIPE)
	{
		dup2(root->cmd.fd[0][0], 0);
		close(root->cmd.fd[0][0]);
		close(root->cmd.fd[0][1]);
	}
	else if ((root->cmd.bitset & EX_INREDIR) == EX_INREDIR)
	{
		dup2(root->cmd.fd[0][0], 0);
		close(root->cmd.fd[0][0]);
	}
	if ((root->cmd.bitset & EX_OUTPIPE) == EX_OUTPIPE)
	{
		dup2(root->cmd.fd[1][1], 1);
		close(root->cmd.fd[1][0]);
		close(root->cmd.fd[1][1]);
	}
	else if ((root->cmd.bitset & EX_OUTREDIR) == EX_OUTREDIR)
	{
		dup2(root->cmd.fd[1][1], 1);
		close(root->cmd.fd[1][1]);
	}
	execve(root->cmd.bin, root->cmd.arg, root->cmd.env);
	exit(EXIT_FAILURE);
}

int			exec_is_builtin(t_tree *root)
{
	if (!ft_strcmp(root->content->value.str, "exit"))
		return (1);
	else if (!ft_strcmp(root->content->value.str, "prompt"))
		return (1);
	return (0);
}

int			exec_builtin(t_sh *sh, t_tree *root)
{
	if ((root->cmd.bitset & EX_OUTPIPE) == EX_OUTPIPE)
		return (1);
	if (!ft_strcmp(root->content->value.str, "exit"))
		return (built_exit(sh, root));
	else if (!ft_strcmp(root->content->value.str, "prompt"))
		return (built_prompt(sh, root));
	return (1);
}

int			exec_word(t_sh *sh, t_tree *root)
{
	pid_t	pid;
	int		status;

	status = 0;
	if (root->content->len > 1024)
		return (1);
	if (exec_is_builtin(root))
		return (exec_builtin(sh, root));
	if (exec_new_cmd(sh, root) < 0)
		return (1);
	if ((pid = fork()) == 0)
		exec_fork(root);
	if ((root->cmd.bitset & EX_INPIPE) == EX_INPIPE)
	{
		close(root->cmd.fd[0][0]);
		close(root->cmd.fd[0][1]);
	}
	else if ((root->cmd.bitset & EX_INREDIR) == EX_INREDIR)
		close(root->cmd.fd[0][0]);
	if ((root->cmd.bitset & EX_WAIT) == EX_WAIT)
	{
		waitpid(pid, &status, 0);
		return (WEXITSTATUS(status));
	}
	return (0);
}
