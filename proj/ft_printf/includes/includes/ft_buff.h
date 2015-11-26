/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 10:45:37 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/25 11:22:40 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFF_H
# define FT_BUFF_H

# include "ft_header.h"

typedef struct	s_buff
{
	int			ret;
	int			fd;
	size_t		buff_size;
	char		*buff;
}				t_buff;

t_buff			*ft_buffnew(int fd, size_t buff_size);
void			ft_buffexp(t_buff **buff, size_t buff_size);
void			ft_buffdel(t_buff **buff);

#endif
