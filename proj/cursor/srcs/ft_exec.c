/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 11:33:42 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/28 08:20:04 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

t_exec		g_exec[] = {\
	exec_word,\
	exec_strict_sep,\
	exec_and_sep,\
	exec_or_sep,\
	exec_pipe,\
	exec_bg,\
	exec_stdin_redir,\
	exec_stdout_redir,\
	exec_stdin_append_redir,\
	exec_stdout_append_redir,\
	exec_stderr_redir,\
	exec_stderr_append_redir\
	\
};

int			exec_root(t_tree *root, t_dic_entry *bin)
{
	int		success;

	if (!root)
		return (0);
	success = g_exec[root->content->type](root, bin);
	return (success);
}
