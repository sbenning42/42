/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_dump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 11:11:40 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/28 11:13:19 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void		rl_dumpdyn(t_dyn d)
{
	size_t	i;

	i = 0;
	ft_fprintf(2, "\t[%zu][%zu][%zu][%zu]\n", d.real, d.used, d.ante, d.post);
	while (i <= d.real)
	{
		ft_fprintf(2, "[%d]", (int)d.str[i]);
		i++;
	}
	ft_fprintf(2, "\n");
}
