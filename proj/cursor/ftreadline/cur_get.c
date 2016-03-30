/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 10:14:16 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 10:55:25 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

extern t_coo	g_coo;
extern t_coo	g_scr;

int				cur_get_scrli(void)
{
	return (g_scr.li);
}

int				cur_get_scrco(void)
{
	return (g_scr.co);
}

int				cur_get_li(void)
{
	return (g_coo.li);
}

int				cur_get_co(void)
{
	return (g_coo.co);
}
