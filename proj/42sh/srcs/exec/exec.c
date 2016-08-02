/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:07:43 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/30 13:50:54 by sbenning         ###   ########.fr       */
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
	if ((root->cmd.bitset & EX_NOPIPE) != EX_NOPIPE)
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

int			exec_strict_sep(t_sh *sh, t_tree *root)
{
	exec_root(sh, root->l);
	exec_root(sh, root->r);
	return (0);
}

int			exec_and_sep(t_sh *sh, t_tree *root)
{
	int		status = 0;

	status = exec_root(sh, root->l);
	if (status != 0)
		return (status);
	status = exec_root(sh, root->r);
	return (status);
}

int			exec_or_sep(t_sh *sh, t_tree *root)
{
	int		status = 0;

	status = exec_root(sh, root->l);
	if (status == 0)
		return (status);
	status = exec_root(sh, root->r);
	return (status);
}

int			exec_pipe(t_sh *sh, t_tree *root)
{
	int		fd[2];
	int		status = 0;

	if (!root->l || !root->r)
		return (1);
	pipe(fd);
	if (root->l->content->type == TY_Word)
	{
		root->l->cmd.bitset &= ~EX_NOPIPE;
		root->l->cmd.bitset &= ~EX_WAIT;
		root->l->cmd.bitset |= EX_OUTPIPE;
		root->l->cmd.fd[1][0] = fd[0];
		root->l->cmd.fd[1][1] = fd[1];
	}
	else
	{
		root->l->l->cmd.bitset &= ~EX_NOPIPE;
		root->l->l->cmd.bitset &= ~EX_WAIT;
		root->l->l->cmd.bitset |= EX_OUTPIPE;
		root->l->l->cmd.fd[1][0] = fd[0];
		root->l->l->cmd.fd[1][1] = fd[1];
	}
	exec_root(sh, root->l);
	if (root->r->content->type == TY_Word)
	{
		root->r->cmd.bitset &= ~EX_NOPIPE;
		root->r->cmd.bitset |= EX_INPIPE;
		root->r->cmd.fd[0][0] = fd[0];
		root->r->cmd.fd[0][1] = fd[1];
	}
	else
	{
		root->r->l->cmd.bitset &= ~EX_NOPIPE;
		root->r->l->cmd.bitset |= EX_INPIPE;
		root->r->l->cmd.fd[0][0] = fd[0];
		root->r->l->cmd.fd[0][1] = fd[1];
	}
	status = exec_root(sh, root->r);
	waitpid(-1, NULL, 0);
	return (status);
}

int			exec_bg(t_sh *sh, t_tree *root)
{
	exec_root(sh, root->l);
	exec_root(sh, root->r);
	return (0);
}

int			exec_stdin_redir(t_sh *sh, t_tree *root)
{
	int		fd;
	int		status;
	char	msg[2048];

	status = 0;
	if (!root->r)
		return (1);
	if (!(fd = open(root->r->content->value.str, O_RDONLY, 0755)))
	{
		ft_sprintf(msg, "open %s fail", root->r->content->value.str);
		ft_error(msg);
		return (1);
	}
	root->l->cmd.bitset &= ~EX_NOPIPE;
	root->l->cmd.bitset |= EX_INREDIR;
	root->l->cmd.fd[0][0] = fd;
	status = exec_root(sh, root->l);
	close(fd);
	return (status);
}

int			exec_stdout_redir(t_sh *sh, t_tree *root)
{
	int		fd;
	int		status;
	char	msg[2048];

	status = 0;
	if (!root->r)
		return (1);
	if (!(fd = open(root->r->content->value.str, O_WRONLY|O_CREAT|O_TRUNC, 0755)))
	{
		ft_sprintf(msg, "open %s fail", root->r->content->value.str);
		ft_error(msg);
		return (1);
	}
	root->l->cmd.bitset &= ~EX_NOPIPE;
	root->l->cmd.bitset |= EX_OUTREDIR;
	root->l->cmd.fd[1][1] = fd;
	status = exec_root(sh, root->l);
	close(fd);
	return (status);
}

int			exec_stdin_append_redir(t_sh *sh, t_tree *root)
{
	exec_root(sh, root->l);
	exec_root(sh, root->r);
	return (0);
}

int			exec_stdout_append_redir(t_sh *sh, t_tree *root)
{
	int		fd;
	int		status;
	char	msg[2048];

	status = 0;
	if (!root->r)
		return (1);
	if (!(fd = open(root->r->content->value.str, O_WRONLY|O_CREAT|O_APPEND, 0755)))
	{
		ft_sprintf(msg, "open %s fail", root->r->content->value.str);
		ft_error(msg);
		return (1);
	}
	root->l->cmd.bitset &= ~EX_NOPIPE;
	root->l->cmd.bitset |= EX_OUTREDIR;
	root->l->cmd.fd[1][1] = fd;
	status = exec_root(sh, root->l);
	close(fd);
	return (status);
}

int			exec_stderr_redir(t_sh *sh, t_tree *root)
{
	exec_root(sh, root->l);
	exec_root(sh, root->r);
	return (0);
}

int			exec_stderr_append_redir(t_sh *sh, t_tree *root)
{
	exec_root(sh, root->l);
	exec_root(sh, root->r);
	return (0);
}
