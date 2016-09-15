/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:07:03 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/15 16:50:13 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			built_echo(t_sh *sh, t_tree *root)
{
	int		i;
	int		nl;

	nl = 1;
	i = 0;
	while (root->cmd.arg[++i])
	{
		if ((i == 1) && !ft_strcmp(root->cmd.arg[i], "-n"))
			nl = 0;
		else if (root->cmd.arg[i + 1])
			ft_printf("%s ", root->cmd.arg[i]);
		else if (nl)
			ft_printf("%s\n", root->cmd.arg[i]);
		else
			ft_printf("%s", root->cmd.arg[i]);
	}
	if ((root->cmd.bitset & EX_OUTPIPE) == EX_OUTPIPE\
			|| (root->cmd.bitset & EX_OUTREDIR) == EX_OUTREDIR)
		exit(EXIT_SUCCESS);
	return (0);
	(void)sh;
}
