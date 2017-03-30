/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:03:19 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/30 18:00:42 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		open_error(char *file)
{
	ft_fprintf(2, error_fmt(), proginfo()->name, file, strerror(errno));
	errno = 0;
}

void		read_error(char *file)
{
	ft_fprintf(2, error_fmt(), proginfo()->name, file, strerror(errno));
	errno = 0;
}

void		compile_error(char *file)
{
	ft_fprintf(2, error_fmt(), proginfo()->name, file, "Can't compile");
}
