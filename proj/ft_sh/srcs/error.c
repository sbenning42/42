/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 17:12:14 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/16 19:29:51 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	error(\
		void)
{
	shenv_destroy();
	exit(EXIT_FAILURE);
}

void	read_error(\
		void)
{
	ft_fprintf(2, (IS(O_COLOR, OPT) ? FMT_CREAD : FMT_READ), AV, MSG_SYSCALL);
}

void	binary_error(\
		void)
{
	ft_fprintf(2, (IS(O_COLOR, OPT) ? FMT_CMEM : FMT_MEM), AV, MSG_SYSCALL);
	error();
}

void	malloc_error(\
		void)
{
	ft_fprintf(2, (IS(O_COLOR, OPT) ? FMT_CMEM : FMT_MEM), AV, MSG_SYSCALL);
	error();
}

void	opendir_error(\
		char *path)
{
	ft_fprintf(2, (IS(O_COLOR, OPT) ? FMT_COPEN : FMT_OPEN),\
			AV, path, MSG_SYSCALL);
}

void	exec_error(\
		char *path)
{
	ft_fprintf(2, (IS(O_COLOR, OPT) ? FMT_CEXEC : FMT_EXEC),\
			AV, path, MSG_SYSCALL);
}

void	fork_error(\
		void)
{
	ft_fprintf(2, (IS(O_COLOR, OPT) ? FMT_CFORK : FMT_FORK), AV, MSG_SYSCALL);
}
