/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:16:01 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/16 09:52:16 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tree.h"

static void	*ft_memdup(void *p, size_t size)
{
	t_uchar	*cp;
	size_t	i;

	cp = (t_uchar *)ft_memalloc(size);
	if (!cp)
		return (NULL);
	i = 0;
	while (i < size)
	{
		cp[i] = ((t_uchar *)p)[i];
		i++;
	}
	return ((void *)cp);
}

void		tree_doinf(t_node *r, void (*d)(void *, size_t))
{
	if (r && r->l)
		tree_doinf(r->l, d);
	if (r)
		d(r->content, r->content_size);
	if (r && r->r)
		tree_doinf(r->r, d);
}

t_node		*tree_newnode(void *content, size_t size)
{
	t_node	*no;

	if (!content)
		return (NULL);
	no = (t_node *)ft_memalloc(sizeof(t_node));
	if (!no)
		return (NULL);
	no->content = ft_memdup(content, size);
	if (!no->content)
	{
		ft_memdel((void **)&no);
		return (NULL);
	}
	no->content_size = size;
	return (no);
}

void		tree_add(t_node **ar, t_node *no, int (*s)(void *, void *))
{
	if (!*ar)
	{
		*ar = no;
		return ;
	}
	if (s((*ar)->content, no->content))
	{
		if ((*ar)->r)
		{
			tree_add(&(*ar)->r, no, s);
			return ;
		}
		(*ar)->r = no;
		no->f = (*ar);
	}
	else
	{
		if ((*ar)->l)
		{
			tree_add(&(*ar)->l, no, s);
			return ;
		}
		(*ar)->l = no;
		no->f = (*ar);
	}
}

void		tree_del(t_node **ar, void (*d)(void *, size_t))
{
	if (*ar && (*ar)->l)
		tree_del(&(*ar)->l, d);
	if (*ar && (*ar)->r)
		tree_del(&(*ar)->r, d);
	if (d)
		d((*ar)->content, (*ar)->content_size);
	ft_memdel((void **)&(*ar)->content);
	ft_memdel((void **)ar);
}
