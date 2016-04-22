/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 11:31:56 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/22 08:40:32 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HISTORY_H
# define FT_HISTORY_H

# include "libft.h"
# include "get_next_line.h"

typedef struct		s_hist
{
	t_dlist			*list;
	t_dlist			*cursor;
}					t_hist;

int					hist_load(t_hist *hist);
int					hist_save(t_hist *hist);
int					hist_copy(t_hist *hist, t_hist *hist_cp);

#endif
