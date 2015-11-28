#include "lem.h"

static int		get_room_id(t_list *room, char *name)
{
	while (room)
	{
		if (!ft_strcmp(name, ((t_lem_room *)room->content)->name))
			return (((t_lem_room *)room->content)->id);
		room = room->next;
	}
	return (-1);
}

void			lem_get_room(char **data, t_lem_map *map, t_lem_state *state)
{
	t_lem_room	room;
	t_list		*elem;
	
	elem = map->room;
	while (elem)
	{
		if (!ft_strcmp(data[0], ((t_lem_room *)elem->content)->name))
		{
			*state = Lem_error;
			ft_printf("Lem: Error. [%s][%s]: Can't have two rooms with the same name! ", data[0], ((t_lem_room *)elem->content)->name);
			lem_del_data(data);
			return ;
		}
		elem = elem->next;
	}
	room.name = data[0];
	room.id = map->size++;
	room.x = data[1];
	room.y = data[2];
	//free(data[3]);
	elem = ft_lstnew(&room, sizeof(t_lem_room));
	if (!elem)
	{
		*state = Lem_error;
		ft_printf("Lem: Error. Memory allocation fail on room [%s] ", data[0]);
		lem_del_data(data);
		return ;
	}
	ft_lstadd(&map->room, elem);
}

void			lem_get_pipe(char **data, t_lem_map *map, t_lem_state *state)
{
	int		id1;
	int		id2;

	if (!map->madj)
	{
		map->madj = (int *)ft_memalloc(sizeof(int) * map->size * map->size);
		if (!map->madj)
		{
			*state = Lem_error;
			ft_printf("Lem: Error. Memory allocation fail on pipe [%s]-[%s] ", data[0], data[2]);
			lem_del_data(data);
			return ;
		}
	}
	id1 = get_room_id(map->room, data[0]);
	id2 = get_room_id(map->room, data[2]);
	if (id1 == -1 || id2 == -1)
	{
		ft_printf("Lem: Error. [%s] is not a valid room name ", id1 == -1 ? data[0] : data[2]);
		*state = Lem_error;
		lem_del_data(data);
		return ;
	}
	map->madj[id1 * map->size + id2] = 1;
	map->madj[id1 + id2 * map->size] = 1;
	lem_del_data(data);
}
