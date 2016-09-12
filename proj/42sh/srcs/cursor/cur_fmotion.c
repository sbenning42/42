/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_fmotion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:09:35 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/09 11:12:00 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

int		cur_fup(void)
{
	cur_goto(0, cur_get_co());
	return (0);
}

int		cur_fdo(void)
{
	cur_goto(cur_get_scrli(), cur_get_co());
	return (0);
}

int		cur_fle(void)
{
	cur_goto(cur_get_li(), 0);
	return (0);
}

int		cur_fri(void)
{
	cur_goto(cur_get_li(), cur_get_scrco());
	return (0);
}
