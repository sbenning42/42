/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_save.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 11:41:38 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/22 13:50:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_history.h"

int		hist_save(t_hist *hist)
{
	int	fd;

	if (!(fd = open(".42sh_history", O_WRONLY | O_CREAT, 0755)))
		return (-1);
	hist->cursor = hist->list;
	while (hist->cursor)
	{
		ft_fprintf(fd, "%s\n", (char *)hist->cursor->content);
		hist->cursor = hist->cursor->n;
	}
	ft_dlstdel(&hist->list, NULL);
	close(fd);
	return (0);
}
