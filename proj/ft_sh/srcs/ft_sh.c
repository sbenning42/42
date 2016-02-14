/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 23:55:26 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/14 18:16:49 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			minishell\
				(void)
{
	int		ret;
	char	cmd_buffer[FT_SH_CMD_BUFFER_SIZE + 1];

	ft_bzero((void *)cmd_buffer, sizeof(char) * (FT_SH_CMD_BUFFER_SIZE + 1));
	ret = read(0, cmd_buffer, FT_SH_CMD_BUFFER_SIZE);
	if (ret < 0)
		read_error();
	else if (!ret)
		return (0);
	cmd_buffer[ret] = 0;
	if (IS(O_DEBUG, OPT))
		put_cmd_buffer(cmd_buffer, ret);
	return (handle_cmd(cmd_buffer, ret));
}
