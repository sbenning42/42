/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 08:10:06 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 12:32:03 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_history.h"

int			hist_copy(t_hist *hist, t_hist *hist_cp)
{
	hist->cursor = hist->list;
	while (hist->cursor)
	{
		hist_cp->cursor = ft_dlstnew(hist->cursor->content,\
									hist->cursor->content_size);
		if (!hist_cp->cursor)
		{
			ft_dlstdel(&hist_cp->list, NULL);
			return (-1);
		}
		ft_dlstaddn(&hist_cp->list, hist_cp->cursor);
		hist->cursor = hist->cursor->n;
	}
	if (!(hist_cp->cursor = ft_dlstnew(NULL, 0)))
	{
		ft_dlstdel(&hist_cp->list, NULL);
		return (-1);
	}
	ft_dlstaddn(&hist_cp->list, hist_cp->cursor);
	return (0);
}
