/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_err.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 23:02:51 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/10 05:09:05 by sbenning         ###   ########.fr       */
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
# define M_CACCES "Client: Connect: Permission denied\n"
# define M_CAFNOSUPPORT "Client: Connect: Family not supported\n"
# define M_ADDRINUSE "Client: Connect: Local address is already in use\n"
# define M_ALREADY "Client: Connect: Co attent has not yet been completed\n"
# define M_CONNREFUSED "Client: Connect: Not listening on the remote address\n"
# define M_INPROGRESS "Client: Connect: Connection cannot be completed\n"
# define M_TIMEDOUT "Client: Connect: Time out on connection\n"

#endif
