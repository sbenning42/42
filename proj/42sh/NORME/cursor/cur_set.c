/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 09:35:09 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 10:55:30 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

extern t_coo	g_coo;
extern t_coo	g_scr;

int				cur_set_scrli(int li)
{
	g_scr.li = li;
	return (0);
}

int				cur_set_scrco(int co)
{
	g_scr.co = co;
	return (0);
}

int				cur_set_li(int li)
{
	g_coo.li = li;
	return (0);
}

int				cur_set_co(int co)
{
	g_coo.co = co;
	return (0);
}
