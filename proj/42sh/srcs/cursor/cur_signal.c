/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 09:25:27 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/09 11:12:44 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

/*
***	cur_goto(cur_get_li(), cur_get_co());
*/

void			cur_resize(int sig)
{
	cur_init_scr();
	cur_init_coo();
	(void)sig;
}
