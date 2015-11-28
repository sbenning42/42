/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:26:26 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/23 13:13:27 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_ls_timecmp(char *n1, char *n2, int *opt)
{
	struct stat	info1;
	struct stat	info2;

	if (((stat(n1, &info1) == -1) || (stat(n2, &info2) == -1)) && errno != ENOENT)
		return (-1);
	ft_pr
	if (info1.st_mtimespec.tv_sec > info2.st_mtimespec.tv_sec)
		return (0);
	else if (info1.st_mtimespec.tv_sec < info2.st_mtimespec.tv_sec)
		return (1);
	if ((ft_strcmp(n1, n2) > 0) && !opt[R_FLAG])
	{
		ft_printf("nosort\n");
		return (0);
	}
		ft_printf("sort\n");
	return (1);
}

void		ft_ls_reverse_sort(t_list *lst)
{
	t_list	*cp;
	int		flag;
	void	*swap;

	flag = 1;
	while (flag)
	{
		cp = lst;
		flag = 0;
		while (lst && lst->next)
		{
			if (ft_strcmp((char *)lst->content, (char *)lst->next->content) < 0)
			{
				flag = 1;
				swap = lst->content;
				lst->content = lst->next->content;
				lst->next->content = swap;
			}
			lst = lst->next;
		}
		lst = cp;
	}
}

void		ft_ls_time_sort(t_list *lst, int *opt)
{
	t_list	*cp;
	int		flag;
	void	*swap;
	int		ret;

	flag = 1;
	while (flag)
	{
		cp = lst;
		flag = 0;
		while (lst && lst->next)
		{
			if ((ret = ft_ls_timecmp((char *)lst->content, (char *)lst->next->content, opt)) < 0)
			{
				ft_lstdel(&lst, ft_ls_del_avl);
				ft_printf("ft_ls: Error on stat status for [%s] or [%s]\n", (char *)lst->content, (char *)lst->next->content);
				exit(1);
			}
			else if (ret)
			{
				flag = 1;
				swap = lst->content;
				lst->content = lst->next->content;
				lst->next->content = swap;
			}
			lst = lst->next;
		}
		lst = cp;
	}
}

void		ft_ls_straigt_sort(t_list *lst)
{
	t_list	*cp;
	int		flag;
	void	*swap;

	flag = 1;
	while (flag)
	{
		cp = lst;
		flag = 0;
		while (lst && lst->next)
		{
			if (ft_strcmp((char *)lst->content, (char *)lst->next->content) > 0)
			{
				flag = 1;
				swap = lst->content;
				lst->content = lst->next->content;
				lst->next->content = swap;
			}
			lst = lst->next;
		}
		lst = cp;
	}
}
