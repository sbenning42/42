/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 23:55:26 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/16 19:30:15 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			minishell(\
			void)
{
	int		ret;
	char	cmd_buffer[FT_SH_CMD_BUFFER_SIZE + 1];

	ft_bzero((void *)cmd_buffer, sizeof(char) * (FT_SH_CMD_BUFFER_SIZE + 1));
	ft_printf((IS(O_COLOR, OPT) ? FMT_CPROMPT : FMT_PROMPT));
	ret = read(0, cmd_buffer, FT_SH_CMD_BUFFER_SIZE);
	if (ret < 0)
	{
		read_error();
		return (1);
	}
	else if (!ret)
		return (0);
	else if (cmd_buffer[0] == '\n')
		return (1);
	cmd_buffer[ret - 1] = 0;
	if (IS(O_DEBUG, OPT))
		put_cmd_buffer(cmd_buffer, ret);
	return (handle_cmd(cmd_buffer, ret));
}
