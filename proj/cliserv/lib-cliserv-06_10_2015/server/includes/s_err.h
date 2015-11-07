/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_err.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 21:39:55 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/10 17:14:42 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_ERR_H
# define S_ERR_H

# include <errno.h>
# include <signal.h>

# define M_READ				"Server: Read: Error not defined\n"

# define M_WRITE			"Server: Write: Error not defined\n"

# define MS_ACCES			"Server: Socket: Permission denied\n"
# define MS_AFNOSUPPORT		"Server: Socket: Family not supported\n"
# define MS_INVAL			"Server: Socket: Unknown protocol\n"
# define MS_MFILE			"Server: Socket: Process file table overflow\n"
# define MS_NFILE			"Server: Socket: Limit of open files as been reached\n"
# define MS_NOMEM			"Server: Socket: Insufficient memory\n"
# define MS_PROTONOSUPPORT	"Server: Socket: Wrong domain within this protocol\n"

# define MB_ACCES			"Server: Bind: The requested address is protected, and the current user has inadequate permission to access it.\n"
# define MB_ADDRINUSE		"Server: Bind: The specified address is already in use.\n"
# define MB_ADDRNOTAVAIL	"Server: Bind: The specified address is not available from the local machine.\n"
# define MB_AFNOSUPPORT		"Server: Bind: address is not valid for the address family of socket.\n"
# define MB_BADF			"Server: Bind: socket is not a valid file descriptor.\n"
# define MB_DESTADDRREQ		"Server: Bind: socket is a null pointer.\n"
# define MB_FAULT			"Server: Bind: The address parameter is not in a valid part of the user address space.\n"
# define MB_INVAL			"Server: Bind: socket is already bound to an address. Alternatively, socket may have been shut down.\n"
# define MB_NOTSOCK			"Server: Bind: socket does not refer to a socket.\n"
# define MB_OPNOTSUPP		"Server: Bind: socket is not of a type that can be bound to an address.\n"
# define MB_EXIST			"Server: Bind: A file already exists at the pathname.  unlink(2) it first.\n"
# define MB_IO				"Server: Bind: An I/O error occurred while making the directory entry or allocating the inode.\n"
# define MB_ISDIR			"Server: Bind: An empty pathname was specified.\n"
# define MB_LOOP			"Server: Bind: Too many symbolic links were encountered in translating the pathname. This is taken to be indicative of a looping symbolic link.\n"
# define MB_NAMETOOLONG		"Server: Bind: A component of a pathname exceeded {NAME_MAX} characters, or an entire path name exceeded {PATH_MAX} characters.\n"
# define MB_NOENT			"Server: Bind: A component of the path name does not refer to an existing file.\n"
# define MB_NOTDIR			"Server: Bind: A component of the path prefix is not a directory.\n"
# define MB_ROFS			"Server: Bind: The name would reside in read-only file system.\n"

# define ML_ACCES			"Server: Listen: The current process has insufficient privileges.\n"
# define ML_BADF			"Server: Listen: The argument socket is not a valid file descriptor.\n"
# define ML_DESTADDRREQ		"Server: Listen: The socket is not bound to a local address and the protocol does not support listening on an unbound socket.\n"
# define ML_INVAL			"Server: Listen: socket is already connected.\n"
# define ML_NOTSOCK			"Server: Listen: The argument socket does not reference a socket.\n"
# define ML_OPNOTSUPP		"Server: Listen: The socket is not of a type that supports the operation listen().\n"

# define MA_BADF			"Server: Accept: socket is not a valid file descriptor.\n"
# define MA_CONNABORTED		"Server: Accept: The connection to socket has been aborted.\n"
# define MA_FAULT			"Server: Accept: The address parameter is not in a writable part of the user address space.\n"
# define MA_INTR			"Server: Accept: The accept() system call was terminated by a signal.\n"
# define MA_INVAL			"Server: Accept: socket is unwilling to accept connections.\n"
# define MA_MFILE			"Server: Accept: The per-process descriptor table is full.\n"
# define MA_NFILE			"Server: Accept: The system file table is full.\n"
# define MA_NOMEM			"Server: Accept: Insufficient memory was available to complete the operation.\n"
# define MA_NOTSOCK			"Server: Accept: socket references a file type other than a socket.\n"
# define MA_OPNOTSUPP		"Server: Accept: socket is not of type SOCK_STREAM and thus does not accept connections.\n"
# define MA_WOULDBLOCK		"Server: Accept: socket is marked as non-blocking and no connections are present to be accepted.\n"

void						err_sock(void);
void						err_bind(void);
void						err_listen(void);
void						err_accept(void);

#endif
