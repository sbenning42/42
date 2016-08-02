/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:07:43 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/28 08:24:45 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int			exec_new_cmd(t_tree *root, t_dic_entry *bin)
{
	char	*path;
	char	*key;

	ft_bzero((void *)root->cmd.bin, 2048);
	key = root->content->value.str;
	if ((path = (char *)ft_dicget(bin, key)))
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
	if ((root->cmd.bitset & EX_OUTPIPE) == EX_OUTPIPE)
	{
		dup2(root->cmd.fd[1][1], 1);
		close(root->cmd.fd[1][0]);
		close(root->cmd.fd[1][1]);
	}
	if ((root->cmd.bitset & EX_OUTREDIR) == EX_OUTREDIR)
	{
		dup2(root->cmd.fd[1][1], 1);
		close(root->cmd.fd[1][1]);
	}
	execve(root->cmd.bin, root->cmd.arg, root->cmd.env);
	exit(EXIT_FAILURE);
}

int			exec_word(t_tree *root, t_dic_entry *bin)
{
	pid_t	pid;
	int		status;

	status = 0;
	if (root->content->len > 1024)
		return (1);
	if (exec_new_cmd(root, bin) < 0)
		return (1);
	if ((pid = fork()) == 0)
		exec_fork(root);
	if ((root->cmd.bitset & EX_INPIPE) == EX_INPIPE)
	{
//		ft_fprintf(2, "F father [%s] close fd [%d][%d]\n", root->content->value.str, root->cmd.fd[0][0], root->cmd.fd[0][1]);
		close(root->cmd.fd[0][0]);
		close(root->cmd.fd[0][1]);
	}
//	ft_fprintf(2, "F father [%s] bitset [%#x] wait [%d]\n", root->content->value.str, root->cmd.bitset, root->cmd.bitset & EX_WAIT);
	if ((root->cmd.bitset & EX_WAIT) == EX_WAIT)
	{
//		ft_fprintf(2, "F father [%s] waiting for exec\n", root->content->value.str);
		waitpid(pid, &status, 0);
//		ft_fprintf(2, "F father [%s] return after waiting\n", root->content->value.str);
		return (WEXITSTATUS(status));
	}
//	ft_fprintf(2, "F father [%s] return without waiting\n", root->content->value.str);
	return (0);
}

int			exec_strict_sep(t_tree *root, t_dic_entry *bin)
{
	exec_root(root->l, bin);
	exec_root(root->r, bin);
	return (0);
}

int			exec_and_sep(t_tree *root, t_dic_entry *bin)
{
	int		status = 0;

	status = exec_root(root->l, bin);
	if (status != 0)
		return (status);
	status = exec_root(root->r, bin);
	return (status);
}

int			exec_or_sep(t_tree *root, t_dic_entry *bin)
{
	int		status = 0;

	status = exec_root(root->l, bin);
	if (status == 0)
		return (status);
	status = exec_root(root->r, bin);
	return (status);
}

int			exec_pipe(t_tree *root, t_dic_entry *bin)
{
	int		fd[2];
	int		status = 0;

	if (!root->l || !root->r)
		return (1);
	pipe(fd);
//	ft_fprintf(2, "father [%s] opened 2 fd [%d][%d]\n", root->content->value.str, fd[0], fd[1]);
	root->l->cmd.bitset &= ~EX_NOPIPE;
	root->l->cmd.bitset &= ~EX_WAIT;
	root->l->cmd.bitset |= EX_OUTPIPE;
	root->l->cmd.fd[1][0] = fd[0];
	root->l->cmd.fd[1][1] = fd[1];
//	ft_fprintf(2, "father [%s] exec left son [%s]\n", root->content->value.str, root->l->content->value.str);
	exec_root(root->l, bin);
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
//	ft_fprintf(2, "father [%s] exec right son [%s]\n", root->content->value.str, root->r->content->value.str);
	status = exec_root(root->r, bin);
//	ft_fprintf(2, "father wait for all pid to termine\n");
	waitpid(-1, NULL, 0);
//	ft_fprintf(2, "father [%s] return\n", root->content->value.str, root->r->content->value.str);
	return (status);
}

int			exec_bg(t_tree *root, t_dic_entry *bin)
{
	exec_root(root->l, bin);
	exec_root(root->r, bin);
	return (0);
}

int			exec_stdin_redir(t_tree *root, t_dic_entry *bin)
{
	exec_root(root->l, bin);
	exec_root(root->r, bin);
	return (0);
}

int			exec_stdout_redir(t_tree *root, t_dic_entry *bin)
{
	int		fd;

	if (!root->r)
		return (1);
	if (!(fd = open(root->r->content->value.str, O_WRONLY|O_CREAT|O_TRUNC, 0755)))
	{
		ft_fprintf(2, "can't open [%s]\n", root->r->content->value.str);
		return (1);
	}
	root->l->cmd.bitset &= ~EX_NOPIPE;
	root->l->cmd.bitset |= EX_OUTREDIR;
	root->l->cmd.fd[1][1] = fd;
	exec_root(root->l, bin);
	waitpid(-1, NULL, 0);
	close(fd);
	return (0);
}

int			exec_stdin_append_redir(t_tree *root, t_dic_entry *bin)
{
	exec_root(root->l, bin);
	exec_root(root->r, bin);
	return (0);
}

int			exec_stdout_append_redir(t_tree *root, t_dic_entry *bin)
{
	exec_root(root->l, bin);
	exec_root(root->r, bin);
	return (0);
}

int			exec_stderr_redir(t_tree *root, t_dic_entry *bin)
{
	exec_root(root->l, bin);
	exec_root(root->r, bin);
	return (0);
}

int			exec_stderr_append_redir(t_tree *root, t_dic_entry *bin)
{
	exec_root(root->l, bin);
	exec_root(root->r, bin);
	return (0);
}
