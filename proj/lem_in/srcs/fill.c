#include "lem.h"

int	sigma_len(t_list *l1, t_list *l2)
{
	int	len;

	len = 0;
	while (l1 && l1->next)
	{
		l1 = l1->next;
		len++;
	}
	while (l2 && l2->next)
	{
		len++;
		l2 = l2->next;
	}
	return (len);
}

static int	is_inter(t_list *l1, t_list *l2)
{
	t_list	*tmp;
	int	len;

	len = sigma_len(l1, l2);
	l1 = l1->next;
	l2 = l2->next;
	while (l1->next)
	{
		tmp = l2;
		while (l2->next)
		{
			if (*(int *)l1->content == *(int *)l2->content)
				return (0);
			l2 = l2->next;
		}
		l1 = l1->next;
		l2 = tmp;
	}
	return (len);
}
/*
int		select_faster(t_lem_map *map)
{
	int	sigma;
	int	win;
	t_list	*tmp;
	int	i;

	i = 0;
	sigma = i;
	win = sigma;
	tmp = map->pathtab;
	while (tmp)
	{
		sigma = sigma_len(*(t_list **)tmp->content, NULL);
		win = sigma < win ? i : win;
		i++;
		tmp = tmp->next;
	}
	return (win);
}
*/
int		fill_madj_path(t_lem_map *map)
{
	t_list	*drive;
	t_list	*tmp;
	size_t	i;
	size_t	j;

	map->madj_path = (int *)ft_memalloc(sizeof(int) * (map->size_tab * map->size_tab));
	if (!map->madj_path)
		return (1);
	i = 0;
	drive = map->pathtab;
	while (drive->next)
	{
		j = i + 1;
		tmp = drive;
		drive = drive->next;
		while (drive)
		{
			map->madj_path[i * map->size_tab + j] = is_inter(*(t_list **)tmp->content, *(t_list **)drive->content);
			map->madj_path[j * map->size_tab + i] = map->madj_path[i * map->size_tab + j];
			drive = drive->next;
			j++;
		}
		drive = tmp->next;
		i++;
	}
	return (0);
}
