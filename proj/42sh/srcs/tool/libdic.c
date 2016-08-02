/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 16:26:43 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/28 20:52:11 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdic.h"

int					dic_sort(char *k1, char *k2)
{
	if (ft_strcmp(k1, k2) >= 0)
		return (1);
	return (0);
}

void				dic_del(void *content)
{
	t_dic_test		*content_test;

	content_test = (t_dic_test *)content;
	free(content_test->user);
	free(content_test->group);
	free(content_test->shell);
	free(content_test->home);
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

void				ft_dicdumpc(t_dic_entry *dic, int asc)
{
	if (!dic)
		return ;
	if (dic->l)
		ft_dicdumpc(dic->l, 1);
	if (!asc)
		ft_printf("%{{cyan|gr}%s{eoc}}: `{green|gr}%s{eoc}`\n", dic->key, (char *)dic->content);
	else if (asc > 0)
		ft_printf("%{{blue|gr}%s{eoc}}: `{green|gr}%s{eoc}`\n", dic->key, (char *)dic->content);
	else if (asc < 0)
		ft_printf("%{{red|gr}%s{eoc}}: `{green|gr}%s{eoc}`\n", dic->key, (char *)dic->content);
	if (dic->r)
		ft_dicdumpc(dic->r, -1);
}

void				ft_dicdump(t_dic_entry *dic, int fd)
{
	if (!dic)
		return ;
	if (dic->l)
		ft_dicdump(dic->l, fd);
	ft_fprintf(fd, "%{%s} : `%s`\n", dic->key, (char *)dic->content);
	if (dic->r)
		ft_dicdump(dic->r, fd);
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
/*
int	main(void)
{
	t_dic_entry	*testdic;
	t_dic_entry	*testentry;
	t_dic_test	user;
	t_dic_test	*cp;

	testdic = NULL;
	
	user.user = ft_strdup("root");
	user.group = ft_strdup("root");
	user.shell = ft_strdup("sh");
	user.home = ft_strdup("/root");
	
	testentry = ft_dicnew("root", &user, sizeof(t_dic_test));
	ft_dicadd(&testdic, testentry, dic_sort);

	user.user = ft_strdup("m4s");
	user.group = ft_strdup("m4s");
	user.shell = ft_strdup("sh");
	user.home = ft_strdup("/home/m4s");
	
	testentry = ft_dicnew("m4s", &user, sizeof(t_dic_test));
	ft_dicadd(&testdic, testentry, dic_sort);

	cp = (t_dic_test *)ft_dicget(testdic, "m4s");
	ft_printf("m4s: %s\n", cp->home);
	
	cp = (t_dic_test *)ft_dicget(testdic, "root");
	ft_printf("root: %s\n", cp->home);
	
	ft_dicdel(&testdic, dic_del);
	return ;
}
*/











