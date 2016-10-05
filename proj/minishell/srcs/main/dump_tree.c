/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 09:37:53 by sbenning          #+#    #+#             */
/*   Updated: 2016/10/05 11:52:14 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			dump_root(t_tree *root, int i, t_dic_entry *bin)
{
	t_lxem		*list;

	if (!root)
	{
		ft_printf("\n");
		return ;
	}
	if (root->l)
		dump_root(root->l, i + 1, bin);
	if (!root->l && !root->r)
	{
		ft_printf("{green|gr}%*s%s{eoc}{red|gr}", i * 5, "", "-");
		list = root->content;
		while (list)
		{
			ft_printf("%s%c{eoc}{red}", list->value.str, list->next ? ' ' : 0);
			list = list->next;
		}
		ft_printf("{eoc}{green|gr}-|:{eoc}\n");
	}
	else
		ft_printf(SH_DUMP_LGFORMAT, i * 5, "", root->content->value.str);
	if (root->r)
		dump_root(root->r, i + 1, bin);
}

void			dump_root_log(t_tree *root, int i, t_dic_entry *bin, int fd)
{
	t_lxem		*list;

	if (!root)
	{
		ft_fprintf(fd, "\n");
		return ;
	}
	if (root->l)
		dump_root_log(root->l, i + 1, bin, fd);
	if (!root->l && !root->r)
	{
		ft_fprintf(fd, "%*s%s", i * 5, "", "-");
		list = root->content;
		while (list)
		{
			ft_fprintf(fd, "%s", list->value.str);
			if ((list = list->next))
				ft_fprintf(fd, " ");
		}
		ft_fprintf(fd, "-|:\n");
	}
	else
		ft_fprintf(fd, "%*s-%s-[\n", i * 5, "", root->content->value.str);
	if (root->r)
		dump_root_log(root->r, i + 1, bin, fd);
}
