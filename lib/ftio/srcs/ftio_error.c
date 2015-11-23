/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftio_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 13:02:16 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/19 21:10:50 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio.h"

void	ftio_error_handle(void)
{
	int	error;

	ftio_reset(ftio_env()->fd);
	error = errno;
	if (error == EBADF)
		ft_putendl_fd("ftio_Error: Not valid fd", 2);
	else if (error == EINVAL || error == ENOTTY)
		ft_putendl_fd("ftio_error: Not valid term fd", 2);
	else
		ft_putendl_fd("ftio_Error: Unknow", 2);
	exit(EXIT_FAILURE);
}
