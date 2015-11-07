/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 23:05:04 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/11 13:51:35 by sbenning         ###   ########.fr       */
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
	exit(0);
}

void		err_bind(void)
{
	if (errno == EACCES)
		write(2, MB_ACCES, ft_strlen(MB_ACCES));
	else if (errno == EADDRINUSE)
		write(2, MB_ADDRINUSE, ft_strlen(MB_ADDRINUSE));
	else if (errno == EADDRNOTAVAIL)
		write(2, MB_ADDRNOTAVAIL, ft_strlen(MB_ADDRNOTAVAIL));
	else if (errno == EAFNOSUPPORT)
		write(2, MB_AFNOSUPPORT, ft_strlen(MB_AFNOSUPPORT));
	else if (errno == EBADF)
		write(2, MB_BADF, ft_strlen(MB_BADF));
	else if (errno == EDESTADDRREQ)
		write(2, MB_DESTADDRREQ, ft_strlen(MB_DESTADDRREQ));
	else if (errno == EFAULT)
		write(2, MB_FAULT, ft_strlen(MB_FAULT));
	else if (errno == EINVAL)
		write(2, MB_INVAL, ft_strlen(MB_INVAL));
	else if (errno == ENOTSOCK)
		write(2, MB_NOTSOCK, ft_strlen(MB_NOTSOCK));
	else if (errno == EOPNOTSUPP)
		write(2, MB_OPNOTSUPP, ft_strlen(MB_OPNOTSUPP));
	else if (errno == EEXIST)
		write(2, MB_EXIST, ft_strlen(MB_EXIST));
	else if (errno == EIO)
		write(2, MB_IO, ft_strlen(MB_IO));
	else if (errno == EISDIR)
		write(2, MB_ISDIR, ft_strlen(MB_ISDIR));
	else if (errno == ELOOP)
		write(2, MB_LOOP, ft_strlen(MB_LOOP));
	else if (errno == ENAMETOOLONG)
		write(2, MB_NAMETOOLONG, ft_strlen(MB_NAMETOOLONG));
	else if (errno == ENOENT)
		write(2, MB_NOENT, ft_strlen(MB_NOENT));
	else if (errno == ENOTDIR)
		write(2, MB_NOTDIR, ft_strlen(MB_NOTDIR));
	else if (errno == EROFS)
		write(2, MB_ROFS, ft_strlen(MB_ROFS));
	exit(0);
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
	exit(0);
}
