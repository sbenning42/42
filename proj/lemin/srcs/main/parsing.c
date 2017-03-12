/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:56:19 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/09 15:20:50 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int					synerror(char **line, int li)
{
	if (PI_ISOPT(proginfo()->opt, O_VERB))
		ft_fprintf(2, "%s: Syntax error.\nLine%d: `%s`\n", proginfo()->name, li, *line);
	ft_memdel((void **)line);
	return (-1);
}

int					taginfo(char *line, int *state)
{	
	if (*(line + 1) != '#')
		return (0);
	if (*state < 0)
		return (-1);
	if (!ft_strcmp(line + 2, "START"))
		*state = 1;
	else if (!ft_strcmp(line + 2, "END"))
		*state = 2;
	return (0);
}

int					popinfo(char *line, int *state, t_cons *rules)
{
	*state = 0;
	rules->pop = ft_atoi(line);
	return ((rules->pop < 1 ? -1 : 0));
}

int					idsearch(t_graph *rooms, char *name)
{
	int				id;

	id = 0;
	while (id < rooms->size)
	{
		if (!ft_strcmp(((t_room *)rooms->node[id].meta)->name, name))
			return (id);
		id++;
	}
	return (-1);
}

int					isinneig(t_graph *rooms, int id1, int id2)
{
	int				i;

	i = 0;
	while (i < rooms->node[id1].neig_size)
	{
		if (rooms->node[id1].neig[i] == id2)
			return (1);
		i++;
	}
	return (0);
}

int					addroom(t_graph *rooms, char **infos, int id)
{
	t_node*				tmp;

	tmp = rooms->node;
	rooms->mem_size += 1;
	rooms->node = (t_node *)ft_memalloc(sizeof(t_node) * rooms->mem_size);
	if (rooms->size)
		ft_memcpy(rooms->node, tmp, sizeof(t_node) * rooms->size);
	rooms->node[id].id = id;
	rooms->node[id].meta = (t_room *)ft_memalloc(sizeof(t_room));
	((t_room *)rooms->node[id].meta)->name = ft_strdup(infos[0]);
	((t_room *)rooms->node[id].meta)->x = ft_atoi(infos[1]);
	((t_room *)rooms->node[id].meta)->y = ft_atoi(infos[2]);
	rooms->size += 1;
	return (0);
}

int				roominfo(char *line, int *state, t_graph *rooms, t_cons *rules)
{
	char			**infos;
	static int		id;

	if (*state < 0)
		return (-1);
	else if (*state == 1)
		rules->id_s = id;
	else if (*state == 2)
		rules->id_e = id;
	*state = 0;
	infos = ft_strsplit(line, ' ');
	if (!infos)
		return (-1);
	else if (!infos[0])
		return (-1);
	else if (!infos[1])
		return (-1);
	else if (!infos[2])
		return (-1);
	else if (infos[3])
		return (-1);
	else if (idsearch(rooms, infos[0]) != -1)
		return (-1);
	else if (addroom(rooms, infos, id))
		return (-1);
	free(infos[0]);
	free(infos[1]);
	free(infos[2]);
	free(infos);
	id += 1;
	return (0);
}

int					addhall(t_graph *rooms, int id1, int id2)
{
	int				*tmp;

	tmp = rooms->node[id1].neig;
	rooms->node[id1].neig = (int *)ft_memalloc(sizeof(int) * (rooms->node[id1].neig_size + 1));
	if (!rooms->node[id1].neig)
		return (-1);
	if (rooms->node[id1].neig_size)
		ft_memcpy(rooms->node[id1].neig, tmp, sizeof(int) * rooms->node[id1].neig_size);
	rooms->node[id1].neig[rooms->node[id1].neig_size] = id2;
	rooms->node[id1].neig_size += 1;
	tmp = rooms->node[id2].neig;
	rooms->node[id2].neig = (int *)ft_memalloc(sizeof(int) * (rooms->node[id2].neig_size + 1));
	if (!rooms->node[id1].neig)
		return (-1);
	if (rooms->node[id2].neig_size)
		ft_memcpy(rooms->node[id2].neig, tmp, sizeof(int) * rooms->node[id2].neig_size);
	rooms->node[id2].neig[rooms->node[id2].neig_size] = id1;
	rooms->node[id2].neig_size += 1;
	return (0);
}

int					hallinfo(char *line, int *state, t_graph *rooms)
{
	char			**infos;
	int				id1;
	int				id2;

	if (*state < 0)
		return (-1);
	*state = 0;
	infos = ft_strsplit(line, '-');
	if (!infos)
		return (-1);
	else if (!infos[0])
		return (-1);
	else if (!infos[1])
		return (-1);
	else if (infos[2])
		return (-1);
	else if (!ft_strcmp(infos[0], infos[1]))
		return (-1);
	id1 = idsearch(rooms, infos[0]);
	id2 = idsearch(rooms, infos[1]);
	if (id1 < 0 || id2 < 0 || isinneig(rooms, id1, id2) || isinneig(rooms, id2, id1))
		return (-1);
	else if (addhall(rooms, id1, id2))
		return (-1);
	free(infos[0]);
	free(infos[1]);
	free(infos);
	return (0);
}

int					getinfo(char *line, t_graph *rooms, t_cons *rules)
{
	static int		state = -1;

	if (*line == '#')
		return (taginfo(line, &state));
	if (state == -1)
		return (popinfo(line, &state, rules));
	else if (ft_strchr(line, ' '))
		return (roominfo(line, &state, rooms, rules));
	else if (ft_strchr(line, '-'))
		return (hallinfo(line, &state, rooms));
	else
		return (-1);
	return (0);
}

int					parsing(int fd, t_graph *rooms, t_cons *rules)
{
	int				ret;
	int				i;
	char				*line;

	i = 1;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!*line)
		{
			ft_memdel((void **)&line);
			break ;
		}
		if (getinfo(line, rooms, rules))
		{
			return (synerror(&line, i));
		}
		ft_memdel((void **)&line);
		i++;
	}
	return ((ret < 0 ? ret : 0));
}
