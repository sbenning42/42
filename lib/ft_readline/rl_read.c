/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:27:54 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/19 18:35:34 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_read(void)
{
	char	buffer[RL_INPUTSIZE + 1];

	ft_bzero((void *)buffer, RL_INPUTSIZE + 1);
	read(0, buffer, RL_INPUTSIZE);
	return (*(int *)buffer);
}
