/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 16:15:36 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/15 16:38:53 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst.h"

t_dlist		*ft_dlstmap(t_dlist *lst, t_dlist *(*f)(t_dlist *elem))
{
	t_dlist		*new;
	t_dlist		*alst;

	new = NULL;
	alst = new;
	while (lst)
	{
		if (f)
			new = f(lst);
		else
			new = ft_dlstnew(lst->content, lst->content_size);
		if (!new)
		{
			ft_dlstdel(&alst, NULL);
			return (NULL);
		}
		ft_dlstaddn(&alst, new);
		lst = lst->n;
	}
	return (alst);
}
