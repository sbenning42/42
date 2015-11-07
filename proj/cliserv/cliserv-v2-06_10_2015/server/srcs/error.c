/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 21:31:42 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/10 04:57:10 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		err_sock(void)
{
	if (errno == EACCES)
		write(2, M_ACCES, ft_strlen(M_ACCES));
	else if (errno == EAFNOSUPPORT)
		write(2, M_AFNOSUPPORT, ft_strlen(M_AFNOSUPPORT));
	else if (errno == EINVAL)
		write(2, M_INVAL, ft_strlen(M_INVAL));
	else if (errno == EMFILE)
		write(2, M_MFILE, ft_strlen(M_MFILE));
	else if (errno == ENFILE)
		write(2, M_NFILE, ft_strlen(M_NFILE));
	else if (errno == ENOMEM || errno == ENOBUFS)
		write(2, M_NOMEM, ft_strlen(M_NOMEM));
	else if (errno == EPROTONOSUPPORT)
		write(2, M_PROTONOSUPPORT, ft_strlen(M_PROTONOSUPPORT));
	exit(0);
}
