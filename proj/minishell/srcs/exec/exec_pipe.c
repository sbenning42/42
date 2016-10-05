/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 13:56:27 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 14:19:05 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	exec_outpipe(t_cmd *cmd, int *fd)
{
	cmd->bitset &= ~EX_NOPIPE;
	cmd->bitset &= ~EX_WAIT;
	cmd->bitset |= EX_OUTPIPE;
	cmd->fd[1][0] = fd[0];
	cmd->fd[1][1] = fd[1];
}

static void	exec_inpipe(t_cmd *cmd, int *fd)
{
	cmd->bitset &= ~EX_NOPIPE;
	cmd->bitset |= EX_INPIPE;
	cmd->fd[0][0] = fd[0];
	cmd->fd[0][1] = fd[1];
}

int			exec_pipe(t_sh *sh, t_tree *root)
{
	int		fd[2];
	int		status;

	if (!root->l || !root->r)
		return (1);
	pipe(fd);
	if (root->l->content->type == TY_Word)
		exec_outpipe(&root->l->cmd, fd);
	else
		exec_outpipe(&root->l->l->cmd, fd);
	exec_root(sh, root->l);
	if (root->r->content->type == TY_Word)
		exec_inpipe(&root->r->cmd, fd);
	else
		exec_inpipe(&root->r->l->cmd, fd);
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
