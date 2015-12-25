/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 05:36:02 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/16 05:42:37 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_buffdel(t_buff **buff)
{
	if (!buff || !*buff)
		return ;
	if ((*buff)->buff)
		ft_memdel((void **)&(*buff)->buff);
	ft_memdel((void **)buff);
}
