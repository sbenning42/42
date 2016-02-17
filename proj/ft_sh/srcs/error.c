/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 17:12:14 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/17 15:47:53 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void				exit_error(\
					void)
{
	shenv_destroy();
	exit(EXIT_FAILURE);
}

void				error(\
					t_error_msg_id id, char *msg, int status)
{
	char			*fmt;
	static char		*g_error_msg[FT_SH_ERROR_MSG_SIZE] = {\
		"Allocate memory - (malloc)",\
		"Bufferize input - (read)",\
		"List directory entries - (opendir)",\
		"Create or open regular file - (open)",\
		"Initialize new process - (fork)",\
		"Execute system binary - (execve)",\
		"Change current working directory - (chdir)",\
		"Get current working directory - (getcwd)"};

	if (msg)
	{
		fmt = (IS(O_COLOR, OPT) ? FMT_COL_MSG_ERROR : FMT_STD_MSG_ERROR);
		ft_fprintf(2, fmt, AV, g_error_msg[id], msg, MSG_SYSCALL);
	}
	else
	{
		fmt = (IS(O_COLOR, OPT) ? FMT_COL_ERROR : FMT_STD_ERROR);
		ft_fprintf(2, fmt, AV, g_error_msg[id], MSG_SYSCALL);
	}
	if (status == EXIT_FAILURE)
		exit_error();
}
