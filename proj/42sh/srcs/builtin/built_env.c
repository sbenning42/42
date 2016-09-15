/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 16:52:04 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/15 17:38:36 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			built_env(t_sh *sh, t_tree *root)
{
	int		ac;

	ac = 0;
	while (root->cmd.arg[ac])
		ac++;
	ft_env(ac, root->cmd.arg);
	if ((root->cmd.bitset & EX_OUTPIPE) == EX_OUTPIPE\
			|| (root->cmd.bitset & EX_OUTREDIR) == EX_OUTREDIR)
		exit(EXIT_SUCCESS);
	return (0);
	(void)sh;
}
