#include "lem.h"
/*
static void	init_path_pound(t_lem_map *map, int id)
{
	int	i;

	i = 0;
	j = i;
	tmp = map->pathtab;
	map->path_pound[i] = sigma_len(*(t_list **)tmp->content, NULL);
	while (tmp->next)
	{
		tmp = tmp->next;
		if (map->madj_path[id * map->size_tab + i++])
			map->path_pound[++j] = sigma_len(*(t_list **)tmp->content, NULL);
	}
}
*/
void	print_path(t_list *path)
{
	int	i;

	i = 0;
	while (path)
	{
		if (!i++ || !path->next)	
			ft_printf("{red|gr}%d{eoc}", *((int *)path->content));
		else
			ft_printf("{cyan}%d{eoc}", *((int *)path->content));
		ft_printf(path->next ? "-" : "\n");
		path = path->next;
	}
}

int	lem_exec(t_lem_map *map)
{
//	int	i = 0;
//	t_list	*tmp;
//	int	best_path;
//	t_ant	ant[map->lem];
	
	if (found_path(map, map->id_s, NULL))
		return (1);
	else if (fill_madj_path(map))
		return (1);
/*	best_stable = select_stable(map);
	if (best_stable == -1)
		return (1);
	i = 0;
	init_path_pound(map, best_path);
	while (i < map->lem)
	{
		ant[i].choose = minpound(map);
		i++;
	}*/
//***********************************************************************************************
	
//***********************************************************************************************
	
	return (0);
}
