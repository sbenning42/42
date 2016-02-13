/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 11:18:31 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/13 12:00:13 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_dlist	*get_stack(int ac, char *av[], size_t *size)
{
	t_dlist		*h_stack;
	t_dlist		*stack;
	long		number;
	int			i;

	h_stack = NULL;
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
		if ((stack = ft_dlstnew((void *)(int *)&number, sizeof(int))) == NULL)
			break ;
		ft_dlstaddn(&h_stack, stack);
		*size += 1;
	}
	if (i == ac)
		return (h_stack);
	ft_dlstdel(&h_stack, NULL);
	return (NULL);
}

int				pushswap(int ac, char *av[], int o)
{
	t_dlist		*stack_a;
	t_dlist		*stack_b;
	size_t		size;

	size = 0;
	if (!(stack_a = get_stack(ac, av, &size)))
		return (error(EXIT_FAILURE, o));
	stack_b = NULL;
	ps_resolve(&stack_a, &stack_b, size, o);
	ft_dlstdel(&stack_a, NULL);
	ft_dlstdel(&stack_b, NULL);
	return (EXIT_SUCCESS);
}
