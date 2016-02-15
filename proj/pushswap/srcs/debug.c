/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 15:34:34 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/15 10:19:23 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	o_name(\
			int o)
{
	if (o == O_COLOR)
		ft_printf("Color");
	else if (o == O_VERB)
		ft_printf("Verbeux");
	else if (o == O_FIN)
		ft_printf("Final stack state");
	else if (o == O_DEBUG)
		ft_printf("Debug");
	else if (o == O_PRIVATE_ERROR)
		ft_printf("Illegal option");
}

static void	o_cname(\
			int o)
{
	if (o == O_COLOR)
		ft_printf("{cyan|gr}Color{eoc}");
	else if (o == O_VERB)
		ft_printf("{cyan|gr}Verbeux{eoc}");
	else if (o == O_FIN)
		ft_printf("{cyan|gr}Final stack state{eoc}");
	else if (o == O_DEBUG)
		ft_printf("{pink|gr}Debug{eoc}");
	else if (o == O_PRIVATE_ERROR)
		ft_printf("{red|gr}Illegal option{eoc}");
}

void		debug_o(\
			int o)
{
	int		cp;

	if (!o)
		return ;
	cp = 0x1;
	if (IS(O_COLOR, o))
		ft_printf("{yellow|ss}Option:{eoc} [");
	else
		ft_printf("Option: [");
	while (cp <= O_PRIVATE_ERROR)
	{
		if (IS(cp, o))
		{
			if (IS(O_COLOR, o))
				o_cname(cp);
			else
				o_name(cp);
		}
		if (cp != O_PRIVATE_ERROR)
			ft_printf(" | ");
		cp <<= 0x1;
	}
	ft_printf("]\n\n");
}

void		debug_split(\
			void)
{
	ft_printf("------------------------------------------------------------\n");
}

void		debug(\
			t_dlist *l, char *name, int o)
{
	t_dlist	*tmp;
	int		i;

	i = 0;
	tmp = l;
	if (IS(O_COLOR, o))
		ft_printf("{yellow}LIST{eoc} %s:\n", name);
	else
		ft_printf("LIST %s:\n", name);
	while (tmp)
	{
		if (IS(O_COLOR, o))
			ft_printf("{yellow}Elelm{eoc} %d: [%d]\n", \
					i++, *(int *)tmp->content);
		else
			ft_printf("Elelm %d: [%d]\n", i++, *(int *)tmp->content);
		tmp = tmp->n;
	}
	ft_printf("\n");
}
