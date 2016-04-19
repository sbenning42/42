/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_scroll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 00:46:19 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 11:40:12 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

int		cur_up_scroll(void)
{
	cur_goto(cur_get_scrli(), 0);
	cur_tputs("sf");
	return (0);
}

int		cur_do_scroll(void)
{
	cur_goto(0, 0);
	cur_tputs("sr");
	return (0);
}
