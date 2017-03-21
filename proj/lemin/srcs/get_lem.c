/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:14:28 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/20 18:15:17 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		have_to_swap(t_lem l1, t_lem l2, t_graph *paths)
{
	size_t		size1;
	size_t		size2;

	if (l1.timer > l2.timer)
		return (1);
	if (l1.timer == l2.timer)
	{
		size1 = ACCESS_PATH_META(paths, l1.id_path)->size;
		size2 = ACCESS_PATH_META(paths, l2.id_path)->size;
		if (size1 > size2)
			return (1);
	}
	return (0);
}

static void		sortlem(t_lem *lem, size_t size, t_graph *paths)
{
	int			finish;
	t_lem		tmp;
	int			i;

	finish = 0;
	while (!finish)
	{
		finish = 1;
		i = -1;
		while (++i < (int)(size - 1))
		{
			if (have_to_swap(lem[i], lem[i + 1], paths))
			{
				finish = 0;
				tmp = lem[i];
				lem[i] = lem[i + 1];
				lem[i + 1] = tmp;
			}
		}
	}
}

static void		fill_lem(t_lem *lem, t_sol *sol)
{
	int			i;
	int			j;
	int			k;

	k = -1;
	i = -1;
	while (++i < (int)sol->size)
	{
		j = -1;
		while (++j < sol->queue[i])
		{
			lem[++k].id_path = sol->stable[i];
			lem[k].timer = j;
			lem[k].stage = 1;
		}
	}
}

t_lem			*get_lem(t_sol *sol, t_cons *rules, t_graph *paths)
{
	t_lem		*lem;

	if (!(lem = (t_lem *)ft_memalloc(sizeof(t_lem) * rules->pop)))
		return (NULL);
	fill_lem(lem, sol);
	sortlem(lem, rules->pop, paths);
	return (lem);
}
