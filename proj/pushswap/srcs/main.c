/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 11:16:47 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/15 10:18:21 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int			main(\
			int ac, char *av[])
{
	char	e;
	int		skip;
	int		o;

	e = 0;
	o = get_opt(CSET_O, ac, av, &e);
	if (IS(O_DEBUG, o))
		debug_o(o);
	if (IS(O_PRIVATE_ERROR, o))
		return (usage(av[0], e, EXIT_FAILURE, o));
	skip = go_over_opt(ac, av);
	av += skip;
	if (!(ac -= skip))
		return (EXIT_SUCCESS);
	return (pushswap(ac, av, o));
}
