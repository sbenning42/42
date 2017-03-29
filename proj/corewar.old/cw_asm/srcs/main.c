/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 17:39:04 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/26 19:56:12 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	compile(char *filename, int fd)
{
	char	*line;
	char	*tmp;
	int		ret;
	int		li;

	li = 1;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!*line)
		{
			ft_memdel((void **)&line);
			++li;
			continue ;
		}
		tmp = ft_strtrim(line);
		ft_memdel((void **)&line);
		line = tmp;
		if (!*tmp)
		{
			ft_memdel((void **)&tmp);
			++li;
			continue ;
		}
		if (ft_parse(ASM_PARSE(ASM_LINE), &tmp, NULL))
			ft_printf("%s: Line %d: Parsed! [%s]\n", filename, li, line);
		else
			ft_printf("%s: Line %d: NOT Parsed! [%s]\n", filename, li, line);
		ft_memdel((void **)&line);
		++li;
	}
}

int			main(int ac, char **av)
{
	int		i;
	int		fd;

	proginfo_init(ac, av, NULL, ASM_OPT_CHARSET);
	ac = proginfo()->oarg_c;
	av = proginfo()->oarg_v;
	i = -1;
	while (++i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd < 0)
		{
			ft_fprintf(2, ASM_OPEN_ERROR_FMT, proginfo()->name, av[i]);
			continue ;
		}
		compile(av[i], fd);
		close(fd);
	}
	return (0);
}
