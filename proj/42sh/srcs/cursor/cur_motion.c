/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_motion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:09:35 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/09 11:10:54 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

int		cur_up(void)
{
	cur_tputs("up");
	cur_maj_li(-1);
	return (0);
}

int		cur_do(void)
{
	cur_tputs("do");
	cur_maj_li(1);
	return (0);
}

int		cur_le(void)
{
	cur_tputs("le");
	cur_maj_co(-1);
	return (0);
}

int		cur_ri(void)
{
	cur_tputs("nd");
	cur_maj_co(1);
	return (0);
}
