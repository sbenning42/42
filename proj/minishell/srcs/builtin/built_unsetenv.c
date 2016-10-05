/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_unsetenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 16:54:29 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/15 17:30:15 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			built_unsetenv(t_sh *sh, t_tree *root)
{
	int		i;

	i = 0;
	while (root->cmd.arg[++i])
		ft_unsetenv(root->cmd.arg[i]);
	if ((root->cmd.bitset & EX_OUTPIPE) == EX_OUTPIPE\
			|| (root->cmd.bitset & EX_OUTREDIR) == EX_OUTREDIR)
		exit(EXIT_SUCCESS);
	return (0);
	(void)sh;
}
