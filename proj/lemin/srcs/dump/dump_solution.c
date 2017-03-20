/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:54:22 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/20 17:14:44 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	dump_stable(t_sol *s)
{
	int		i;

	i = -1;
	while (++i < (int)s->size)
	{
		ft_printf(LEM_SOLUTION_STABLE_FMT,\
			s->stable[i], (i + 1 == (int)s->size ? ']' : ','));
	}
	if (!i)
		ft_printf("{gr}]{eoc}");
}

static void	dump_queue(t_sol *s)
{
	int		i;

	i = -1;
	ft_printf("\t{gr}[{eoc}");
	while (++i < (int)s->size)
	{
		ft_printf(LEM_SOLUTION_QUEUE_FMT,\
				s->queue[i], (i + 1 == (int)s->size ? ']' : ','));
	}
	if (!i)
		ft_printf("{gr}]{eoc}");
}

void		dump_solutions(t_list *l)
{
	t_sol	*s;
	int		best;
	int		best_id;
	int		j;

	best = INT_MAX;
	best_id = -1;
	j = 0;
	while (l)
	{
		s = (t_sol *)l->content;
		ft_printf(LEM_SOLUTION_DUMP_FMT, ++j);
		dump_stable(s);
		dump_queue(s);
		ft_printf(LEM_SOLUTION_SPEED_FMT, s->timer);
		if (best > s->timer)
		{
			best = s->timer;
			best_id = j;
		}
		l = l->next;
	}
	ft_printf(LEM_BEST_SOLUTION_FMT, best_id, best);
}
