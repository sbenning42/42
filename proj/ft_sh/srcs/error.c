/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 17:12:14 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/15 10:54:19 by sbenning         ###   ########.fr       */
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
	error();
}

void	binary_error(\
		void)
{
	ft_fprintf(2, (IS(O_COLOR, OPT) ? FMT_CMEM : FMT_MEM), AV, MSG_SYSCALL);
	error();
}
