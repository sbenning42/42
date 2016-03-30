/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_maj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 10:55:42 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 14:42:02 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

extern t_coo	g_coo;
extern t_coo	g_scr;

int				cur_maj_li(int x)
{
	g_coo.li += x;
	g_coo.li = (g_coo.li > g_scr.li ? g_scr.li : g_coo.li);
	g_coo.li = (g_coo.li < 0 ? 0 : g_coo.li);
	return (0);
}

int				cur_maj_co(int x)
{
	g_coo.co += x;
	g_coo.co = (g_coo.co > g_scr.co ? g_scr.co : g_coo.co);
	g_coo.co = (g_coo.co < 0 ? 0 : g_coo.co);
	return (0);
}
