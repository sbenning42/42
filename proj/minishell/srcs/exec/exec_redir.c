/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 13:54:07 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 14:08:17 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

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
	fd = open(root->r->content->value.str, O_WRONLY | O_CREAT | O_TRUNC, 0755);
	if (fd < 0)
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
