/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:05:55 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/19 19:15:08 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		minishell(void)
{
	char	*line;

	if (!(line = ft_readline("$>", RL_ECHO | RL_HISTORY)))
		ft_exit(EXIT_FAILURE, "No enougth memory");
	ft_printf("%s\n", line);
	free(line);
}
