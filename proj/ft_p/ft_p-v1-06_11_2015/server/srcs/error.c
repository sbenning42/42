/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 21:31:42 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/11 03:50:06 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		err_sock(void)
{
	if (errno == EACCES)
		write(2, MS_ACCES, ft_strlen(MS_ACCES));
	else if (errno == EAFNOSUPPORT)
		write(2, MS_AFNOSUPPORT, ft_strlen(MS_AFNOSUPPORT));
	else if (errno == EINVAL)
		write(2, MS_INVAL, ft_strlen(MS_INVAL));
	else if (errno == EMFILE)
		write(2, MS_MFILE, ft_strlen(MS_MFILE));
	else if (errno == ENFILE)
		write(2, MS_NFILE, ft_strlen(MS_NFILE));
	else if (errno == ENOMEM || errno == ENOBUFS)
		write(2, MS_NOMEM, ft_strlen(MS_NOMEM));
	else if (errno == EPROTONOSUPPORT)
		write(2, MS_PROTONOSUPPORT, ft_strlen(MS_PROTONOSUPPORT));
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

void		err_listen(void)
{
	if (errno == EACCES)
		write(2, ML_ACCES, ft_strlen(ML_ACCES));
	else if (errno == EBADF)
		write(2, ML_BADF, ft_strlen(ML_BADF));
	else if (errno == EDESTADDRREQ)
		write(2, ML_DESTADDRREQ, ft_strlen(ML_DESTADDRREQ));
	else if (errno == EINVAL)
		write(2, ML_INVAL, ft_strlen(ML_INVAL));
	else if (errno == ENOTSOCK)
		write(2, ML_NOTSOCK, ft_strlen(ML_NOTSOCK));
	else if (errno == EOPNOTSUPP)
		write(2, ML_OPNOTSUPP, ft_strlen(ML_OPNOTSUPP));
	exit(0);
}

void		err_accept(void)
{
	if (errno == EBADF)
		write (2, MA_BADF, ft_strlen(MA_BADF));
	else if (errno == ECONNABORTED)
		write (2, MA_CONNABORTED, ft_strlen(MA_CONNABORTED));
	else if (errno == EFAULT)
		write (2, MA_FAULT, ft_strlen(MA_FAULT));
	else if (errno == EINTR)
		write (2, MA_INTR, ft_strlen(MA_INTR));
	else if (errno == EINVAL)
		write (2, MA_INVAL, ft_strlen(MA_INVAL));
	else if (errno == EMFILE)
		write (2, MA_MFILE, ft_strlen(MA_MFILE));
	else if (errno == ENFILE)
		write (2, MA_NFILE, ft_strlen(MA_NFILE));
	else if (errno == ENOMEM)
		write (2, MA_NOMEM, ft_strlen(MA_NOMEM));
	else if (errno == ENOTSOCK)
		write (2, MA_NOTSOCK, ft_strlen(MA_NOTSOCK));
	else if (errno == EOPNOTSUPP)
		write (2, MA_OPNOTSUPP, ft_strlen(MA_OPNOTSUPP));
	else if (errno == EWOULDBLOCK)
		write (2, MA_WOULDBLOCK, ft_strlen(MA_WOULDBLOCK));
}
