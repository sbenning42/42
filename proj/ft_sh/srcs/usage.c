/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 16:20:02 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/17 18:53:03 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		cd_usage(\
		char invalid)
{
	if (IS(O_COLOR, OPT))
	{
		ft_fprintf(2, FMT_CCDU1, "cd", invalid);
		ft_fprintf(2, FMT_CCDU2, "cd", "L|P", "Directory");
	}
	else
	{
		ft_fprintf(2, FMT_CDU1, "cd", invalid);
		ft_fprintf(2, FMT_CDU2, "cd", "L|P", "Dirctory");
	}
	return (1);
}

void	usage(\
		char invalid)
{
	if (IS(O_COLOR, OPT))
	{
		ft_fprintf(2, FMT_CU1, AV, invalid);
		ft_fprintf(2, FMT_CU2, AV, CSET_O);
	}
	else
	{
		ft_fprintf(2, FMT_U1, AV, invalid);
		ft_fprintf(2, FMT_U2, AV, CSET_O);
	}
	shenv_destroy();
	exit(EXIT_FAILURE);
}
