#include "lem.h"

void	lem_del_path(t_list *path)
{
	t_list	*tmp;

	while (path)
	{
		tmp = path->next;
		free(path->content);
		free(path);
		path = tmp;
	}
}

t_list	**pathtab(void)
{
	static t_list	*path;

	return (&path);
}

int		add_to_path(t_list **path, int id)
{
	t_list	*elem;

	elem = ft_lstnew((void *)&id, sizeof(int));
	if (!elem)
	{
		lem_del_path(*path);
		return (1);
	}
	elem->next = *path;
	*path = elem;
	return (0);
}

t_list			*copypath(t_list *path)
{
	t_list		*newpath;

	newpath = NULL;
	while (path)
	{
		if (add_to_path(&newpath, *((int *)path->content)))
		{
			lem_del_path(newpath);
			return (NULL);
		}
		path = path->next;
	}
	return (newpath);
}

int			save_path(t_lem_map *map, t_list *path)
{
	t_list		*elem;
	t_list		*cp;

	cp = copypath(path);
	if (!cp)
	{
		lem_del_path(path);
		return (1);
	}
	elem = ft_lstnew((void *)&cp, sizeof(t_list *));
	if (!elem)
	{
		lem_del_path(cp);
		lem_del_path(path);
		return (1);
	}
	elem->next = map->pathtab;
	map->pathtab = elem;
	map->size_tab++;
	return (0);
}

void		rem_to_path(t_list **path)
{
	t_list	*tmp;

	tmp = *path;
	if (tmp)
	{
		*path = tmp->next;
		free(tmp->content);
		free(tmp);
	}
}

int		is_in_path(t_list *path, int id)
{
	while (path)
	{
		if (id == *((int *)path->content))
			return (1);
		path = path->next;
	}
	return (0);
}

int		found_path(t_lem_map *map, int src, t_list *path)
{
	int	i;
	int	j;
	
	if (add_to_path(&path, src))
		return (1);
	if (src == map->id_e)
	{
		if (save_path(map, path))
			return (1);
		rem_to_path(&path);
		return (0);

	}
	i = src * map->size;
	j = i + map->size;
	while (i < j)
	{
		if (map->madj[i])
		{
			if (!is_in_path(path, i % map->size) && found_path(map, i % map->size, path))
					return (1);

		}
		i++;
	}
	rem_to_path(&path);
	return (0);
}
