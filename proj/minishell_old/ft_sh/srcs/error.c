/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 17:12:14 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/18 15:06:18 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static char		*g_error_msg[FT_SH_ERROR_MSG_SIZE] = {\
	"Allocate memory - (malloc syscall)",\
	"Bufferize input - (read syscall)",\
	"List directory entries - (opendir syscall)",\
	"Create or open regular file - (open syscall)",\
	"Initialize new process - (fork syscall)",\
	"Execute system binary - (execve syscall)",\
	"Change current working directory - (chdir syscall)",\
	"Get current working directory - (getcwd syscall)",\
	"No PATH in environ. Autofix with old value - (Environ corruption)",\
	"No PATH in environ. Fix it to launch binary - (Environ corruption)",\
	"No PWD in environ. Autofix with getcwd() - (Environ corruption)",\
	"No OLDPWD in environ. Autofix with PWD value - (Environ corruption)",\
	"No HOME in environ. Fix it to get '~' abreviation - (Environ corruption)",\
	"Path not found - (access syscall)",\
	"Permission denied - (access syscall)",\
	"Get file info - (stat syscall)",\
	"Not a directory - (stat syscall)",\
	"Too many argument",\
	"Unknow error type..."};

void				exit_error(\
					void)
{
	shenv_destroy();
	exit(EXIT_FAILURE);
}

char				cd_error(\
					t_error_msg_id id, char *msg, int status)
{
	char			*fmt;

	if (msg)
	{
		fmt = (IS(O_COLOR, OPT) ? FMT_COL_MSG_ERROR : FMT_STD_MSG_ERROR);
		ft_fprintf(2, fmt, "cd", g_error_msg[id], msg, MSG_SYSCALL);
	}
	else
	{
		fmt = (IS(O_COLOR, OPT) ? FMT_COL_ERROR : FMT_STD_ERROR);
		ft_fprintf(2, fmt, "cd", g_error_msg[id], MSG_SYSCALL);
	}
	if (status == EXIT_FAILURE)
		exit_error();
	return (0);
}

void				error(\
					t_error_msg_id id, char *msg, int status)
{
	char			*fmt;

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
