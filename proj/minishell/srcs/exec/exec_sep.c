/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_sep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 13:53:23 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 14:04:45 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			exec_strict_sep(t_sh *sh, t_tree *root)
{
	exec_root(sh, root->l);
	exec_root(sh, root->r);
	return (0);
}

int			exec_and_sep(t_sh *sh, t_tree *root)
{
	int		status;

	status = exec_root(sh, root->l);
	if (status != 0)
		return (status);
	status = exec_root(sh, root->r);
	return (status);
}

int			exec_or_sep(t_sh *sh, t_tree *root)
{
	int		status;

	status = exec_root(sh, root->l);
	if (status == 0)
		return (status);
	status = exec_root(sh, root->r);
	return (status);
}
