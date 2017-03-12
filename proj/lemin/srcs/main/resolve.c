/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:56:46 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/09 15:05:17 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				pushstep(t_btrack *backtrack)
{
	t_list			*step;

	step = ft_lstnew((void *)&backtrack->id, sizeof(int));
	ft_lstadd(&backtrack->path, step);
	return (0);
}

int				popstep(t_btrack *backtrack)
{
	t_list			*tmp;

	if (!backtrack->path)
		return (0);
	tmp = backtrack->path->next;
	ft_lstdelone(&backtrack->path, NULL);
	backtrack->path = tmp;
	return (0);
}

int				isforbidden(t_btrack *backtrack)
{
	t_list			*drive;

	drive = backtrack->path;
	while (drive)
	{
		if (backtrack->id == *(int *)drive->content)
			return (1);
		drive = drive->next;
	}
	return (0);
}

size_t				lstsize(t_list *l)
{
	size_t			size;

	size = 0;
	while (l)
	{
		size++;
		l = l->next;
	}
	return (size);
}

void				fillstep(int *t, t_list *l)
{
	while (l)
	{
		*t = *(int *)l->content;
		l = l->next;
		t++;
	}
}

int				isinpneig(t_graph *paths, int id1, int id2)
{
	int			i;
	int			size;

	size = paths->node[id1].neig_size;
	i = -1;
	while (++i < size)
	{
		if (paths->node[id1].neig[i] == id2)
			return (1);
	}
	return (0);
}

void				setneig(t_graph *paths, int id1, int id2)
{
	int			*tmp;

	tmp = paths->node[id1].neig;
	paths->node[id1].neig = (int *)ft_memalloc(sizeof(int) * (paths->node[id1].neig_size + 1));
	if (paths->node[id1].neig_size)
		ft_memcpy(paths->node[id1].neig, tmp, sizeof(int) * paths->node[id1].neig_size);
	free(tmp);
	paths->node[id1].neig[paths->node[id1].neig_size] = id2;
	paths->node[id1].neig_size += 1;
	tmp = paths->node[id2].neig;
	paths->node[id2].neig = (int *)ft_memalloc(sizeof(int) * (paths->node[id2].neig_size + 1));
	if (paths->node[id2].neig_size)
		ft_memcpy(paths->node[id2].neig, tmp, sizeof(int) * paths->node[id2].neig_size);
	free(tmp);
	paths->node[id2].neig[paths->node[id2].neig_size] = id1;
	paths->node[id2].neig_size += 1;
}

void				fillneig(t_graph *paths, int id)
{
	int			i;
	int			j;
	int			k;
	int			step_size;
	int			other_step_size;

	step_size = ((t_path *)paths->node[id].meta)->size - 1;
	i = 0;
	while (++i < step_size)
	{
		j = -1;
		while (++j < id)
		{
			if (isinpneig(paths, id, j))
				continue ;
			other_step_size = ((t_path *)paths->node[j].meta)->size - 1;
			k = 0;
			while (++k < other_step_size)
			{
				if (((t_path *)paths->node[id].meta)->step[i] == ((t_path *)paths->node[j].meta)->step[k])
				{
					setneig(paths, id, j);
					break ;
				}
			}
		}
	}
}

int				savepath(t_graph *path, t_btrack *backtrack)
{
	size_t			size;
	int			*step;
	t_node			*tmp;
	static int		id;
	
	size = lstsize(backtrack->path);
	step = (int *)ft_memalloc(sizeof(int) * size);
	fillstep(step, backtrack->path);
	tmp = path->node;
	path->mem_size += 1;
	path->node = (t_node *)ft_memalloc(sizeof(t_node) * path->mem_size);
	if (path->size)
		ft_memcpy(path->node, tmp, sizeof(t_node) * path->size);
	path->node[id].id = id;
	path->node[id].meta = (t_path *)ft_memalloc(sizeof(t_path));
	((t_path *)path->node[id].meta)->step = step;
	((t_path *)path->node[id].meta)->size = size;
	path->size += 1;
	fillneig(path, id);
	id += 1;
	return (0);
}

int				getpaths(t_graph *rooms, t_graph *paths, t_cons *rules, t_btrack *backtrack)
{
	int			myid;
	int			i;
	int			size;

	myid = backtrack->id;
	pushstep(backtrack);
	if (myid == rules->id_s)
	{
		savepath(paths, backtrack);
		popstep(backtrack);
		return (0);
	}
	i = -1;
	size = rooms->node[myid].neig_size;
	while (++i < size)
	{
		backtrack->id = rooms->node[myid].neig[i];
		if (isforbidden(backtrack))
			continue ;
		else if (getpaths(rooms, paths, rules, backtrack))
			return (-1);
	}
	popstep(backtrack);
	return (0);
}

int				isstabable(t_graph *paths, t_btrack *backtrack, int testid)
{
	t_list			*drive;
	int			id;
	size_t			size;
	int			i;

	drive = backtrack->path;
	while (drive)
	{
		id = *(int *)drive->content;
		if (id == testid)
			return (0);
		size = paths->node[id].neig_size;
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

void				savestable(t_list **solutions, t_btrack *backtrack)
{
	t_list			*stable;
	t_sol			sol;

	sol.size = lstsize(backtrack->path);
	sol.stable = (int *)ft_memalloc(sizeof(int) * sol.size);
	sol.queue = (int *)ft_memalloc(sizeof(int) * sol.size);
	fillstep(sol.stable, backtrack->path);
	stable = ft_lstnew(&sol, sizeof(t_sol));
	ft_lstadd_back(solutions, stable);
}

void				getsolutions(t_graph *paths, t_list **solutions, t_btrack *backtrack)
{
	int			i;
	int			flag;

	flag = 0;
	pushstep(backtrack);
	i = backtrack->id;
//	i = -1;
	while (++i < paths->size)
	{
		if (isstabable(paths, backtrack, i))
		{
			flag = 1;
			backtrack->id = i;
			getsolutions(paths, solutions, backtrack);
		}
	}
	if (!flag)
		savestable(solutions, backtrack);
	popstep(backtrack);
}

int				resolve(t_graph *rooms, t_graph *paths, t_cons *rules, t_list **solutions)
{
	t_btrack		backtrack;
	int			i;
	int			k;
	t_list			*tmp;
	t_sol			*sol;
	int			best;
	int			best_id;

	ft_bzero(&backtrack, sizeof(t_btrack));
	backtrack.id = rules->id_e;
	backtrack.path = NULL;
	getpaths(rooms, paths, rules, &backtrack);
	ft_bzero(&backtrack, sizeof(t_btrack));
	i = -1;
	while (++i < paths->size)
	{
		backtrack.id = i;
		getsolutions(paths, solutions, &backtrack);
	}
	i = -1;
	while (++i < rules->pop)
	{
		tmp = *solutions;
		while (tmp)
		{
			sol = (t_sol *)tmp->content;
			k = -1;
			best = INT_MAX;
			while (++k < sol->size)
			{
				if (best > (((t_path *)paths->node[sol->stable[k]].meta)->size + sol->queue[k]))
				{
					best = ((t_path *)paths->node[sol->stable[k]].meta)->size + sol->queue[k];
					best_id = k;
				}
			}
			sol->queue[best_id] += 1;
			tmp = tmp->next;
		}
	}
	tmp = *solutions;
	int timer;
	while (tmp)
	{
		sol = (t_sol *)tmp->content;
		sol->timer = INT_MIN;
		i = -1;
		while (++i < sol->size)
		{
			if (!sol->queue[i])
				continue ;
			timer = (((t_path *)paths->node[sol->stable[i]].meta)->size - 1) + (sol->queue[i] - 1);
			if (sol->timer < timer)
				sol->timer = timer;
		}
		tmp = tmp->next;
	}
	return (0);
}
