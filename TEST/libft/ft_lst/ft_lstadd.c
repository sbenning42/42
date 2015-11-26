/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 14:45:38 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/15 21:04:04 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void		ft_lstadd(t_list **alst, t_list *elem)
{
	if (!elem)
		return ;
	elem->next = *alst;
	*alst = elem;
}
