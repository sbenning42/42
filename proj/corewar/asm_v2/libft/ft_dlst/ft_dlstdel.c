/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 15:10:01 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/14 15:11:22 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst.h"

void		ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist	*cp;

	while (*alst)
	{
		cp = (*alst)->n;
		ft_dlstdelone(alst, del);
		*alst = cp;
	}
}
