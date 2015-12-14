/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:18:14 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/14 17:58:41 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_node	*verbose_sort(int ac, char **av, int (*s)(void *, void *))
{
	t_node		*root;
	t_node		*no;
	int			i;

	root = NULL;
	i = 0;
	while (++i < ac)
	{
		no = tree_newnode(av[i], av[i], sizeof(char) * (ft_strlen(av[i] + 1))); // change second av[i] for the lstat struct
		if (!no)
		{
			tree_del(&root, NULL);
			return (NULL);
		}
		tree_add(&root, no);
	}
}

void		ft_ls_wopt(int ac, char **av, int o, int (*s)(void *, void *))
{
	t_node	*root;

	root = verbose_sort(ac, av, s);
	if (!root)
		ft_printf("%s: {red}%s{eoc}: %s\n", av[0], "Error", "Memory allocation failed");
	//tree_do_inf(root, ls_tree_print);
	(void)o;
}
