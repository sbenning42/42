/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 11:18:31 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/12 16:34:44 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_dlist	*getlist(int ac, char *av[], size_t *size)
{
	t_dlist		*h_dl;
	t_dlist		*dl;
	long		number;
	int			i;

	h_dl = NULL;
	i = -1;
	while (++i < ac)
	{
		if ((av[i][0] == '-' && !ft_isdigit(av[i][1])) || \
				(!ft_isdigit(av[i][0]) && av[i][0] != '-'))
			break ;
		number = ft_atol(av[i]);
		if (number > INT_MAX || number < INT_MIN)
			break ;
		number = (int)number;
		if ((dl = ft_dlstnew((void *)(int *)&number, sizeof(int))) == NULL)
			break ;
		ft_dlstaddn(&h_dl, dl);
		*size += 1;
	}
	if (i == ac)
		return (h_dl);
	ft_dlstdel(&h_dl, NULL);
	return (NULL);
}

int				pushswap(int ac, char *av[])
{
	t_dlist		*h_dl_a;
	t_dlist		*h_dl_b;
	size_t		size;

	size = 0;
	if (!(h_dl_a = getlist(ac, av, &size)))
		return (ps_error(EXIT_FAILURE));
	h_dl_b = NULL;
	ps_resolve(&h_dl_a, &h_dl_b, size);
	ft_dlstdel(&h_dl_a, NULL);
	ft_dlstdel(&h_dl_b, NULL);
	return (EXIT_SUCCESS);
}
