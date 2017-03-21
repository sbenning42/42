/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:56:46 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/21 09:06:31 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		apply_queue_on_solution(t_graph *paths, t_sol *sol)
{
	int			i;
	int			best;
	int			best_id;
	int			speed;

	i = -1;
	best = INT_MAX;
	best_id = 0;
	while (++i < (int)sol->size)
	{
		speed = ACCESS_PATH_META(paths, sol->stable[i])->size + sol->queue[i];
		if (best > speed)
		{
			best = speed;
			best_id = i;
		}
	}
	sol->queue[best_id] += 1;
}

static void		get_queue_switch_solution(t_graph *paths, t_list *solutions,\
											t_cons *rules)
{
	int			i;
	t_list		*tmp;
	t_sol		*sol;

	i = -1;
	while (++i < rules->pop)
	{
		tmp = solutions;
		while (tmp)
		{
			sol = (t_sol *)tmp->content;
			apply_queue_on_solution(paths, sol);
			tmp = tmp->next;
		}
	}
}

static void		get_timer_switch_solution(t_graph *paths, t_list *solutions)
{
	t_sol		*sol;
	int			i;
	int			timer;

	while (solutions)
	{
		sol = (t_sol *)solutions->content;
		sol->timer = INT_MIN;
		i = -1;
		while (++i < (int)sol->size)
		{
			if (!sol->queue[i])
				continue ;
			timer = (ACCESS_PATH_META(paths, sol->stable[i])->size - 1)\
					+ (sol->queue[i] - 1);
			if (sol->timer < timer)
				sol->timer = timer;
		}
		solutions = solutions->next;
	}
}

int				resolve(t_graph *rooms, t_graph *paths,\
						t_cons *rules, t_list **solutions)
{
	if (is_in_neig(rooms, rules->id_s, rules->id_e))
	{
		rules->lucky = 1;
		return (0);
	}
	get_paths_by_backtrack(rooms, paths, rules);
	if (!paths->size)
	{
		if (PI_ISOPT(proginfo()->opt, O_VERB))
		{
			ft_fprintf(2, LEM_NOPATH_FMT, proginfo()->name,\
					ACCESS_ROOM_META(rooms, rules->id_s)->name,\
					ACCESS_ROOM_META(rooms, rules->id_e)->name);
		}
		return (-1);
	}
	get_solutions_by_backtrack(paths, solutions);
	get_queue_switch_solution(paths, *solutions, rules);
	get_timer_switch_solution(paths, *solutions);
	return (0);
}
