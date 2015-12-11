/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:18:14 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/09 22:41:23 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_ls_wopt(int ac, char **av, int o, int (*s)(void *, void *))
{
	t_node	*root;
	int		i;

	i = 1;
	while (i < ac && av[i][0] == '-')
		i++;
	root = NULL;
	while (i < ac)
	{
		ls_add_entry(av[0], &root, av[i], s);
		i++;
	}
	if (root && (root->l || root->r))
		ft_ls(av[0], o, &root, s);
}
