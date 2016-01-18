/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:48:16 by sbenning          #+#    #+#             */
/*   Updated: 2016/01/18 14:22:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evo.h"

static int	evo_exist(t_list *lst, t_pos pos)
{
	t_unit	*cp;

	while (lst)
	{
		cp = (t_unit *)lst->content;
		if (cp->pos.x == pos.x && cp->pos.y == pos.y)
			return (1);
		lst = lst->next;
	}
	return (0);
}

static void	evo_duplicate(t_env *e, t_unit *unit)
{
	t_list	*elem;
	t_unit	clone;

	clone = *unit;
	clone.pos = random_pos(clone.pos);
	if (evo_exist(e->pop, clone.pos))
		return ;
	clone.pv = random_rank(PVPOPMIN, PVPOPMAX) + (clone.lv * (random_rank(LVUPDEATHMIN, LVUPDEATHMAX)));
	if (!(elem = ft_lstnew(&clone, sizeof(t_unit))))
		return ;
	else
		ft_lstadd_back(&e->pop, elem);
}

static void	evo_evolute(t_unit *unit)
{
	unit->lv++;
	unit->death -= random_rank(LVUPDEATHMIN, LVUPDEATHMAX);
	if (unit->death < 1)
		unit->death = 1;
	unit->evo += random_rank(LVUPEVOMIN, LVUPEVOMAX);
	unit->pv += random_rank(LVUPPVMIN, LVUPPVMAX);
}

int			evo_loop(void *p)
{
	t_env	*e;
	t_list	*cp;
	t_unit	*tmp;
	int		i;

	i = 0;
	e = (t_env *)p;
	cp = e->pop;
	while (cp)
	{
		tmp = (t_unit *)cp->content;
		if (tmp->pv)
		{
			if (random_rank(0, 100) <= tmp->death)
				tmp->pv = 0;
			else if (random_rank(0, 100) <= tmp->dupl)
				evo_duplicate(e, tmp);
			else if (random_rank(0, 100) <= tmp->evo)
				evo_evolute(tmp);
			else if (tmp->pv)
				tmp->pv--;
		}
		cp = cp->next;
	}
	cp = e->pop;
	//sleep(1);
	evo_expose(p);
	return (0);
}

int			evo_key(int key, void *p)
{
	t_env	*e;

	e = (t_env *)p;
	if (key == QUITKEY)
	{
		ft_lstdel(&e->pop, NULL);
		evo_success(e->av, "evo destroy pop");
		mlx_destroy_window(e->mlx, e->win);
		evo_success(e->av, "mlx destroy window");
		evo_success(e->av, "mlx loop");
		exit(EXIT_SUCCESS);
	}
	ft_fprintf(2, "[%d]\n", key);
	return (0);
}
	
int		evo_expose(void *p)
{
	t_env	*e;
	t_list	*cp;
	t_unit	*tmp;

	e = (t_env *)p;
	cp = e->pop;
	while (cp)
	{
		tmp = (t_unit *)cp->content;
		mlx_pixel_put(e->mlx, e->win, tmp->pos.x, tmp->pos.y, (tmp->pv ? (0xff00 + (tmp->lv - 1) * 0x0f0000 - (tmp->lv - 1) * 0xf00) : 0x0));
		cp = cp->next;
	}
	return (0);
}
