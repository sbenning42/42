/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_solutions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:54:12 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/20 17:16:36 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		is_stabable(t_graph *paths, t_btrack *backtrack, int testid)
{
	t_list		*drive;
	int			id;
	int			size;
	int			i;

	drive = backtrack->path;
	while (drive)
	{
		id = *(int *)drive->content;
		if (id == testid)
			return (0);
		size = (int)paths->node[id].neig_size;
		i = -1;
		while (++i < size)
		{
			if (testid == paths->node[id].neig[i])
				return (0);
		}
		drive = drive->next;
	}
	return (1);
}

static void		save_stable(t_list **solutions, t_btrack *backtrack)
{
	t_list		*stable;
	t_sol		sol;

	sol.size = lst_size(backtrack->path);
	sol.stable = (int *)ft_memalloc(sizeof(int) * sol.size);
	sol.queue = (int *)ft_memalloc(sizeof(int) * sol.size);
	fill_step(sol.stable, backtrack->path);
	stable = ft_lstnew(&sol, sizeof(t_sol));
	ft_lstadd_back(solutions, stable);
}

static void		get_solutions(t_graph *paths, t_list **solutions,\
								t_btrack *backtrack)
{
	int			i;
	int			flag;

	flag = 0;
	push_step(backtrack);
	i = backtrack->id;
	while (++i < (int)paths->size)
	{
		if (is_stabable(paths, backtrack, i))
		{
			flag = 1;
			backtrack->id = i;
			get_solutions(paths, solutions, backtrack);
		}
	}
	if (!flag)
		save_stable(solutions, backtrack);
	pop_step(backtrack);
}

void			get_solutions_by_backtrack(t_graph *paths, t_list **solutions)
{
	t_btrack	backtrack;
	int			i;

	ft_bzero(&backtrack, sizeof(t_btrack));
	i = -1;
	while (++i < (int)paths->size)
	{
		backtrack.id = i;
		get_solutions(paths, solutions, &backtrack);
	}
}
