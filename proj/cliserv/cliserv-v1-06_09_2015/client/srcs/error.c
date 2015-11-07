/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 23:05:04 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/10 02:59:37 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

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
	else
		write(2, M_DEFAULT, ft_strlen(M_DEFAULT));
}

void		err_co(void)
{
	if (errno == EACCES)
		write(2, M_CACCES, ft_strlen(M_CACCES));
	else if (errno == EAFNOSUPPORT)
		write(2, M_CAFNOSUPPORT, ft_strlen(M_CAFNOSUPPORT));
	else if (errno == EADDRINUSE)
		write(2, M_ADDRINUSE, ft_strlen(M_ADDRINUSE));
	else if (errno == EALREADY)
		write(2, M_ALREADY, ft_strlen(M_ALREADY));
	else if (errno == ECONNREFUSED)
		write(2, M_CONNREFUSED, ft_strlen(M_CONNREFUSED));
	else if (errno == EINPROGRESS)
		write(2, M_INPROGRESS, ft_strlen(M_INPROGRESS));
	else if (errno == ETIMEDOUT)
		write(2, M_TIMEDOUT, ft_strlen(M_TIMEDOUT));
	else
		write(2, M_DEFAULT, ft_strlen(M_DEFAULT));
}
