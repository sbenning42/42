/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_dump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 19:03:36 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/28 20:47:09 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_history.h"

void		hist_dump(t_hist hist, int fd)
{
	t_dlist	*tmp;

	tmp = hist.list;
	while (tmp)
	{
		ft_fprintf(fd, "%s\n", (char *)tmp->content);
		tmp = tmp->n;
	}
}
