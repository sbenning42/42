/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:45:30 by sbenning          #+#    #+#             */
/*   Updated: 2016/01/18 14:07:31 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evo.h"
#include <time.h>

static t_unit	init_unit(void)
{
	t_unit		unit;

	unit.pos.x = random_rank(1, WIDTH);
	unit.pos.y = random_rank(1, HEIGHT);
	unit.lv = LVPOP;
	unit.pv = random_rank(PVPOPMIN, PVPOPMAX);
	unit.death = random_rank(DEATHPOPMIN, DEATHPOPMAX);
	unit.dupl = random_rank(DUPLPOPMIN, DUPLPOPMAX);
	unit.evo = random_rank(EVOPOPMIN, EVOPOPMAX);
	return (unit);
}

void			init_random(void)
{
	srand(time(NULL));
}

int				random_rank(int a, int b)
{
	return ((rand() % (b - a)) + a);
}

t_list			*random_pop(size_t size)
{
	t_list		*lst;
	t_list		*elem;
	t_unit		unit;
	size_t		i;

	i = 0;
	lst = NULL;
	while (i < size)
	{
		unit = init_unit();
		if (!(elem = ft_lstnew((void *)&unit, sizeof(t_unit))))
		{
			ft_lstdel(&lst, NULL);
			return (NULL);
		}
		ft_lstadd(&lst, elem);
		i++;
	}
	return (lst);
}

t_pos			random_pos(t_pos pos)
{
	t_pos		cp;
	int			dir;

	cp = pos;
	dir = random_rank(0, 4);
	if (dir == 0 && (cp.x + 1) < WIDTH)
		cp.x++;
	else if (dir == 1 && (cp.x - 1) > 0)
		cp.x--;
	else if (dir == 2 && (cp.y + 1) < HEIGHT)
		cp.y++;
	else if (dir == 3 && (cp.y - 1) > 0)
		cp.y--;
	return (cp);
}
