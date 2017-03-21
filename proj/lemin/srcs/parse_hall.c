/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 09:36:47 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/21 10:34:09 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	check_hall_integrity(char **hall, t_graph *rooms,\
								int *id1, int *id2)
{
	size_t	size;

	if (!hall)
		return (LEM_MALLOC_ERR);
	size = 0;
	while (hall[size])
		++size;
	if (size != LEM_HALL_SIZE)
		return (LEM_HALL_FMT_ERR);
	else if (!ft_strcmp(hall[0], hall[1]))
		return (LEM_CYCLE_HALL_ERR);
	*id1 = get_id_by_name(rooms, hall[0]);
	*id2 = get_id_by_name(rooms, hall[1]);
	if (*id1 < 0 || *id2 < 0)
		return (LEM_UNKNOW_ROOM_ERR);
	if (is_in_neig(rooms, *id1, *id2) || is_in_neig(rooms, *id2, *id1))
		return (LEM_DUPLICATE_HALL_ERR);
	return (LEM_NOERR);
}

static int	add_neig(t_graph *rooms, int id1, int id2)
{
	int		*tmp;
	size_t	size;

	tmp = rooms->node[id1].neig;
	size = rooms->node[id1].neig_size;
	rooms->node[id1].neig = (int *)ft_memalloc(sizeof(int) * (size + 1));
	if (!rooms->node[id1].neig)
		return (LEM_MALLOC_ERR);
	if (size)
		ft_memcpy(rooms->node[id1].neig, tmp, sizeof(int) * size);
	rooms->node[id1].neig[size] = id2;
	rooms->node[id1].neig_size += 1;
	return (LEM_NOERR);
}

static int	add_hall(t_graph *rooms, int id1, int id2)
{
	if (add_neig(rooms, id1, id2) || add_neig(rooms, id2, id1))
		return (LEM_MALLOC_ERR);
	return (LEM_NOERR);
}

int			parse_hall(char *line, int *state, t_graph *rooms)
{
	char	**hall;
	int		id1;
	int		id2;
	int		ret;

	if (*state < LEM_DEFAULT_STATE)
		return (LEM_NOPOP_ERR);
	*state = LEM_DEFAULT_STATE;
	hall = ft_strsplit(line, LEM_HALL_CHAR);
	if ((ret = check_hall_integrity(hall, rooms, &id1, &id2)))
		return ((ret == LEM_DUPLICATE_HALL_ERR ? 0 : ret));
	else if (add_hall(rooms, id1, id2))
		return (LEM_MALLOC_ERR);
	delete_tab(&hall);
	return (LEM_NOERR);
}
