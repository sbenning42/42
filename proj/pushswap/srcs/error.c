/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 11:23:22 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/15 10:19:52 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	error(\
	int rtnvalue, int o)
{
	if (IS(O_COLOR, o))
		ft_fprintf(2, "{red|ss}Error{eoc}\n");
	else
		ft_fprintf(2, "Error\n");
	return (rtnvalue);
}

int	usage(\
	char *av, char c, int rtnvalue, int o)
{
	if (IS(O_COLOR, o))
	{
		ft_fprintf(2, FMT_CU1, av, "illegal option", c);
		ft_fprintf(2, FMT_CU2, "usage", av, CSET_O, "number ...");
	}
	else
	{
		ft_fprintf(2, FMT_U1, av, "illegal option", c);
		ft_fprintf(2, FMT_U2, "usage", av, CSET_O, "number ...");
	}
	return (rtnvalue);
}
