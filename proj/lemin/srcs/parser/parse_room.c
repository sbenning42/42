/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 09:36:49 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/21 10:02:56 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		check_room_integrity(t_graph *rooms, char **room)
{
	size_t		size;

	if (!room)
		return (LEM_MALLOC_ERR);
	size = 0;
	while (room[size])
		++size;
	if (size != LEM_ROOM_SIZE)
		return (LEM_ROOM_FMT_ERR);
	if (room[0][0] == 'L')
		return (LEM_FORBIDDEN_ROOM_ERR);
	if (get_id_by_name(rooms, room[0]) != -1)
		return (LEM_DUPLICATE_ROOM_ERR);
	if (ft_strchr(room[0], '-'))
		return (LEM_LITIGE_ROOM_ERR);
	return (LEM_NOERR);
}

static int		add_room(t_graph *rooms, char **room, int id)
{
	t_node		*tmp;
	char		*name;

	tmp = rooms->node;
	rooms->mem_size += 1;
	rooms->node = (t_node *)ft_memalloc(sizeof(t_node) * rooms->mem_size);
	if (!rooms->node)
		return (LEM_MALLOC_ERR);
	if (rooms->size)
		ft_memcpy(rooms->node, tmp, sizeof(t_node) * rooms->size);
	if (!(name = ft_strdup(room[0])))
		return (LEM_MALLOC_ERR);
	rooms->node[id].id = id;
	rooms->node[id].meta = ft_memalloc(sizeof(t_room));
	if (!rooms->node[id].meta)
		return (LEM_MALLOC_ERR);
	ACCESS_ROOM_META(rooms, id)->name = name;
	ACCESS_ROOM_META(rooms, id)->x = ft_atoi(room[1]);
	ACCESS_ROOM_META(rooms, id)->y = ft_atoi(room[2]);
	rooms->size += 1;
	return (0);
}

int				parse_room(char *line, int *state,\
							t_graph *rooms, t_cons *rules)
{
	char		**room;
	int			ret;
	static int	id;

	if (!rooms->size)
		id = 0;
	if (*state < LEM_DEFAULT_STATE)
		return (LEM_NOPOP_ERR);
	else if (*state == LEM_START_STATE)
		rules->id_s = id;
	else if (*state == LEM_END_STATE)
		rules->id_e = id;
	*state = LEM_DEFAULT_STATE;
	room = ft_strsplit(line, LEM_ROOM_CHAR);
	if ((ret = check_room_integrity(rooms, room)))
		return (ret);
	else if (add_room(rooms, room, id))
		return (LEM_MALLOC_ERR);
	delete_tab(&room);
	id += 1;
	return (0);
}
