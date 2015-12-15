/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:15:33 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/15 15:50:36 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*g_o_str[SIZE_O + 1] = {"Illegal",\
									"Hide",\
									"Long",\
									"Recursif",\
									"Reverse",\
									"Time",\
									"Verbose",\
									"Colorized"};

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

void		verbose_get_avsort(int (*s)(t_node *, t_node *), char *av)
{
	ft_printf(FMT_VERBOSE, ft_name(av), "verbose", "arg_v sort function");
	if (s == avs_lex)
		ft_printf("[{cyan|gr}%s{eoc}]\n", "Lexical sort");
	else if (s == avs_rlex)
		ft_printf("[{cyan|gr}%s{eoc}]\n", "Reverse lexical sort");
	else if (s == avs_time)
		ft_printf("[{cyan|gr}%s{eoc}]\n", "Last modified sort");
	else if (s == avs_rtime)
		ft_printf("[{cyan|gr}%s{eoc}]\n", "First modified sort");
}

void		verbose_get_avprint(void (*p)(t_node *), char *av)
{
	ft_printf(FMT_VERBOSE, ft_name(av), "verbose", "arg_v print function");
	if (p == avp_print)
		ft_printf("[{cyan|gr}%s{eoc}]\n", "Basic print");
	else if (p == avp_cprint)
		ft_printf("[{cyan|gr}%s{eoc}]\n", "Colrized basic print");
	else if (p == avp_lprint)
		ft_printf("[{cyan|gr}%s{eoc}]\n", "Long print");
	else if (p == avp_clprint)
		ft_printf("[{cyan|gr}%s{eoc}]\n", "Colorized long print");
}
