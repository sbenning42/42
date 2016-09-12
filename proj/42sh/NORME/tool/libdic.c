/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 16:26:43 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/09 11:08:02 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdic.h"

int					dic_sort(char *k1, char *k2)
{
	if (ft_strcmp(k1, k2) >= 0)
		return (1);
	return (0);
}

t_dic_entry			*ft_dicnew(char *key, void *content, size_t size)
{
	t_dic_entry		*entry;

	entry = (t_dic_entry *)ft_memalloc(sizeof(t_dic_entry));
	if (!entry)
		return (NULL);
	entry->key = ft_strdup(key);
	if (!entry->key)
	{
		free(entry);
		return (NULL);
	}
	entry->content = ft_memalloc(size);
	if (!entry->content)
	{
		free(entry->key);
		free(entry);
		return (NULL);
	}
	ft_memcpy(entry->content, content, size);
	return (entry);
}

void				ft_dicadd(t_dic_entry **dic, t_dic_entry *entry, \
					t_dic_sort sort)
{
	if (!dic || !(*dic))
	{
		(*dic) = entry;
		return ;
	}
	else if (sort((*dic)->key, entry->key) > 0)
	{
		if ((*dic)->l)
			ft_dicadd(&((*dic)->l), entry, sort);
		else
			(*dic)->l = entry;
	}
	else
	{
		if ((*dic)->r)
			ft_dicadd(&((*dic)->r), entry, sort);
		else
			(*dic)->r = entry;
	}
}

void				ft_dicdel(t_dic_entry **dic, t_dic_del del)
{
	if ((*dic)->l)
		ft_dicdel(&((*dic)->l), del);
	if ((*dic)->r)
		ft_dicdel(&((*dic)->r), del);
	if (del)
		del((*dic)->content);
	free((*dic)->content);
	free((*dic)->key);
	free(*dic);
	*dic = NULL;
}

void				*ft_dicget(t_dic_entry *dic, char *key)
{
	int				ret;

	if (dic)
	{
		ret = ft_strcmp(dic->key, key);
		if (ret > 0 && dic->l)
			return (ft_dicget(dic->l, key));
		else if (ret < 0 && dic->r)
			return (ft_dicget(dic->r, key));
		else if (!ret)
			return (dic->content);
		else
			return (NULL);
	}
	return (NULL);
}
