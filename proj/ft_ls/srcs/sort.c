/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/22 18:28:40 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/22 18:38:57 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_ls_del_lav(void *content, size_t size)
{
	free(content);
}

void		ft_ls_sort_lav(int *opt, t_list *lst)
{
	if (opt[R_FLAG])
		ft_ls_reverse_sort(lst);
	else if (opt[T_FLAG])
		ft_ls_time_sort(lst);
	else
		ft_ls_straigt_sort(lst);
}

t_list		*ft_ls_sort_av(int *opt, int ac, char **av)
{
	t_list	*lst;
	t_list	*elem;
	int		i;

	i = 0;
	lst = NULL;
	while (++i < ac)
	{
		if (*av[i] == '-' || !*av[i])
			continue ;
		elem = ft_lstnew((void *)av[i], sizeof(char) * (ft_strlen(av[i] + 1)));
		if (!elem)
		{
			ft_lstdel(&lst, ft_ls_del_lav);
			ft_printf("ft_ls: Memory allocation failed\n");
			return (NULL);
		}
		ft_lstadd(&lst, elem);
	}
	ft_ls_sort_lav(opt, lst);
}
