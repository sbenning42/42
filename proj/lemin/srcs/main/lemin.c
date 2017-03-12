/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:23:55 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/09 15:28:11 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		dump_room(void *meta)
{
	t_room	*r;

	r = (t_room *)meta;
	ft_printf("\t{gr|cyan}%s{eoc}: ({blue}%d{eoc}, {red}%d{eoc})", r->name, r->x, r->y);
}

void		dump_path(void *meta)
{
	t_path	*p;
	int	i;

	p = (t_path *)meta;
	ft_printf("\t{gr}[{eoc}");
	i = -1;
	while (++i < p->size)
	{
		ft_printf("{gr|cyan}%d{eoc}{gr}%c{eoc}", p->step[i], (i + 1 == p->size ? ']' : ','));
	}
}


void		dump_g(t_graph *g, char *name, void (*f)(void *))
{
	int	i;
	int	j;

	i = -1;
	ft_printf("{gr|ss}Dumping graph `{eoc}{gr|ss|green}%s{eoc}{gr|ss}`{eoc}\n\n", name);
	while (++i < g->size)
	{
		f(g->node[i].meta);
		ft_printf("\t{gr}%d{eoc} [", i);
		j = -1;
		while (++j < g->node[i].neig_size)
			ft_printf("%d%c ", g->node[i].neig[j], (j + 1 == g->node[i].neig_size ? ']' : ','));
		if (!j)
			ft_printf("]");
		ft_printf("\n");
	}
	ft_printf("\n");
}

void		dump(t_graph *g, t_cons *r)
{
	int	i = -1;
	int	j = -1;


	ft_printf("{gr}Pop{eoc}: {gr|yellow}%d{eoc}, {gr}Start{eoc}: `{gr|green}%s{eoc}`, {gr}End{eoc}: `{gr|red}%s{eoc}`\n",\
			r->pop, (r->id_s < 0 ? "-1" : ((t_room *)g->node[r->id_s].meta)->name), (r->id_e < 0 ? "-1" : ((t_room *)g->node[r->id_e].meta)->name));
	while (++i < g->size)
	{
		ft_printf("\tRoom `{gr|cyan}%s{eoc}`:",\
				((t_room *)g->node[i].meta)->name);
		if (g->node[i].neig_size > 0)
			ft_printf("[");
		j = -1;
		while (++j < g->node[i].neig_size)
			ft_printf("`%s`%c", ((t_room *)g->node[g->node[i].neig[j]].meta)->name,((j + 1 == g->node[i].neig_size) ? ']' : ','));
		ft_printf("\n");
	}
}

void		dump2(t_graph *g)
{
	int	i = -1;
	int	j = -1;

	ft_printf("There is {gr|pink}%zu{eoc} path in the graph:\n", g->size);
	while (++i < g->size)
	{
		ft_printf("\t{gr|red}%d{eoc} {gr}[{eoc}", i);
		j = -1;
		while (++j < ((t_path *)g->node[i].meta)->size)
			ft_printf("{gr|cyan}%d{eoc}{gr}%c{eoc}", ((t_path *)g->node[i].meta)->step[j], (j + 1 == ((t_path *)g->node[i].meta)->size ? ']' : '-'));
		j = -1;
		ft_printf(" [");
		while (++j < g->node[i].neig_size)
			ft_printf("{gr|red}%d{eoc}%c", g->node[i].neig[j], (j + 1 == g->node[i].neig_size ? ']' : ','));
		if (!j)
			ft_printf("]");
		ft_printf("\n");
	}
}

void		dump3(t_list *l)
{
	t_sol	*s;
	int	best = INT_MAX;
	int	best_id;
	int	i = -1;
	int	j = 0;

	while (l)
	{
		s = (t_sol *)l->content;
		ft_printf("{gr|ss}Solution {eoc}{gr|ss|green}%d{eoc}{gr|ss}:{eoc} {gr}[{eoc}", ++j);
		i = -1;
		while (++i < s->size)
			ft_printf("{gr|red}%d{eoc}{gr}%c{eoc} ", s->stable[i], (i + 1 == s->size ? ']' : ','));
		if (!i)
			ft_printf("{gr}]{eoc}");
		i = -1;
		ft_printf("\t{gr}[{eoc}");
		while (++i < s->size)
			ft_printf("{gr|yellow}%d{eoc}{gr}%c{eoc} ", s->queue[i], (i + 1 == s->size ? ']' : ','));
		if (!i)
			ft_printf("{gr}]{eoc}");
		ft_printf("{gr|ss}Speed:{eoc} {gr|green}%d{eoc}\n", s->timer);
		if (best > s->timer)
		{
			best = s->timer;
			best_id = j;
		}
		l = l->next;
	}
	ft_printf("\n{gr|ss|cyan}Best Solution is: {eoc}{gr|ss|green}%d{eoc}{gr|ss|cyan}, with speed of: {eoc}{gr|ss|green}%d{eoc}\n\n", best_id, best);
}

void		lemin(int fd)
{
	t_graph	rooms;
	t_graph	paths;
	t_cons	rules;
	t_list	*solutions;

	solutions = NULL;
	ft_bzero((void *)&rooms, sizeof(t_graph));
	ft_bzero((void *)&paths, sizeof(t_graph));
	rules.pop = -1;
	rules.id_s = -1;
	rules.id_e = -1;
	if (parsing(fd, &rooms, &rules))
	{
		ft_fprintf(2, "Parsing Error\n");
	}
//	dump(&rooms, &rules);
	dump_g(&rooms, "Room", dump_room);
	if (resolve(&rooms, &paths, &rules, &solutions))
	{
		ft_fprintf(2, "Resolve Error\n");
		return ;
	}
//	dump2(&paths);
	dump_g(&paths, "Path", dump_path);
	dump3(solutions);
	if (play(&rooms, &paths, &rules, &solutions))
	{
		ft_fprintf(2, "Play Error\n");
		return ;
	}
	/*TODO Destroy everything*/
	return ;
}
