/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 16:52:04 by sbenning          #+#    #+#             */
/*   Updated: 2016/10/05 11:01:40 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			built_env(t_sh *sh, t_tree *root)
{
	int		ac;
	int		ret;

	ac = 0;
	while (root->cmd.arg[ac])
		ac++;
	ret = ft_env(ac, root->cmd.arg, sh->bin);
	if ((root->cmd.bitset & EX_OUTPIPE) == EX_OUTPIPE\
			|| (root->cmd.bitset & EX_OUTREDIR) == EX_OUTREDIR)
		exit((ret ? EXIT_FAILURE : EXIT_SUCCESS));
	return (ret);
	(void)sh;
}
