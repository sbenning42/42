/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:17:50 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/20 17:12:05 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

size_t		lst_size(t_list *l)
{
	size_t	size;

	size = 0;
	while (l)
	{
		size++;
		l = l->next;
	}
	return (size);
}

void		fill_step(int *t, t_list *l)
{
	while (l)
	{
		*t = *(int *)l->content;
		l = l->next;
		t++;
	}
}

int			push_step(t_btrack *backtrack)
{
	t_list	*step;

	step = ft_lstnew((void *)&backtrack->id, sizeof(int));
	ft_lstadd(&backtrack->path, step);
	return (0);
}

int			pop_step(t_btrack *backtrack)
{
	t_list	*tmp;

	if (!backtrack->path)
		return (0);
	tmp = backtrack->path->next;
	ft_lstdelone(&backtrack->path, NULL);
	backtrack->path = tmp;
	return (0);
}
