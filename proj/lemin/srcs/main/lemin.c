/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:23:55 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/20 16:38:18 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	may_dump_room(t_graph *rooms)
{
	if (PI_ISOPT(proginfo()->opt, O_STEP))
		dump_graph(rooms, "Room", dump_room);
}

static void	may_dump_path(t_graph *paths)
{
	if (PI_ISOPT(proginfo()->opt, O_STEP))
		dump_graph(paths, "Path", dump_path);
}

static void	may_dump_solution(t_list *solutions)
{
	if (PI_ISOPT(proginfo()->opt, O_STEP))
		dump_solutions(solutions);
}

static void	lem_init(t_graph *rooms, t_graph *paths,\
					t_cons *rules, t_list **solutions)
{
	*solutions = NULL;
	ft_bzero((void *)rooms, sizeof(t_graph));
	ft_bzero((void *)paths, sizeof(t_graph));
	rules->pop = -1;
	rules->id_s = -1;
	rules->id_e = -1;
}

void		lemin(int fd)
{
	t_graph	rooms;
	t_graph	paths;
	t_cons	rules;
	t_list	*solutions;

	lem_init(&rooms, &paths, &rules, &solutions);
	if (parsing(fd, &rooms, &rules))
	{
		ft_fprintf(2, "Error\n");
		return ;
	}
	may_dump_room(&rooms);
	if (resolve(&rooms, &paths, &rules, &solutions))
	{
		ft_fprintf(2, "Error\n");
		return ;
	}
	may_dump_path(&paths);
	may_dump_solution(solutions);
	if (play(&rooms, &paths, &rules, &solutions))
	{
		ft_fprintf(2, "Error\n");
		return ;
	}
}
