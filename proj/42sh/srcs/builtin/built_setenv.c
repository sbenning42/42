/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_setenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 16:54:13 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/15 17:30:11 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			built_setenv(t_sh *sh, t_tree *root)
{
	char	*k;
	char	key[1024];
	char	*v;

	k = NULL;
	v = NULL;
	if (root->cmd.arg[1])
	{
		k = root->cmd.arg[1];
		ft_sprintf(key, "%s=", k);
		if (root->cmd.arg[2])
			v = root->cmd.arg[2];
	}
	if (k && v)
		ft_setenv(key, v);
	if ((root->cmd.bitset & EX_OUTPIPE) == EX_OUTPIPE\
			|| (root->cmd.bitset & EX_OUTREDIR) == EX_OUTREDIR)
		exit(EXIT_SUCCESS);
	return (0);
	(void)sh;
}
