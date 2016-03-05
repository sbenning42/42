/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew_empty.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:04:17 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/23 14:06:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst.h"

t_dlist		*ft_dlstnew_empty(size_t content_size)
{
	t_dlist		*new;

	if (!(new = (t_dlist *)ft_memalloc(sizeof(t_dlist))))
		return (NULL);
	new->n = NULL;
	new->p = NULL;
	if (!(new->content = ft_memalloc(content_size)))
	{
		free(new);
		return (NULL);
	}
	new->content_size = content_size;
	return (new);
}
