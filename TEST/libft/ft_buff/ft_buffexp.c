/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffexp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 02:57:43 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/16 05:35:37 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_buffexp(t_buff **buff, size_t buff_size)
{
	char	buff_cpy[buff_size];

	if (!buff || !*buff)
		return ;
	ft_strcpy(buff_cpy, (*buff)->buff);
	ft_memdel((void **)&((*buff)->buff));
	if (!((*buff)->buff = (char *)malloc(sizeof(char) * buff_size + 1)))
		return ;
	ft_strcpy((*buff)->buff, buff_cpy);
	(*buff)->buff_size = buff_size;
}
