/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 23:55:26 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/17 16:28:31 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int	empty_buffer(\
			char *buffer)
{
	while (*buffer)
	{
		if (!ft_isblank(*buffer))
			return (0);
		buffer++;
	}
	return (1);
}

int			minishell(\
			void)
{
	int		ret;
	char	cmd_buffer[FT_SH_CMD_BUFFER_SIZE + 1];

	ft_bzero((void *)cmd_buffer, sizeof(char) * (FT_SH_CMD_BUFFER_SIZE + 1));
	ft_printf((IS(O_COLOR, OPT) ? FMT_COL_PROMPT : FMT_STD_PROMPT));
	ret = read(0, cmd_buffer, FT_SH_CMD_BUFFER_SIZE);
	if (ret < 0)
	{
		error(Read, NULL, EXIT_FAILURE);
		return (1);
	}
	else if (!ret)
		return (0);
	else if (empty_buffer(cmd_buffer))
		return (1);
	if (cmd_buffer[ret - 1] == '\n')
		cmd_buffer[ret - 1] = 0;
	return (handle_cmd(cmd_buffer));
}
