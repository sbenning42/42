#include "lem.h"

static void		data_launch(char *line, t_lem_map *map, t_lem_state *state)
{
	char		**data;

	data = ft_strsplit(line, ' ');
	if (lem_check_data(data))
	{
		lem_del_data(data);
		*state = Lem_error;
		ft_printf("Lem: Error. Can't parse ");
	}
	else if (ft_strcmp(data[1], "-"))
	{
		lem_get_room(data, map, state);
		if (*state == Wait_end)
			map->id_e = ((t_lem_room *)map->room->content)->id;
		else if (*state == Wait_start)
			map->id_s = ((t_lem_room *)map->room->content)->id;
		*state = *state == Lem_error ? *state : Wait_data;
	}
	else
		lem_get_pipe(data, map, state);
}

static int		lem_comment(char *line, t_lem_state *state)
{
	if (*line == '#')
	{
		if (*(line + 1) == '#')
		{
			if (!ft_strcmp(line, "##END"))
				*state = Wait_end;
			else if (!ft_strcmp(line, "##START"))
				*state = Wait_start;
			else
				*state = Lem_error; //delete this line if ##OTHER_THAN_START_OR_END must be handle like a comment instead of an invalid command
		}
		return (1);
	}
	return (0);
}

static void		line_launch(char *line, t_lem_map *map, t_lem_state *state)
{
	if (lem_comment(line, state) || !*line || *line == '\n') // Line is a com, or is empty or it's just a nl, so work to do on this line, could switch to the next one
		return ;
	if (*state == Wait_lem)
	{
		map->lem = ft_atoi(line);
		if (map->lem < 1)
		{
			*state = Lem_error;
			ft_printf("Lem: Error. No ant in the lem! "); //Have to choose is the msg is print now or in the call function
		}
		else
			*state = Wait_data;
	}
	else
		data_launch(line, map, state);
}

static int		lem_launch(int fd, t_lem_map *map)
{
	int		ret;
	char		*line;
	t_lem_state	state;

	ret = 1;
	state = Wait_lem;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ret == 1)
		{
			line_launch(line, map, &state);
			if (state == Lem_error)
			{
		//		lem_del(map);
				ft_printf("line [%s]\n", line);
				lem_del(map);
				close(fd);
				return (1);
			}
			free(line);
		}
		else if (ret == -1)
			ft_printf("Lem: Error. Can't read file\n");
	}
	close(fd);
	return (ret ? 1 : 0);
}

void			lem(int fd)
{
	t_lem_map	map;
	
	
	t_list		*tmp;
	t_lem_room	*tmp2;
	int		i;

	ft_bzero((void *)&map, sizeof(t_lem_map));
	map.id_s = -1;
	map.id_e = -1;
	if (lem_launch(fd, &map))
		return ;
	else if (map.id_s == -1 || map.id_e == -1)
		ft_printf("Lem: Error. There is no start and/or end room\n");
	else
	{
		if (lem_exec(&map))
		{
			lem_del(&map);
			return ;
		}
	}


//******************************************************************************************************************************************

	i = 0;
	ft_printf("\nThere is %[Gr|Ss]d ants in the lem and %[Gr|Ss]d rooms in the map\n", map.lem, map.size);
	tmp = map.room;
	while (tmp)
	{
		tmp2 = (t_lem_room *)tmp->content;
		ft_printf("%[Gr|Pin]-5s id is %[Gr|Ss|Pin]d.\n", tmp2->name, tmp2->id);
		tmp = tmp->next;
	}
	ft_printf("Ant have to go from %[Gr|Ss]d to %[Gr|Ss]d\n", map.id_s, map.id_e);
	ft_printf("%[Blu|Gr|Ss]s\n |", "MATRICE:");
	while (i < map.size)
		ft_printf("%[Pin]d|", i++);
	i = 0;	
	ft_printf("\n%[Pin]d|", i);
	while (i < (map.size * map.size))
	{
		if (map.madj[i])
			ft_printf("%[Red|Gr]d", map.madj[i]);
		else if (i % map.size != i / map.size)
			ft_printf("%[Cya|Gr]d", map.madj[i]);
		else
			ft_printf("%[Gree|Gr]d", map.madj[i]);
		i++;
		if (i < (map.size * map.size) && i % map.size)
			ft_printf("|");
		else
		{
			if (i / map.size != map.size)
				ft_printf("|\n%[Pin]d|", i / map.size);
			else
				ft_printf("|\n");
		}
	}
	i = 0;
	tmp = map.pathtab;
	while (tmp)
	{
		ft_printf("%[GR|Ss]s%[Gr|Ss|Pin]d:\t", "Path ", i++);
		print_path(*(t_list **)tmp->content);
		tmp = tmp->next;
	}
	i = 0;
	ft_printf("%[Blu|Gr|Ss]s\n  |", "MATRICE PATH:");
	while (i < map.size_tab)
		ft_printf("%2[Pin]02d|", i++);
	i = 0;	
	ft_printf("\n%[Pin]02d|", i);
	while (i < (map.size_tab * map.size_tab))
	{
		if (map.madj_path[i])
			ft_printf("%[Red|Gr]02d", map.madj_path[i]);
		else if (i % map.size_tab != i / map.size_tab)
			ft_printf("%[Cya|Gr]02d", map.madj_path[i]);
		else
			ft_printf("%[Gree|Gr]02d", map.madj_path[i]);
		i++;
		if (i < (map.size_tab * map.size_tab) && i % map.size_tab)
			ft_printf("|");
		else
		{
			if (i / map.size_tab != map.size_tab)
				ft_printf("|\n%[Pin]02d|", i / map.size_tab);
			else
				ft_printf("|\n");
		}
	}










//***************************************************************************************************************************************	
	lem_del(&map);
}
