/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_err.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 21:39:55 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/09 23:04:15 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_ERR_H
# define S_ERR_H

# define M_READ "Server: Read: Error not defined\n"
# define M_WRITE "Server: Write: Error not defined\n"
# define M_ACCES "Server: Socket: Permission denied\n"
# define M_AFNOSUPPORT "Server: Socket: Family not supported\n"
# define M_INVAL "Server: Socket: Unknown protocol\n"
# define M_MFILE "Server: Socket: Process file table overflow\n"
# define M_NFILE "Server: Socket: Limit of open files as been reached\n"
# define M_NOMEM "Server: Socket: Insufficient memory\n"
# define M_PROTONOSUPPORT "Server: Socket: Wrong domain within this protocol\n"

#endif
