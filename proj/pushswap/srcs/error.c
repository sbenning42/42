/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 11:23:22 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/12 12:12:05 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ps_error(int rtnvalue)
{
	if (IS(O_COLOR, *opt()))
		ft_fprintf(2, "{red|ss}Error{eoc}\n");
	else
		ft_fprintf(2, "Error\n");
	return (rtnvalue);
}

int	ps_usage(char *av, char c, int rtnvalue)
{
	if (IS(O_COLOR, *opt()))
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
