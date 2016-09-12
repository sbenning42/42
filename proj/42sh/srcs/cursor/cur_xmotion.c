/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_xmotion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:09:35 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/09 11:11:50 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

int		cur_xup(int x)
{
	cur_tparm("UP", x);
	cur_maj_li(-x);
	return (0);
}

int		cur_xdo(int x)
{
	cur_tparm("DO", x);
	cur_maj_li(x);
	return (0);
}

int		cur_xle(int x)
{
	cur_tparm("LE", x);
	cur_maj_co(-x);
	return (0);
}

int		cur_xri(int x)
{
	cur_tparm("RI", x);
	cur_maj_co(x);
	return (0);
}
