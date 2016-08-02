/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 18:23:00 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/17 12:59:24 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_dic			*ft_dicnew(\
				char *id, void *content, size_t content_size)
{
	t_dic		*entry;

	if (!(entry = ft_memalloc(sizeof(t_dic))))
		return (NULL);
	if (!(entry->id = ft_strdup(id)))
	{
		ft_memdel((void **)&entry);
		return (NULL);
	}
	if (content_size)
	{
		if (!(entry->content = ft_memalloc(content_size)))
		{
			ft_memdel((void **)&entry->id);
			ft_memdel((void **)&entry);
			return (NULL);
		}
		ft_memcpy(entry->content, content, content_size);
	}
	return (entry);
}

int				alpha_sort(\
				char *id1, char *id2)
{
	return ((ft_strcmp(id1, id2) >= 0 ? 1 : 0));
}

void			ft_dicadd(\
				t_dic **adic, t_dic *e, int (*s)(char *, char *))
{
	if (!(*adic))
		*adic = e;
	else if (s((*adic)->id, e->id))
	{
		if ((*adic)->l)
		{
			ft_dicadd(&(*adic)->l, e, s);
			return ;
		}
		(*adic)->l = e;
		e->p = (*adic);
	}
	else
	{
		if ((*adic)->r)
		{
			ft_dicadd(&(*adic)->r, e, s);
			return ;
		}
		(*adic)->r = e;
		e->p = (*adic);
	}
}

void			ft_dicdel(\
				t_dic **adic, void (*del)(void *, size_t))
{
	if ((*adic) && (*adic)->l)
		ft_dicdel(&(*adic)->l, del);
	if ((*adic) && (*adic)->r)
		ft_dicdel(&(*adic)->r, del);
	if (*adic && del)
		del((*adic)->content, (*adic)->content_size);
	if (*adic)
	{
		ft_memdel((void **)&(*adic)->id);
		ft_memdel((void **)&(*adic)->content);
		ft_memdel((void **)adic);
	}
}
