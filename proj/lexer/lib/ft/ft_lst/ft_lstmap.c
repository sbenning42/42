/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 14:49:22 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/18 16:06:33 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*alst;

	new = NULL;
	alst = new;
	while (lst)
	{
		if (f)
			new = f(lst);
		ft_lstadd_back(&alst, new);
		lst = lst->next;
	}
	return (alst);
}
