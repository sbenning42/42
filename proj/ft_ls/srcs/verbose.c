/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:15:33 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/14 16:01:50 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*g_o_str[SIZE_O + 1] = {"Illegal",\
									"Hide",\
									"Long",\
									"Recursif",\
									"Reverse",\
									"Time",\
									"Verbose"};

void		verbose_get_opt(int o, char *av)
{
	int		i;
	int		flag;

	ft_printf(FMT_VERBOSE, ft_name(av), "verbose", "option(s)");
	i = 0;
	flag = 0x1;
	while (flag < O_MAX)
	{
		if (((o & flag) == flag) && (flag != O_PRIVATE_ERROR))
			ft_printf("[{cyan|gr}%s{eoc}] ", g_o_str[i]);
		else if (((o & flag) == flag) && (flag == O_PRIVATE_ERROR))
			ft_printf("[{red|gr|ss}%s{eoc}] ", g_o_str[i]);
		i++;
		flag <<= 0x1;
	}
	ft_printf("\n");
}

void		verbose_get_sort(int (*s)(void *, void *), char *av)
{
	ft_printf(FMT_VERBOSE, ft_name(av), "verbose", "sort function");
	if (s == s_lex)
		ft_printf("[{cyan|gr}%s{eoc}]\n", "Lexical sort");
	else if (s == s_rlex)
		ft_printf("[{cyan|gr}%s{eoc}]\n", "Reverse lexical sort");
	else if (s == s_time)
		ft_printf("[{cyan|gr}%s{eoc}]\n", "Last modified sort");
	else if (s == s_rtime)
		ft_printf("[{cyan|gr}%s{eoc}]\n", "First modified sort");
}
