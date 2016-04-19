/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 09:25:27 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 12:57:55 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

void			cur_resize(int sig)
{
	cur_init_scr();
	cur_init_coo();
//	cur_goto(cur_get_li(), cur_get_co());
	(void)sig;
}
