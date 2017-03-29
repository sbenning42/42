/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 08:20:03 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/26 12:01:25 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	open_error(char *filename)
{
	ft_fprintf(2, ASM_OPEN_ERROR_FMT, proginfo()->name, filename);
}

static void	compile(char *filename, int fd)
{
	char		*line;
	char		*tmp;
	int			ret;
	t_asm_token	*lexem;

	lexem = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		tmp = line;
		if (!*line)
		{
			ft_memdel((void **)&line);
			continue ;
		}
		if (asm_lexer(&tmp, &lexem))
		{
			ft_memdel((void **)&line);
			continue ;
		}
		ft_memdel((void **)&line);
	}
	(void)filename;
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
			open_error(av[i]);
			continue ;
		}
		compile(av[i], fd);
		close(fd);
	}
	return (0);
}
