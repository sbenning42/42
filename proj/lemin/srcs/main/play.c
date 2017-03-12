/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:56:58 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/09 15:05:19 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

typedef struct s_lem t_lem;

struct s_lem
{
	int	id_path;
	int	timer;
	int	stage;
};

void	play_solution(t_cons *rules, t_graph *paths, t_graph *rooms, t_sol *sol)
{
	t_lem	*lem;
	int	i;
	int	j;
	int	k;
	int	finish;

	lem = (t_lem *)ft_memalloc(sizeof(t_lem) * rules->pop);
	i = -1;
	k = -1;
	while (++i < sol->size)
	{
		j = -1;
		while (++j < sol->queue[i])
		{
			lem[++k].id_path = sol->stable[i];
			lem[k].timer = j;
			lem[k].stage = 1;
		}
	}
	finish = 0;
	while (!finish)
	{
		finish = 1;
		i = -1;
		while (++i < rules->pop)
		{
			if (lem[i].timer == 0)
			{
				if (!finish)
					ft_printf(" ");
				finish = 0;
				ft_printf("L%d-%s", i, ((t_room *)rooms->node[((t_path *)paths->node[lem[i].id_path].meta)->step[lem[i].stage]].meta)->name);
				lem[i].stage += 1;
				if (lem[i].stage == ((t_path *)paths->node[lem[i].id_path].meta)->size)
					lem[i].timer = -1;
			}
			else if (lem[i].timer > 0)
				lem[i].timer -= 1;
		}
		ft_printf("\n");
	}
}

int	play(t_graph *rooms, t_graph *paths, t_cons *rules, t_list **solutions)
{
	t_sol	*sol;
	t_list	*tmp;
	int	best;

	if (rules->id_s < 0 || rules->id_e < 0 || paths->size < 1)
		return (-1);
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
	play_solution(rules, paths, rooms, sol);
	return (0);
	(void)rooms;
	(void)paths;
	(void)rules;
	(void)solutions;
}
