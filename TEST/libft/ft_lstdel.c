/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 14:39:54 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/16 21:31:39 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*drive;

	if (!alst || !*alst)
		return ;
	drive = *alst;
	while (drive)
	{
		ft_lstdelone(&drive, del);
		*alst = (*alst)->next;
		drive = (*alst);
	}
}
