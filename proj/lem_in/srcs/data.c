#include "lem.h"

int	lem_check_data(char **data)
{
	char	**tmp;

	tmp = data;
	while (data && *data)
		data++;
	return (data - tmp == 3 ? 0 : 1);
}

void	lem_del_data(char **data)
{
	char	**tmp;

	tmp = data;
	while (data && *data)
	{
		free(*data);
		data++;
	}
	free(tmp);
}

void	lem_del(t_lem_map *map)
{
	t_list	*tmp;

	while (map->room)
	{
		tmp = map->room->next;
		free(((t_lem_room *)map->room->content)->name);
		free(((t_lem_room *)map->room->content)->x);
		free(((t_lem_room *)map->room->content)->y);
		free(map->room->content);
		free(map->room);
		map->room = tmp;
	}
	free(map->madj);
	if (map->madj_path)
		free(map->madj_path);
	while (map->pathtab)
	{
		tmp = map->pathtab->next;
	//	lem_del_path((t_list *)map->pathtab->content);
		free(map->pathtab);
		map->pathtab = tmp;
	}
}
