/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftio_perform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 02:20:05 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/17 08:53:16 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio.h"

void	ftio_perform(long int input)
{
	if (input == 4)
		ft_printf("");
	else if (input == 12)
		ft_printf("\033[H\033[2J");
	else if (input == 127)
		ft_printf("");
	else if (input == 27)
		ft_printf("");
	else if (input == 2117294875)
		ft_printf("");
	else if (input == 4283163)
		ft_printf("");
	else if (input == 4348699)
		ft_printf("");
	else if (input == 4479771)
		ft_printf("\033[D");
	else if (input == 4414235)
		ft_printf("\033[C");
}
