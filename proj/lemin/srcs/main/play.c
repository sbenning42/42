/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:56:58 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/20 20:25:14 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		run_step(t_graph *paths, t_graph *rooms, int pop, t_lem *lem)
{
	int			i;
	int			id_room;
	int			finish;

	i = -1;
	finish = 1;
	while (++i < pop)
	{
		if (lem[i].timer > 0 || lem[i].timer < 0)
		{
			lem[i].timer -= 1;
			continue ;
		}
		if (!finish)
			ft_printf(" ");
		finish = 0;
		id_room = ACCESS_PATH_META(paths, lem[i].id_path)->step[lem[i].stage];
		ft_printf("L%d-%s", i + 1, ACCESS_ROOM_META(rooms, id_room)->name);
		lem[i].stage += 1;
		if (lem[i].stage == (int)ACCESS_PATH_META(paths, lem[i].id_path)->size)
			lem[i].timer = -1;
	}
	if (!finish)
		ft_printf("\n");
	return (finish);
}

static int		play_solution(t_cons *rules, t_graph *paths,\
								t_graph *rooms, t_sol *sol)
{
	t_lem		*lem;

	if (!(lem = get_lem(sol, rules, paths)))
		return (-1);
	while (!run_step(paths, rooms, rules->pop, lem))
		;
	return (0);
}

static void		print_lucky(t_graph *rooms, t_cons *rules)
{
	int			i;
	char		*name;

	name = ACCESS_ROOM_META(rooms, rules->id_e)->name;
	i = -1;
	if (PI_ISOPT(proginfo()->opt, O_COUNT))
		ft_printf("Resolvable in 1 step\n");
	while (++i < rules->pop)
		ft_printf("L%d-%s%c", i + 1, name, (i + 1 == rules->pop ? '\n' : ' '));
}

int				play(t_graph *rooms, t_graph *paths,\
					t_cons *rules, t_list **solutions)
{
	t_sol		*sol;
	t_list		*tmp;
	int			best;

	if (rules->lucky)
	{
		print_lucky(rooms, rules);
		return (0);
	}
	best = INT_MAX;
	tmp = *solutions;
	while (tmp)
	{
		if (best > ((t_sol *)tmp->content)->timer)
		{
			sol = (t_sol *)tmp->content;
			best = sol->timer;
		}
		tmp = tmp->next;
	}
	if (PI_ISOPT(proginfo()->opt, O_COUNT))
		ft_printf("Resolvable in %d steps\n", best);
	play_solution(rules, paths, rooms, sol);
	return (0);
}
