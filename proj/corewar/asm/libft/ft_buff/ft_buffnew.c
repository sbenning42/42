/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 02:46:03 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/16 17:02:11 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_buff		*ft_buffnew(int fd, size_t buff_size)
{
	t_buff		*new;

	if (!(new = (t_buff *)malloc(sizeof(t_buff))))
		return (NULL);
	new->ret = 0;
	new->fd = fd;
	new->buff_size = buff_size;
	if (!(new->buff = ft_strnew(buff_size)))
	{
		ft_memdel((void **)&new);
		return (NULL);
	}
	return (new);
}
