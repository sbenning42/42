/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:05:02 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/02 00:00:02 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	t_list	*lst;
	t_list	*elem;
	int		i;

	lst = NULL;
	if (ac == 1)
	{
		if (!(elem = fdf(NULL)) || !(elem = ft_lstnew(&elem, sizeof(t_list *))))
			return (0);
		ft_lstadd_back(&lst, elem);
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			if (!(elem = fdf(av[i++])))
				continue ;
			if ((elem = ft_lstnew(&elem, sizeof(t_list *))))
				ft_lstadd_back(&lst, elem);
		}
	}
	if (lst)
		fdf_exec(lst, ac, av);
	return (0);
}
