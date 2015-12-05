/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:38:17 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/05 11:34:39 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static char		**fdf_handle_av(int *ac, char **fake, char **real)
{
	char		**av;

	fake[0] = real[0];
	fake[1] = FDF_FAKE_AV;
	av = (*ac == 1 ? fake : real);
	*ac += (*ac == 1 ? 1 : 0);
	return (av);
}

static int		fdf_put_rules(char *name)
{
	ft_printf("%s:{ss}%s{eoc}\n\n{green}%s{eoc}%s{green}%s{eoc}%s",\
			name, MSG_RULES, MSG_KESC, MSG_ESC, MSG_KUPDOWN, MSG_UPDOWN);
	return (0);
}

int				main(int ac, char **av)
{
	char		**fdf_av;
	char		*fake_av[2];
	t_fdf_map	map;
	int			pid;
	int			i;

	fdf_av = fdf_handle_av(&ac, fake_av, av);
	fdf_put_rules(av[0]);
	i = 1;
	while (i < ac)
	{
		ft_bzero((void *)&map, sizeof(t_fdf_map));
		if (fdf_parse_file(fdf_av, i++, &map))
		{
			if (!(pid = fork()))
				fdf_mlx(map, av[0]);
			else if (pid < 0)
				ft_printf("%s:{red}%s{eoc}%s\n",\
						av[0], ERRMSG_FORK, fdf_av[i - 1]);
		}
	}
	return (0);
}
