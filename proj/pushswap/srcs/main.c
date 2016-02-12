/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 11:16:47 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/12 12:43:18 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int			main(int ac, char *av[])
{
	char	e;
	int		skip;

	e = 0;
	*opt() = get_opt(CSET_O, ac, av, &e);
	if (IS(O_PRIVATE_ERROR, *opt()))
		return (ps_usage(av[0], e, EXIT_FAILURE));
	skip = go_over_opt(ac, av);
	av += skip;
	if (!(ac -= skip))
		return (EXIT_SUCCESS);
	return (pushswap(ac, av));
}
