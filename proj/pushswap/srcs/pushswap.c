/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 11:18:31 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/19 11:12:53 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int		isdouble_n(\
				t_dlist *stack, int n)
{
	while (stack)
	{
		if (n == *(int *)stack->content)
			return (1);
		stack = stack->n;
	}
	return (0);
}

static int		isdouble(\
				t_dlist *stack)
{
	while (stack)
	{
		if (isdouble_n(stack->n, *(int *)stack->content))
			return (1);
		stack = stack->n;
	}
	return (0);
}

static int		oneswap(\
				t_dlist **astack, int o)
{
	t_dlist		*tmp;
	int			stroke;

	stroke = 0;
	tmp = (*astack)->n;
	if (!nosort(tmp, o, 0)\
			&& (!tmp->n\
			|| (tmp->n\
			&& *(int *)(*astack)->content) < *(int *)tmp->n->content))
	{
		ft_printf("sa\n");
		op_sx(astack, &stroke);
		if (IS(O_DEBUG, o) || IS(O_STROKE, o))
		{
			if (IS(O_COLOR, o))
				ft_printf("{pink}Stroke{eoc}: %d\n", stroke);
			else
				ft_printf("Stroke: %d\n", stroke);
		}
		return (1);
	}
	return (0);
}

static t_dlist	*get_stack(\
				int ac, char *av[], size_t *size)
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

int				pushswap(\
				int ac, char *av[], int o)
{
	t_dlist		*stack_a;
	t_dlist		*stack_b;
	size_t		size;

	size = 0;
	if (!(stack_a = get_stack(ac, av, &size)))
		return (error(EXIT_FAILURE, o));
	else if (isdouble(stack_a))
		return (error(EXIT_FAILURE, o));
	stack_b = NULL;
	if (nosort(stack_a, o, 1) && !oneswap(&stack_a, o)\
			&& !reverse(&stack_a, o) && !reverse_swap(&stack_a, o))
		sort(&stack_a, &stack_b, size, o);
	if (IS(O_DEBUG, o) || IS(O_FIN, o))
	{
		debug(stack_a, "A end", o);
		debug(stack_b, "B end", o);
	}
	ft_dlstdel(&stack_a, NULL);
	ft_dlstdel(&stack_b, NULL);
	return (EXIT_SUCCESS);
}
