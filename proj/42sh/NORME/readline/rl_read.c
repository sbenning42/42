/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:27:54 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 12:33:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

long int		rl_read(void)
{
	long int	buffer;

	buffer = 0;
	read(0, (char *)&buffer, sizeof(buffer));
	return (buffer);
}
