/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 14:52:51 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/15 16:53:59 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int				built_cd(t_sh *sh, t_tree *root)
{
	int			ac;

	ac = 0;
	while (root->cmd.arg[ac])
		ac++;
	if ((root->cmd.bitset & EX_OUTPIPE) == EX_OUTPIPE\
			|| (root->cmd.bitset & EX_OUTREDIR) == EX_OUTREDIR)
	{
		ft_cd(ac, root->cmd.arg);
		exit(EXIT_SUCCESS);
	}
	return (ft_cd(ac, root->cmd.arg));
	(void)sh;
}
