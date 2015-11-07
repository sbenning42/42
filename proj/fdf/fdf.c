#include "fdf.h"

void			fdf_color(int z)
{
	if (z == 10)
		ft_printf(",%[Cya]2d", z);
	else if (z == 20)
		ft_printf(",%[Blu]2d", z);
	else if (z == 30)
		ft_printf(",%[Gree]2d", z);
	else if (z == 40)
		ft_printf(",%[Yel]2d", z);
	else if (z == 50)
		ft_printf(",%[Red]2d", z);
	else if (z == 0)
		ft_printf(",%[Gre]2d", z);
}

void			fdf_color2(int z)
{
	if (z == 10)
		ft_printf("%[Fcya]s", " ");
	else if (z == 20)
		ft_printf("%[Fblu]s", " ");
	else if (z == 30)
		ft_printf("%[Fgree]s", " ");
	else if (z == 40)
		ft_printf("%[Fyel]s", " ");
	else if (z == 50)
		ft_printf("%[Fred]s", " ");
	else if (z == 0)
		ft_printf("%[Fgre]s", " ");
}

int			fdf_fill(t_list **info, char *line, int x, int *y)
{
	t_fdf_point	point;
	t_list		*elem;
	char		**tab;
	char		**cp;
	int		i;

	i = 0;
	tab = ft_strsplit(line, ' ');
	if (!tab)
		return (1);
	while (tab[i] && *(tab[i]))
	{
		point.x = x;
		point.y = i;
		point.z = ft_atoi(tab[i]);
		elem = ft_lstnew((void *)&point, sizeof(t_fdf_point));
		if (!elem)
			break ;
		ft_lstadd_back(info, elem);
		i++;
	}
	*y = i ? i : *y;
	cp = tab;
	while (*tab)
		free(*tab++);
	free(cp);
	return (elem ? 0 : 1);
}

int			fdf_parse(t_list **info, int fd, int *y)
{
	char		*line;
	int		ret;
	int		i;

	i = 0;
	while ((ret = get_next_line(fd, &line)) != -1)
	{
		if (!ret)
		{
			free(line);
			break ;
		}
		ret = fdf_fill(info, line, i, y);
		free(line);
		if (ret)
			break ;
		i++;
	}
	return (ret ? 1 : 0);
}

void			fdf_print(t_list *info, int y)
{
	t_fdf_point	*cp;
	int		i;

	i = 0;
	while (info)
	{
		cp = (t_fdf_point *)info->content;
		ft_printf("%[Gr]3d%2d,%2d", i++, cp->x, cp->y);
		fdf_color(cp->z);
		if (y && ((i % y) == 0))
			ft_printf("\n");
		info = info->next;
	}
}

void			fdf_print2(t_list *info, int y)
{
	t_fdf_point	*cp;
	int		i;

	i = 0;
	ft_printf("\n%[Gr|Ss]s\n\n", "DRAW:");
	while (info)
	{
		cp = (t_fdf_point *)info->content;
		fdf_color2(cp->z);
		if (y && !(++i % y))
			ft_printf("\n");
		info = info->next;
	}
	ft_printf("\n");
}

void			fdf_del(t_list *info)
{
	t_list		*cp;

	while (info)
	{
		cp = info->next;
		free(info->content);
		free(info);
		info = cp;
	}
}

void			fdf(int fd)
{
	t_list		*info;
	int		y;

	info = NULL;
	if (fdf_parse(&info, fd, &y))
		return ;
	fdf_print(info, y);
	fdf_print2(info, y);
	fdf_del(info);
}

int			main(int ac, char **av)
{
	int		fd;
	int		i;

	i = 0;
	while (++i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) > 0)
		{
			fdf(fd);
			close(fd);
		}
		else
			ft_printf("fdf: Error, can't open file %s\n", av[i]);
	}
	if (ac == 1)
		fdf(0);
	return (0);
}
