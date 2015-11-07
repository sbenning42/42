/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 17:18:30 by sbenning          #+#    #+#             */
/*   Updated: 2015/09/21 17:35:17 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.h"

void		cv1_tokenize(t_ar *ar, char *s)
{
}

void		computerv1(char *s)
{
	t_ar	ar;

	ft_arnew(&ar);
	cv1_tokenize(&ar, s);
	ft_ardel(&ar);
}

int			main(int ac, char **av)
{
	size_t	i;

	i = 1;
	while (i < ac)
		computerv1(av[i++]);
	if (i == 1)
		ft_putendl("computerv1: No enough argument!");
	return (0);
}
