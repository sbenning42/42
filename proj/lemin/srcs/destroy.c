/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 11:57:14 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/21 12:05:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	del_solution(void *content, size_t content_size)
{
	t_sol	*solution;

	solution = (t_sol *)content;
	if (solution->stable)
		free(solution->stable);
	if (solution->queue)
		free(solution->queue);
	(void)content_size;
}

void		destroy_all(t_graph *rooms, t_graph *paths, t_list **solutions)
{
	int		i;

	i = -1;
	while (++i < (int)rooms->size)
	{
		if (rooms->node[i].neig)
			free(rooms->node[i].neig);
		if (ACCESS_ROOM_META(rooms, i)->name)
			free(ACCESS_ROOM_META(rooms, i)->name);
	}
	if (i)
		free(rooms->node);
	i = -1;
	while (++i < (int)paths->size)
	{
		if (paths->node[i].neig)
			free(paths->node[i].neig);
		if (ACCESS_PATH_META(paths, i)->step)
			free(ACCESS_PATH_META(paths, i)->step);
	}
	if (i)
		free(paths->node);
	ft_lstdel(solutions, del_solution);
}
