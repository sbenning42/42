/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_err.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 23:02:51 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/11 13:51:36 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_ERR_H
# define C_ERR_H

# define M_DEFAULT "Client: Errno not used\n"
# define M_READ "Client: Read: Error not defined\n"
# define M_WRITE "Client: Write: Error not defined\n"
# define M_ACCES "Client: Socket: Permission denied\n"
# define M_AFNOSUPPORT "Client: Socket: Family not supported\n"
# define M_INVAL "Client: Socket: Unknown protocol\n"
# define M_MFILE "Client: Socket: Process file table overflow\n"
# define M_NFILE "Client: Socket: Limit of open files as been reached\n"
# define M_NOMEM "Client: Socket: Insufficient memory\n"
# define M_PROTONOSUPPORT "Client: Socket: Wrong domain within this protocol\n"

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

# define M_CACCES "Client: Connect: Permission denied\n"
# define M_CAFNOSUPPORT "Client: Connect: Family not supported\n"
# define M_ADDRINUSE "Client: Connect: Local address is already in use\n"
# define M_ALREADY "Client: Connect: Co attent has not yet been completed\n"
# define M_CONNREFUSED "Client: Connect: Not listening on the remote address\n"
# define M_INPROGRESS "Client: Connect: Connection cannot be completed\n"
# define M_TIMEDOUT "Client: Connect: Time out on connection\n"

#endif
