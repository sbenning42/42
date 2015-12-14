/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:16:01 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/14 17:58:42 by sbenning         ###   ########.fr       */
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

t_node		*tree_newnode(void *content, size_t size)
{
	t_node	*no;

	if (!content || !key)
		return (NULL);
	no = (t_node *)ft_memalloc(sizeof(t_node));
	if (!no)
		return (NULL);
	no->content = ft_memdup(content, size);
	if (!no->content)
	{
		ft_membzdel((void **)&no);
		return (NULL);
	}
	no->content_size = 0;
	return (no);
}

void		tree_add(t_node **ar, t_node *no, int (*s)(t_node *, t_node *))
{
	if (!*ar)
	{
		*ar = no;
		return ;
	}
	if (s(*ar, no))
	{
		if ((*ar)->r)
			tree_add(&(*ar)->r, no, s);
		(*ar)->r = no;
		no->p = (*ar);
	}
	else
	{
		if ((*ar)->l)
			tree_add(&(*ar)->l, no, s);
		(*ar)->l = no;
		no->p = (*ar);
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
	ft_membzdel((void **)&(*ar)->content);
	ft_membzdel((void **)ar);
}
