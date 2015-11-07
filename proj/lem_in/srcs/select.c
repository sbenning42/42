#include "lem.h"

int		select_path(t_lem_map *map)
{
	int	id;
	int	i;
	int	j;
	int	win_n;
	int	tmp_n;
	int	win_pound;
	int	tmp_pound;

	i = 0;
	win_n = 0;
	win_pound = 0;
	while (i < map->size_tab)
	{
		j = 0;
		tmp_n = j;
		tmp_pound = j;
		while (j < map->size_tab)
		{
			tmp_n += map->madj_path[i + j] ? 1 : 0;
			tmp_pound += map->madj_path[i + j];
			j++;

		}
		if (win_n == tmp_n)
		{
			if (tmp_pound < win_pound)
			{
				win_pound = tmp_pound;
				id = i / map->size_tab;
			}
		}
		else if (win_n < tmp_n)
		{
			win_n = tmp_n;
			win_pound = tmp_pound;
			id = i / map->size_tab;
		}
		i += map->size_tab;
	}
	if (!win_n)
		id = select_faster(map);
	map->path_pound = (int *)ft_memalloc(sizeof(int) * win_n + 1);
	if (!map->path_pound)
		return (1);
	return (id);
}
