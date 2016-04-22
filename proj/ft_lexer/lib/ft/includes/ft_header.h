/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:54:10 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/15 12:47:07 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <wchar.h>

# define MAX_UINT 4294967295
# define BS 256

extern char					**g_ftenviron;

typedef unsigned int		t_uint;
typedef unsigned char		t_uchar;
typedef unsigned long int	t_ulong;
typedef unsigned short int	t_ushort;

#endif
