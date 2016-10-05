/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdic_dump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 10:35:52 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/09 10:50:39 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdic.h"

void				ft_dicdumpc(t_dic_entry *dic, int asc)
{
	if (!dic)
		return ;
	if (dic->l)
		ft_dicdumpc(dic->l, 1);
	if (!asc)
		ft_printf(DIC_ROOTFORMAT, dic->key, (char *)dic->content);
	else if (asc > 0)
		ft_printf(DIC_LFORMAT, dic->key, (char *)dic->content);
	else if (asc < 0)
		ft_printf(DIC_RFORMAT, dic->key, (char *)dic->content);
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
