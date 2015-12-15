/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:28:19 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/15 17:06:01 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node			*ls_dir_sort(int o, DIR *dir, t_ls_func f)
{
	
}

void			ft_ls(char *av, int o, t_node **ar, t_ls_func f)
{
	t_ls_entry	*e;

	if ((o & O_RECU) == 0)
		tree_del(ar, NULL);
	else
	{
		if ((*ar)->l)
			ft_ls(av, o, &(*ar)->l, f);
		e = (t_ls_entry *)(*ar)->content;
		if (e->type == T_DIR)
		{
			ft_printf("%s:\n", e->key);
			ls_dir(av, o, e, f);
		}
		if ((*ar)->r)
			ft_ls(av, o, &(*ar)->r, f);
		tree_del(ar, NULL);
	}
}

void			ls_dir(char *av, int o, t_entry *e, t_ls_func f)
{
	t_node		*root;
	DIR			*dir;

	errno = 0;
	if (!(dir = opendir(e->key)) || errno)
	{
		ls_err(av, e->key, errno, "Cant open directory");
		return ;
	}
	root = ls_dir_sort(o, dir, f);
	tree_doinf(root, f.p);
	if (root)
		ft_ls(av, o, &root, f);
}

void			ft_ls_avp(char *av, int o, t_node **ar, t_ls_func f)
{
	t_ls_entry	*e;

	if ((*ar)->l)
		ft_ls(o, &(*ar)->l, f);
	e = (t_ls_entry *)(*ar)->content;
	if (e->type == T_NODIR)
		f.p(*ar);
	else
	{
		if ((o & O_PRIVATE_MULTI) == O_PRIVATE_MULTI)
			ft_printf("%s:\n", e->key);
		/*if ((o & O_RECU) == O_RECU)
			o |= O_PRIVATE_MULTI; //In order to get the e->key:\n on the recursive call
	*/	ls_dir(o, e, f);
	}
	if ((*ar)->r)
		ft_ls(av, o, &(*ar)->r, f);
	tree_del(ar, NULL);
}
